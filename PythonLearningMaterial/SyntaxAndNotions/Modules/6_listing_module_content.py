"""
It's possible to list the content of the module using the dir function. Without any arguments, it lists the content
of the current module.
"""
import sys
print(dir(sys))

print(dir())	# Prints content of current module, which includes sys (the name, not the content.)
