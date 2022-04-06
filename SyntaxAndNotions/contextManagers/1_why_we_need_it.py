"""This tutorial is taken from https://realpython.com/python-with-statement/

One common problem you’ll face in programming is how to properly manage external resources, such as files, locks, and network connections. Sometimes, a program will retain those resources forever, even if you no longer need them. This kind of issue is called a memory leak because the available memory gets reduced every time you create and open a new instance of a given resource without closing an existing one.

Managing resources properly is often a tricky problem. It requires both a setup phase and a teardown phase. The latter phase requires you to perform some cleanup actions, such as closing a file, releasing a lock, or closing a network connection. If you forget to perform these cleanup actions, then your application keeps the resource alive. This might compromise valuable system resources, such as memory and network bandwidth.

For example, a common problem that can arise when developers are working with databases is when a program keeps creating new connections without releasing or reusing them. In that case, the database back end can stop accepting new connections. This might require an admin to log in and manually kill those stale connections to make the database usable again.

Another frequent issue shows up when developers are working with files. Writing text to files is usually a buffered operation. This means that calling .write() on a file won’t immediately result in writing text to the physical file but to a temporary buffer. Sometimes, when the buffer isn’t full and developers forget to call .close(), part of the data can be lost forever.

Another possibility is that your application runs into errors or exceptions that cause the control flow to bypass the code responsible for releasing the resource at hand. Here’s an example in which you use open() to write some text to a file:

file = open("hello.txt", "w")
file.write("Hello, World!")
file.close()

This implementation doesn’t guarantee the file will be closed if an exception occurs during the .write() call. In this case, the code will never call .close(), and therefore your program might leak a file descriptor.

In Python, you can use two general approaches to deal with resource management. You can wrap your code in:

    -   A try … finally construct
    -   A with construct

"""
