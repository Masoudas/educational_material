"""
Okay, so what exactly is happening in the API call?

socket.socket() creates a socket object that supports the context manager type, so you can use it in a with statement. There’s no need to call s.close().

The arguments passed to socket() are constants used to specify the address family and socket type. AF_INET is the Internet address family for IPv4. SOCK_STREAM is the socket type for TCP, the protocol that will be used to transport messages in the network.

The .bind() method is used to associate the socket with a specific network interface and port number. The values passed to .bind() depend on the address family of the socket. In this example, you’re using socket.AF_INET (IPv4). So it expects a two-tuple: (host, port). host can be a hostname, IP address, or empty string. If an IP address is used, host should be an IPv4-formatted address string. The IP address 127.0.0.1 is the standard IPv4 address for the loopback interface, so only processes on the host will be able to connect to the server. If you pass an empty string, the server will accept connections on all available IPv4 interfaces. port represents the TCP port number to accept connections on from clients. It should be an integer from 1 to 65535, as 0 is reserved. Some systems may require superuser privileges if the port number is less than 1024. We prefer to use a numbered host name.

In the server example, .listen() enables a server to accept connections. It makes the server a “listening” socket. The .listen() method has a backlog parameter. It specifies the number of unaccepted connections that the system will allow before refusing new connections. Starting in Python 3.5, it’s optional. If not specified, a default backlog value is chosen. If your server receives a lot of connection requests simultaneously, increasing the backlog value may help by setting the maximum length of the queue for pending connections. The maximum value is system dependent. For example, on Linux, see /proc/sys/net/core/somaxconn.

The .accept() method blocks execution and waits for an incoming connection. When a client connects, it returns a new socket object representing the connection and a tuple holding the address of the client. The tuple will contain (host, port) for IPv4 connections or (host, port, flowinfo, scopeid) for IPv6. See Socket Address Families in the reference section for details on the tuple values.

One thing that’s imperative to understand is that you now have a new socket object from .accept(). This is important because it’s the socket that you’ll use to communicate with the client. It’s distinct from the listening socket that the server is using to accept new connections.

After .accept() provides the client socket object conn, an infinite while loop is used to loop over blocking calls to conn.recv(). This reads whatever data the client sends and echoes it back using conn.sendall(). (Me: So recv is used for receiving data from the connection, and sendall for sending data. Note that recv is a blocking method. Moreover, when we make a TCP connection, we're allowed to both send and receive data on the same connection, i.e, no need to create a new connection. Finally, note that the if statement checks that if the sender sends an empty string, it will close the reception loop.)

Me: What's missing from this loop? One thing is that we can't handle multiple clients. Second is that if a client closes, then we can't receive from it again (which is the same as above.) A third issue is that if we close the execution of this code, then we have to wait before we're allowed to bind to the same host again. Why? This is a property of linux. We can check this by stoping the execution of the code and then rerunning it. We see that it gives a message "address already in use". This latter can be taken care of with the following code:

# Avoid bind() exception: OSError: [Errno 48] Address already in use
lsock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

"""
import socket

HOST = "0.0.0.0"  # Standard loopback interface address (localhost)
PORT = 5000  # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print(f"Connected by {addr}")
        while True:
            data = conn.recv(1024)
            print(data)
            if not data:
                break
            conn.sendall(data)