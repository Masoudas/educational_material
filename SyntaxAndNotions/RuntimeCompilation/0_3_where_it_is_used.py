"""
The use of eval is in dynamic construction. For example, we can generate named tuples with given attributes
with a dynamic constructor as shown below:

The way it does it is using exec, which is equivalent to eval.

Another use case is in documentations. Often, function or class docs contain code examples. We can retrive
those with the __docs__ method, then extract the code lines, and then execute them using eval! This is
called the doctests module in the standard library.
"""
from collections import namedtuple

Point = namedtuple('Point', 'x y z') # Or could be namedtuple('Point', ['x', 'y', 'z'])

p = Point(3.0, 4.0, 5.0)
print(p.z)