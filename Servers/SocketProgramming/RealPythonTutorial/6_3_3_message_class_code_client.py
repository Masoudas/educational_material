"""
Because the client initiates a connection to the server and sends a request first, the state variable _request_queued is checked. If a request hasn’t been queued, it calls .queue_request(). The queue_request() method creates the request and writes it to the send buffer. It also sets the state variable _request_queued so that it’s only called once.

Just like for the server, ._write() calls socket.send() if there’s data in the send buffer.

The notable difference in the client’s version of .write() is the last check to see if the request has been queued. This will be explained more in the section Client Main Script, but the reason for this is to tell selector.select() to stop monitoring the socket for write events. If the request has been queued and the send buffer is empty, then you’re done writing and you’re only interested in read events. There’s no reason to be notified that the socket is writable.

To wrap up this section, consider this thought: the main purpose of this section was to explain that selector.select() is calling into the Message class via the method .process_events() and to describe how state is managed.

This is important because .process_events() will be called many times over the life of the connection. Therefore, make sure that any methods that should only be called once are either checking a state variable themselves, or the state variable set by the method is checked by the caller.

The dictionaries used to create the request, depending on what was passed on the command line, are in the client’s main script, app-client.py. The request dictionary is passed as an argument to the class when a Message object is created.

The request message is created and appended to the send buffer, which is then seen by and sent via ._write(). The state variable self._request_queued is set so that .queue_request() isn’t called again.

After the request has been sent, the client waits for a response from the server.

The methods for reading and processing a message in the client are the same as for the server. As response data is read from the socket, the process header methods are called: .process_protoheader() and .process_jsonheader().

The difference is in the naming of the final process methods and the fact that they’re processing a response, not creating one: .process_response(), ._process_response_json_content(), and ._process_response_binary_content().

Last, but certainly not least, is the final call for .process_response():
"""
import sys
import socket
import selectors
import types

class Message:
    def __init__(self, selector, sock, addr):
        pass

    def process_events(self, mask):
        if mask & selectors.EVENT_READ:
            self.read()
        if mask & selectors.EVENT_WRITE:
            self.write()

    def read(self):
        self._read()

        if self._jsonheader_len is None:
            self.process_protoheader()

        if self._jsonheader_len is not None:
            if self.jsonheader is None:
                self.process_jsonheader()

        if self.jsonheader:
            if self.request is None:
                self.process_request()    
    
    def _read(self):
        try:
            # Should be ready to read
            data = self.sock.recv(4096)
        except BlockingIOError:
            # Resource temporarily unavailable (errno EWOULDBLOCK)
            pass
        else:
            if data:
                self._recv_buffer += data
            else:
                raise RuntimeError("Peer closed.")
            
    def write(self):
        if not self._request_queued:
            self.queue_request()

        self._write()

        if self._request_queued:
            if not self._send_buffer:
                # Set selector to listen for read events, we're done writing.
                self._set_selector_events_mask("r")

    def queue_request(self):
        content = self.request["content"]
        content_type = self.request["type"]
        content_encoding = self.request["encoding"]
        if content_type == "text/json":
            req = {
                "content_bytes": self._json_encode(content, content_encoding),
                "content_type": content_type,
                "content_encoding": content_encoding,
            }
        else:
            req = {
                "content_bytes": content,
                "content_type": content_type,
                "content_encoding": content_encoding,
            }
        message = self._create_message(**req)
        self._send_buffer += message
        self._request_queued = True


sel = selectors.DefaultSelector()
messages = [b"Message 1 from client.", b"Message 2 from client."]

def start_connection(host, port, request):
    addr = (host, port)
    print(f"Starting connection to {addr}")
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setblocking(False)
    sock.connect_ex(addr)
    events = selectors.EVENT_READ | selectors.EVENT_WRITE
    message = Message(sel, sock, addr, request)
    sel.register(sock, events, data=message)

def service_connection(key, mask):
    sock = key.fileobj
    data = key.data

    if mask & selectors.EVENT_READ:
        recv_data = sock.recv(1024)  # Should be ready to read
        if recv_data:
            print(f"Received {recv_data!r} from connection {data.connid}")
            data.recv_total += len(recv_data)

        if not recv_data or data.recv_total == data.msg_total:
            print(f"Closing connection {data.connid}")
            sel.unregister(sock)
            sock.close()

    if mask & selectors.EVENT_WRITE:
        if not data.outb and data.messages:
            data.outb = data.messages.pop(0)
        
        if data.outb:
            print(f"Sending {data.outb!r} to connection {data.connid}")
            sent = sock.send(data.outb)  # Should be ready to write
            data.outb = data.outb[sent:]

host, port, num_conns = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]) 

print(f"Connecting on {(host, port)}")
start_connection(host, port, num_conns)

try:
    while True:
        events = sel.select(timeout=1)
        for key, mask in events:
            message = key.data
            try:
                message.process_events(mask)
            except Exception:
                print(
                    f"Main: Error: Exception for {message.addr}:\n"
                )
                message.close()
        # Check for a socket being monitored to continue.
        if not sel.get_map():
            break
except KeyboardInterrupt:
    print("Caught keyboard interrupt, exiting")
finally:
    sel.close()
