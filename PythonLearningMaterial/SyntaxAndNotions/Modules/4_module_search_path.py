"""
When a module named spam is imported, the interpreter first searches for a built-in module with that name. If not 
found, it then searches for a file named spam.py in a list of directories given by the variable sys.path. sys.path 
is initialized from these locations:
	-	The directory containing the input script (or the current directory when no file is specified).
	-	PYTHONPATH (a list of directory names, with the same syntax as the shell variable PATH).
	-	The installation-dependent default (by convention including a site-packages directory, handled by the site 
		module).

Note: symbolic links are calculated, and are never set here.
ME: As such, there's no OS level variable to search for libraries, and we must add to sys.path to add new locations.
On the other hand, if we define PYTHONPATH, then the content of that variable is used in sys.path.

"""
import sys
print(sys.path)

sys.path.insert(0, '/')	# Adding a new path
print(sys.path)