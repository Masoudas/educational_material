"""
From Data Model, section 3.3.2.1, of the Language syntax documentation.

Me: Just like we can customize attribute access to a class (overloading the dot operator,) we can do the same with
the attributes of a module (meaning methods, data, class, etc.)

Special names __getattr__ and __dir__ can be also used to customize access to module attributes. The __getattr__ 
function at the module level should accept one argument which is the name of an attribute and return the computed 
value or raise an AttributeError. If an attribute is not found on a module object through the normal lookup, i.e. 
object.__getattribute__(), then __getattr__ is searched in the module __dict__ before raising an AttributeError. 
If found, it is called with the attribute name and the result is returned.

The __dir__ function should accept no arguments, and return a sequence of strings that represents the names 
accessible on module. If present, this function overrides the standard dir() search on a module.

For a more fine grained customization of the module behavior (setting attributes, properties, etc.), one can set 
the __class__ attribute of a module object to a subclass of types.ModuleType. For example:

import sys
from types import ModuleType

class VerboseModule(ModuleType):
    def __repr__(self):
        return f'Verbose {self.__name__}'

    def __setattr__(self, attr, value):
        print(f'Setting {attr}...')
        super().__setattr__(attr, value)

sys.modules[__name__].__class__ = VerboseModule
"""