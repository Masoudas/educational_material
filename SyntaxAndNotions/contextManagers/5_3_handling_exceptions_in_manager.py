"""
Here's an example of how we handle exceptions directly inside the exit method. Notice that we return True only inside the bit of the code that handles exception, and not all the function.
If we return False in the if branch as well, then that exception is raised as well.
"""


class HelloContextManager:
    def __enter__(self):
        print("Entering the context...")
        return "Hello, World!"

    def __exit__(self, exc_type, exc_value, exc_tb):
        print("Leaving the context...")
        if isinstance(exc_value, IndexError):
            # Handle IndexError here...
            print(f"An exception occurred in your with block: {exc_type}")
            print(f"Exception message: {exc_value}")
            return True


with HelloContextManager() as h:
    print(h)
    h[100]

print("Continue normally from here...")
