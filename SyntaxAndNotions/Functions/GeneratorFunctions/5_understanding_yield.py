"""
When you call a generator function or use a generator expression, you return a special iterator called a 
generator. You can assign this generator to a variable in order to use it. When you call special methods on the 
generator, such as next(), the code within the function is executed up to yield.

When the Python yield statement is hit, the program suspends function execution and returns the yielded value to 
the caller. (In contrast, return stops function execution completely.) When a function is suspended, the state 
of that function is saved. This includes any variable bindings local to the generator, the instruction pointer, 
the internal stack, and any exception handling.

We can best see this with the following example:

def multi_yield():
    yield_str = "This will print the first string"
    yield yield_str
    yield_str = "This will print the second string"
    yield yield_str

>>> multi_obj = multi_yield()
>>> print(next(multi_obj))
This will print the first string
>>> print(next(multi_obj))
This will print the second string
>>> print(next(multi_obj))
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
StopIteration
"""