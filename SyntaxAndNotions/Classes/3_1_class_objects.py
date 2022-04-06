"""
Class objects support two kinds of operations: attribute references and instantiation.

Attribute references use the standard syntax used for all attribute references in Python: obj.name. Valid attribute 
names are all the names that were in the class’s namespace when the class object was created. So, if the class 
definition looked like this:

class MyClass:
    '''A simple example class'''
    i = 12345

    def f(self):
        return 'hello world'

then MyClass.i and MyClass.f are valid attribute references, returning an integer and a function object, respectively. 
Class attributes can also be assigned to, so you can change the value of MyClass.i by assignment. __doc__ is also a 
valid attribute, returning the docstring belonging to the class: "A simple example class".


"""