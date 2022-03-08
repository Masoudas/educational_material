"""
The simplest context manager is implemented below. Notice that in the second example, when an exception is raised, it's called and printed, and it's as well propagated.
"""


class Manager:
    def __enter__(self):
        print("Entering the context...")
        return "Hello, World!"

    def __exit__(self, exc_type, exc_value, exc_tb):
        print("Leaving the context...")
        print(exc_type, exc_value, exc_tb)


with Manager() as f:
    print(f)    # The return value of enter

with Manager() as f:
    print(f)    # The return value of enter
    f[100]
