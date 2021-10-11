"""
Packages support one more special attribute, __path__. This is initialized to be a list containing the name of the 
directory holding the package’s __init__.py before the code in that file is executed. This variable can be modified; 
doing so affects future searches for modules and subpackages contained in the package.

As such, we can extend the paths to which we look at for the content of this module. This feature, however, is
rarely used.
"""