"""
Working with files is probably the most common example of resource management in programming. In Python, you can use a try … finally statement to handle opening and closing files properly:

>>> # Safely open the file
>>> file = open("hello.txt", "w")
>>> 
>>> try:
>>>     file.write("Hello, World!")
>>> finally:
>>>     # Make sure to close the file after using it
>>>     file.close()

In this example, you need to safely open the file hello.txt, which you can do by wrapping the call to open() in a try … except statement. Later, when you try to write to file, the finally clause will guarantee that file is properly closed, even if an exception occurs during the call to .write() in the try clause. You can use this pattern to handle setup and teardown logic when you’re managing external resources in Python.

The try block in the above example can potentially raise exceptions, such as AttributeError or NameError. You can handle those exceptions in an except clause like this:

# Safely open the file
file = open("hello.txt", "w")

try:
    file.write("Hello, World!")
except Exception as e:
    print(f"An error occurred while writing to the file: {e}")
finally:
    # Make sure to close the file after using it
    file.close()

In this example, you catch any potential exceptions that can occur while writing to the file. In real-life situations, you should use a specific exception type instead of the general Exception to prevent unknown errors from passing silently.

NOTE: Me. The exception is caught, taken care of, and then finally, the file is always closed. The problem here is that if we need to return something or reraise the exception, then the finally statement will not be executed.
"""
