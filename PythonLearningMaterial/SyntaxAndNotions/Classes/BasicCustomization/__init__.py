"""
Called after the instance has been created (by __new__()), but before it is returned to the caller. The arguments 
are those passed to the class constructor expression. If a base class has an __init__() method, the derived class’s 
__init__() method, if any, must explicitly call it to ensure proper initialization of the base class part of the 
instance; for example: super().__init__([args...]).

Me: As such, we notice that there's no implicit call to super.__init__ if we override the derived class __init__.

Because __new__() and __init__() work together in constructing objects (__new__() to create it, and __init__() to 
customize it), no non-None value may be returned by __init__(); doing so will cause a TypeError to be raised at 
runtime.
"""