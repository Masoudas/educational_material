"""
Here's an example of how to use decorators together with generator functions. This example is a file manager.
"""

from contextlib import contextmanager


@contextmanager
def writable_file(file_path):
    file = open(file_path, mode="w")
    try:
        yield file
    finally:
        file.close()


with writable_file("hello.txt") as file:
    file.write("Hello, World!")
