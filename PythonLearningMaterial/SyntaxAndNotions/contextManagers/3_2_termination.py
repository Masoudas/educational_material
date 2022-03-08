"""
Once the with code block finishes, .__exit__() gets called. This method typically provides the teardown logic or cleanup code, such as calling .close() on an open file object. That’s why the with statement is so useful. It makes properly acquiring and releasing resources a breeze.

Here’s how to open your hello.txt file for writing using the with statement:

>>> with open("hello.txt", mode="w") as file:
>>>     file.write("Hello, World!")

When you run this with statement, open() returns an io.TextIOBase object. This object is also a context manager, so the with statement calls .__enter__() and assigns its return value to file. Then you can manipulate the file inside the with code block. When the block ends, .__exit__() automatically gets called and closes the file for you, even if an exception is raised inside the with block.
"""