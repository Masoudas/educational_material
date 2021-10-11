"""
A dot py file is a module, from which definitions are imported.

Within a module, the module’s name (as a string) is available as the value of the global variable __name__

Note when typing:

import module

This does not enter the names of the functions defined in fibo directly in the current symbol table; it only enters 
the module name fibo there. Using the module name you can access the functions.

Each module has its own private symbol table, which is used as the global symbol table by all functions defined in 
the module. Thus, the author of a module can use global variables in the module without worrying about accidental 
clashes with a user’s global variables. Me: The dot notation does not allow name clashes to happen.

The following directly imports the names of modules:
from fibo import fib, fib2

The import statemet:
from fibo import *	# Import all names.

imports all names except those that start with _.

If the module name is followed by as, then the name following as is bound directly to the imported module.
import fibo as fib

and we can also say:
from fibo import fib as fibonacci
"""

import copy
print(__name__, copy.__name__)