"""
The echo server definitely has its limitations. The biggest one is that it serves only one client and then exits. The echo client has this limitation too, but there’s an additional problem. When the client uses s.recv(), it’s possible that it will return only one byte, b'H' from b'Hello, world'.

""
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b"Hello, world")
    data = s.recv(1024)
""

The bufsize argument of 1024 used above is the maximum amount of data to be received at once. It doesn’t mean that .recv() will return 1024 bytes.

The .send() method also behaves this way. It returns the number of bytes sent, which may be less than the size of the data passed in. You’re responsible for checking this and calling .send() as many times as needed to send all of the data:

NOTE: Applications are responsible for checking that all data has been sent; if only some of the data was transmitted, the application needs to attempt delivery of the remaining data. In the example above, you avoided having to do this by using .sendall(). “Unlike send(), this method continues to send data from bytes until either all data has been sent or an error occurs. None is returned on success.”

You have two problems at this point:
    -   How do you handle multiple connections concurrently?
    -   You need to call .send() and .recv() until all data is sent or received.

The trouble with concurrency is it’s hard to get right. There are many subtleties to consider and guard against. All it takes is for one of these to manifest itself and your application may suddenly fail in not-so-subtle ways.

This isn’t meant to scare you away from learning and using concurrent programming. If your application needs to scale, it’s a necessity if you want to use more than one processor or one core. However, for this tutorial, you’ll use something that’s even more traditional than threads and easier to reason about. You’re going to use the granddaddy of system calls: .select().
"""