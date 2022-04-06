"""
Custom class types are typically created by class definitions (see section Class definitions). A class has a 
namespace implemented by a dictionary object. Class attribute references are translated to lookups in this 
dictionary, e.g., C.x is translated to C.__dict__["x"] (although there are a number of hooks which allow for other 
means of locating attributes). When the attribute name is not found there, the attribute search continues in the 
base classes. This search of the base classes uses the C3 method resolution order which behaves correctly even in 
the presence of ‘diamond’ inheritance structures where there are multiple inheritance paths leading back to a 
common ancestor. Additional details on the C3 MRO used by Python can be found in the documentation accompanying 
the 2.3 release at https://www.python.org/download/releases/2.3/mro/.

When a class attribute reference (for class C, say) would yield a class method object, it is transformed into an 
instance method object whose __self__ attribute is C. When it would yield a static method object, it is transformed 
into the object wrapped by the static method object. 

Class attribute assignments update the class’s dictionary, never the dictionary of a base class.

A class object can be called (see above) to yield a class instance (me: using __new__).

Special attributes:

			__name__						The class name.

			__module__						The name of the module in which the class was defined.

			__dict__						The dictionary containing the class’s namespace.

			__bases__						A tuple containing the base classes, in the order of their occurrence 
											in the base class list.

			__doc__							The class’s documentation string, or None if undefined.

			__annotations__					A dictionary containing variable annotations collected during class 
											body execution. 
"""