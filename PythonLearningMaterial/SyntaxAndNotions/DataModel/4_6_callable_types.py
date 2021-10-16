"""
These are the types to which the function call operation (see section Calls) can be applied:

	User-defined functions
A user-defined function object is created by a function definition (see section Function definitions). It should 
be called with an argument list containing the same number of items as the function’s formal parameter list.

We have the following attributes for a function (me: object:)

		Attribute											Meaning

		__doc__			The function’s documentation string, or None if unavailable; not inherited by subclasses.
						Writable

		__name__		The function’s name. Writable

	__qualname__		The function’s qualified name. New in version 3.3. Writable (Me from other places of docs:
						A dotted name showing the “path” from a module’s global scope to a class)

	__module__			The name of the module the function was defined in, or None if unavailable. Writable

	__defaults__		A tuple containing default argument values for those arguments that have defaults, or None 
						if no arguments have a default value. Writable

		__code__		The code object representing the compiled function body. Writable

		__globals__		A reference to the dictionary that holds the function’s global variables — the global 
						namespace of the module in which the function was defined. Read-only

		__dict__		The namespace supporting arbitrary function attributes. Writable.

		__closure__		None or a tuple of cells that contain bindings for the function’s free variables. Read-only

	__annotations__		A dict containing annotations of parameters. The keys of the dict are the parameter names,
						and 'return' for the return annotation, if provided. Writable

	__kwdefaults__		A dict containing defaults for keyword-only parameters. Writable

Most of the attributes labelled “Writable” check the type of the assigned value.

Function objects also support getting and setting arbitrary attributes, which can be used, for example, to attach 
metadata to functions. Regular attribute dot-notation is used to get and set such attributes. Note that the current 
implementation only supports function attributes on user-defined functions. Function attributes on built-in 
functions may be supported in the future.

A cell object has the attribute cell_contents. This can be used to get the value of the cell, as well as set the 
value.

Additional information about a function’s definition can be retrieved from its code object; see the description of 
internal types below. The cell type can be accessed in the types module.	
"""