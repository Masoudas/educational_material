"""
The simplest context manager is implemented below. Notice that in the second example, when an exception is raised, it's called and printed, and it's as well propagated.

ME: Also notice that working with instance variables is also fine. In such a case, we just call the __enter__ and __exit__ method. This is useful if I have to create the instance of my context manager before actually using it.
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

mananger = Manager()

with mananger as m:
    print(m)

with Manager() as f:
    print(f)    # The return value of enter
    f[100]
