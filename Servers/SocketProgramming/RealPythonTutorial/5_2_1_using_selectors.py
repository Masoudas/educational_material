"""
The .select() method allows you to check for I/O completion on more than one socket. So you can call .select() to see which sockets have I/O ready for reading and/or writing. But this is Python, so there’s more. You’re going to use the selectors module in the standard library so that the most efficient implementation is used, regardless of the operating system you happen to be running on:

“This module allows high-level and efficient I/O multiplexing, built upon the select module primitives. Users are encouraged to use this module instead, unless they want precise control over the OS-level primitives used.” (Source)

Still, by using .select(), you’re not able to run concurrently. That said, depending on your workload, this approach may still be plenty fast. It depends on what your application needs to do when it services a request, and the number of clients it needs to support.

asyncio uses single-threaded cooperative multitasking and an event loop to manage tasks. With .select(), you’ll be writing your own version of an event loop, albeit more simply and synchronously. When using multiple threads, even though you have concurrency, you currently have to use the GIL (Global Interpreter Lock) with CPython and PyPy. This effectively limits the amount of work you can do in parallel anyway.

The actual code is written in the next script.
"""
