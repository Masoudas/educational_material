"""
Python’s socket module provides an interface to the Berkeley sockets API. This is the module that you’ll use in this tutorial.

The primary socket API functions and methods in this module are:

    -   socket()
    -   .bind()
    -   .listen()
    -   .accept()
    -   .connect()
    -   .connect_ex()
    -   .send()
    -   .recv()
    -   .close()

Python provides a convenient and consistent API that maps directly to system calls, their C counterparts. In the next section, you’ll learn how these are used together.

As part of its standard library, Python also has classes that make using these low-level socket functions easier. Although it’s not covered in this tutorial, you can check out the socketserver module, a framework for network servers. There are also many modules available that implement higher-level Internet protocols like HTTP and SMTP. 
"""