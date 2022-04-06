"""
Modules are a basic organizational unit of Python code, and are created by the import system as invoked either by 
the import statement, or by calling functions such as importlib.import_module() and built-in __import__(). A module 
object has a namespace implemented by a dictionary object (this is the dictionary referenced by the __globals__ 
attribute of functions defined in the module). Attribute references are translated to lookups in this dictionary, 
e.g., m.x is equivalent to m.__dict__["x"]. A module object does not contain the code object used to initialize 
the module (since it isn’t needed once the initialization is done).

Attribute assignment updates the module’s namespace dictionary, e.g., m.x = 1 is equivalent to m.__dict__["x"] = 1.

Predefined (writable) attributes:

			__name__							The module’s name.

			__doc__								The module’s documentation string, or None if unavailable.

			__file__							The pathname of the file from which the module was loaded, if it 
												was loaded from a file. The __file__ attribute may be missing for 
												certain types of modules, such as C modules that are statically 
												linked into the interpreter. For extension modules loaded dynamically 
												from a shared library, it’s the pathname of the shared library file.

		__annotations__							A dictionary containing variable annotations collected during module 
												body execution. 

Special read-only attribute: __dict__ is the module’s namespace as a dictionary object.
"""