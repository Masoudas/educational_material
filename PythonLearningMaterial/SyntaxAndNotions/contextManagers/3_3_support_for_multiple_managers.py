"""
In Python 3.1 and later, the with statement supports multiple context managers. You can supply any number of context managers separated by commas:

with A() as a, B() as b:
    pass
This works like nested with statements but without nesting. This might be useful when you need to open two files at a time, the first for reading and the second for writing:

with open("input.txt") as in_file, open("output.txt", "w") as out_file:
    # Read content from input.txt
    # Transform the content
    # Write the transformed content to output.txt
    pass

"""