"""
Me: The general concept of the following code is as follows. Selector is just like an event loop. As soon as an event of the given type happens, it will deal with the event. Notice that the events are defined by the selector. What makes the selector know that an event has occured on the socket? Select use IO of the underlying object, which is the socket here! Now, we need to register two different sets of event. The first one is when a client tries to access the socket (the accept method). In this case, we call the accept method, and then register the events of read and write. Now, when someone tries to access the connection object, we check which event is raised, and then either read or write to the connection object. Then again, I don't understand how all of this works. Note that what differentiates between these two events in our code is whether there's data associated with the event or not. The data passed is something called SimpleNamespace, which is more or less like a named tuple.

The biggest difference between this server and the echo server is the call to lsock.setblocking(False) to configure the socket in non-blocking mode. Calls made to this socket will no longer block. When it’s used with sel.select(), as you’ll see below, you can wait for events on one or more sockets and then read and write data when it’s ready.

sel.register() registers the socket to be monitored with sel.select() for the events that you’re interested in. For the listening socket, you want read events: selectors.EVENT_READ.

To store whatever arbitrary data you’d like along with the socket, you’ll use data. It’s returned when .select() returns. You’ll use data to keep track of what’s been sent and received on the socket.

sel.select(timeout=None) blocks until there are sockets ready for I/O. It returns a list of tuples, one for each socket. Each tuple contains a key and a mask. The key is a SelectorKey namedtuple that contains a fileobj attribute. key.fileobj is the socket object, and mask is an event mask of the operations that are ready. (Me: In human terms, it returns the object that was waited on, together with the event data we may have sent with it.)

If key.data is None, then you know it’s from the listening socket and you need to accept the connection. You’ll call your own accept_wrapper() function to get the new socket object and register it with the selector. If key.data is not None, then you know it’s a client socket that’s already been accepted, and you need to service it. service_connection() is then called with key and mask as arguments, and that’s everything you need to operate on the socket. (Me: We set everything to false blocking, because this is one purpose of this code.) 

Next, you create an object to hold the data that you want included along with the socket using a SimpleNamespace. Because you want to know when the client connection is ready for reading and writing, both of those events are set with the bitwise OR operator: The events mask, socket, and data objects are then passed to sel.register().

Next, consider the service_connection wrapper. This is the heart of the simple multi-connection server. key is the namedtuple returned from .select() that contains the socket object (fileobj) and data object. mask contains the events that are ready. If the socket is ready for reading, then mask & selectors.EVENT_READ will evaluate to True, so sock.recv() is called. Any data that’s read is appended to data.outb so that it can be sent later. Note the else: block to check if no data is received. If no data is received, this means that the client has closed their socket, so the server should too. But don’t forget to call sel.unregister() before closing, so it’s no longer monitored by .select().

When the socket is ready for writing, which should always be the case for a healthy socket, any received data stored in data.outb is echoed to the client using sock.send(). The bytes sent are then removed from the send buffer. The .send() method returns the number of bytes sent. This number can then be used with slice notation on the .outb buffer to discard the bytes sent.


"""
import sys
import socket
import selectors
import types

def accept_wrapper(sock: socket.socket):
    conn, addr = sock.accept()  # Should be ready to read
    print(f"Accepted connection from {addr}")
    conn.setblocking(False)
    
    data = types.SimpleNamespace(addr=addr, inb=b"", outb=b"")
    events = selectors.EVENT_READ | selectors.EVENT_WRITE
    sel.register(conn, events, data=data)

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
                service_connection(key, mask)
except KeyboardInterrupt:
    print("Caught keyboard interrupt, exiting")
finally:
    sel.close()


