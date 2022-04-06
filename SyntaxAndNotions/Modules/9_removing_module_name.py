"""
This is all me:

A trick that I use to remove the module name is to define a relative import inside the __init__ file. Consider the
following file:

%%% package/myClass.py
class MyClass:
	pass

Now, in the corresponding __init__ file, I define:
from .myClass import MyClass

This implies that we can import MyClass as follows:

import package
c = package.MyClass()

Otherwise, this would have to be written as:
import package.myClass
c = package.myClass.MyClass()

"""