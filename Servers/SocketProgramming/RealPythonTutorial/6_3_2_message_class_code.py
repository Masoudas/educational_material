"""
Finally, the payoff! In this section, you’ll study the Message class and see how it’s used with .select() when read and write events happen on the socket.

To keep things simple and still demonstrate how things would work in a real application, this example uses an application protocol that implements a basic search feature. The client sends a search request and the server does a lookup for a match. If the request sent by the client isn’t recognized as a search, the server assumes it’s a binary request and returns a binary response.

The application is not that far off from the multiconn client and server example. The event loop code stays the same in app-client.py and app-server.py. What you’re going to do is move the message code into a class named Message and add methods to support reading, writing, and processing of the headers and content. This is a great example for using a class.

As you learned before and you’ll see below, working with sockets involves keeping state. By using a class, you keep all of the state, data, and code bundled together in an organized unit. An instance of the class is created for each socket in the client and server when a connection is started or accepted.

The class is mostly the same for both the client and the server for the wrapper and utility methods. They start with an underscore, like Message._json_encode(). These methods simplify working with the class. They help other methods by allowing them to stay shorter and support the DRY principle.

The server’s Message class works in essentially the same way as the client’s and vice-versa. The difference is that the client initiates the connection and sends a request message, followed by processing the server’s response message. Conversely, the server waits for a connection, processes the client’s request message, and then sends a response message.

process_events() is simple. It can only do two things: call .read() and .write().

This is where managing state comes in. If another method depended on state variables having a certain value, then they would only be called from .read() and .write(). This keeps the logic as simple as possible as events come in on the socket for processing.

You might be tempted to use a mix of some methods that check the current state variables and, depending on their value, call other methods to process data outside .read() or .write(). In the end, this would likely prove too complex to manage and keep up with.

You should definitely modify the class to suit your own needs so that it works best for you, but you’ll probably have the best results if you keep the state checks and the calls to methods that depend on that state to the .read() and .write() methods if possible.

Now look at .read(). This is the server’s version, but the client’s is the same. It just uses a different method name, .process_response() instead of .process_request().

The ._read() method is called first. It calls socket.recv() to read data from the socket and store it in a receive buffer.

Remember that when socket.recv() is called, all of the data that makes up a complete message may not have arrived yet. socket.recv() may need to be called again. This is why there are state checks for each part of the message before the appropriate method to process it is called.

Before a method processes its part of the message, it first checks to make sure enough bytes have been read into the receive buffer. If they have, it processes its respective bytes, removes them from the buffer and writes its output to a variable that’s used by the next processing stage. Because there are three components to a message, there are three state checks and process method calls:

        Message Component	            Method	                        Output
        Fixed-length header	        process_protoheader()	    self._jsonheader_len
        JSON header	                process_jsonheader()	    self.jsonheader
        Content	                    process_request()	        self.request

The .write() method checks first for a request. If one exists and a response hasn’t been created, .create_response() is called. The .create_response() method sets the state variable response_created and writes the response to the send buffer. The ._write() method calls socket.send() if there’s data in the send buffer.

Remember that when socket.send() is called, all of the data in the send buffer may not have been queued for transmission. The network buffers for the socket may be full, and socket.send() may need to be called again. This is why there are state checks. The .create_response() method should only be called once, but it’s expected that ._write() will need to be called multiple times. The client version of .write() is similar.

The fixed-length header is a 2-byte integer in network, or big-endian, byte order. It contains the length of the JSON header. You’ll use struct.unpack() to read the value, decode it, and store it in self._jsonheader_len. After processing the piece of the message it’s responsible for, .process_protoheader() removes it from the receive buffer.

The method self._json_decode() is called to decode and deserialize the JSON header into a dictionary. Because the JSON header is defined as Unicode with a UTF-8 encoding, utf-8 is hardcoded in the call. The result is saved to self.jsonheader. After processing the piece of the message that it’s responsible for, process_jsonheader() removes it from the receive buffer.

Next is the actual content, or payload, of the message. It’s described by the JSON header in self.jsonheader. When content-length bytes are available in the receive buffer, the request can be processed.

After saving the message content to the data variable, .process_request() removes it from the receive buffer. Then, if the content type is JSON, .process_request() decodes and deserializes it. If it’s not, this example application assumes that it’s a binary request and simply prints the content type.

The last thing .process_request() does is modify the selector to monitor write events only. In the server’s main script, app-server.py, the socket is initially set to monitor read events only. Now that the request has been fully processed, you’re no longer interested in reading.

A response can now be created and written to the socket. When the socket is writable, .create_response() is called from .write().

A response is created by calling other methods, depending on the content type. In this example application, a simple dictionary lookup is done for JSON requests when action == 'search'. For your own applications, you can define other methods that get called here.

After creating the response message, the state variable self.response_created is set so that .write() doesn’t call .create_response() again. Finally, the response is appended to the send buffer. This is seen by and sent via ._write().

One tricky bit to figure out is how to close the connection after the response is written. You can put the call to .close() in the method ._write().
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
    
    def write(self):
        if self.request:
            if not self.response_created:
                self.create_response()

        self._write()
    
    def process_protoheader(self):
        hdrlen = 2
        if len(self._recv_buffer) >= hdrlen:
            self._jsonheader_len = struct.unpack(
                ">H", self._recv_buffer[:hdrlen]
            )[0]
            self._recv_buffer = self._recv_buffer[hdrlen:]
    
    def process_jsonheader(self):
        hdrlen = self._jsonheader_len
        if len(self._recv_buffer) >= hdrlen:
            self.jsonheader = self._json_decode(
                self._recv_buffer[:hdrlen], "utf-8"
            )
            self._recv_buffer = self._recv_buffer[hdrlen:]
            for reqhdr in (
                "byteorder",
                "content-length",
                "content-type",
                "content-encoding",
            ):
                if reqhdr not in self.jsonheader:
                    raise ValueError(f"Missing required header '{reqhdr}'.")
    
    def create_response(self):
        if self.jsonheader["content-type"] == "text/json":
            response = self._create_response_json_content()
        else:
            # Binary or unknown content-type
            response = self._create_response_binary_content()
        message = self._create_message(**response)
        self.response_created = True
        self._send_buffer += message

    def process_request(self):
        content_len = self.jsonheader["content-length"]
        if not len(self._recv_buffer) >= content_len:
            return
        data = self._recv_buffer[:content_len]
        self._recv_buffer = self._recv_buffer[content_len:]
        if self.jsonheader["content-type"] == "text/json":
            encoding = self.jsonheader["content-encoding"]
            self.request = self._json_decode(data, encoding)
            print(f"Received request {self.request!r} from {self.addr}")
        else:
            # Binary or unknown content-type
            self.request = data
            print(
                f"Received {self.jsonheader['content-type']} "
                f"request from {self.addr}"
            )
        # Set selector to listen for write events, we're done reading.
        self._set_selector_events_mask("w")

    def _write(self):
        if self._send_buffer:
            print(f"Sending {self._send_buffer!r} to {self.addr}")
            try:
                # Should be ready to write
                sent = self.sock.send(self._send_buffer)
            except BlockingIOError:
                # Resource temporarily unavailable (errno EWOULDBLOCK)
                pass
            else:
                self._send_buffer = self._send_buffer[sent:]
                # Close when the buffer is drained. The response has been sent.
                if sent and not self._send_buffer:
                    self.close()


def accept_wrapper(sock: socket.socket):
    conn, addr = sock.accept()  # Should be ready to read
    print(f"Accepted connection from {addr}")
    conn.setblocking(False)
    message = Message(sel, conn, addr)
    sel.register(conn, selectors.EVENT_READ, data=message)

def service_connection(
        key: selectors.SelectorKey, mask: int):
    sock: socket.socket = key.fileobj
    data: types.SimpleNamespace = key.data

    if mask & selectors.EVENT_READ:
        recv_data = sock.recv(1024)  # Should be ready to read
        if recv_data:
            data.outb += recv_data
        
        else:
            print(f"Closing connection to {data.addr}")
            sel.unregister(sock)
            sock.close()

    elif mask & selectors.EVENT_WRITE:
        if data.outb:
            print(f"Echoing {data.outb!r} to {data.addr}")
            sent = sock.send(data.outb)  # Should be ready to write
            data.outb = data.outb[sent:]

sel = selectors.DefaultSelector()

host, port = sys.argv[1], int(sys.argv[2])

lsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
lsock.bind((host, port))
lsock.listen()
print(f"Listening on {(host, port)}")

lsock.setblocking(False)

sel.register(lsock, selectors.EVENT_READ, data=None)

try:
    while True:
        events = sel.select(timeout=None)
        for key, mask in events:
            if key.data is None:
                accept_wrapper(key.fileobj)
            else:
                message = key.data
                try:
                    message.process_events(mask)
                except Exception:
                    print(
                        f"Main: Error: Exception for {message.addr}:\n")
                    message.close()
except KeyboardInterrupt:
    print("Caught keyboard interrupt, exiting")
finally:
    sel.close()