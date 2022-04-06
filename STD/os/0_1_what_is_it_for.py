"""
This module is for leveraging os functionalities, and also for file and path manipulation.

As a reminder, we can change the content of a module using dir, or get its dictionary.

Notice for example that the pathsep variable returns the path separator for this os (which is oddly ':' for
my Ubuntu Linux machine).
"""
import os

print(dir(os))
print(os.pathsep)


#print(os.__dict__)