"""
Generator functions look and act just like regular functions, but with one defining characteristic. Generator 
functions use the Python yield keyword instead of return. For example:

def infinite_sequence():
    num = 0
    while True:
        yield num
        num += 1

This looks like a typical function definition, except for the Python yield statement and the code that follows it. 
yield indicates where a value is sent back to the caller, but unlike return, you don’t exit the function afterward.
Instead, the state of the function is remembered. That way, when next() is called on a generator object (either 
explicitly or implicitly within a for loop), the previously yielded variable num is incremented, and then yielded 
again. Since generator functions look like other functions and act very similarly to them, you can assume that 
generator expressions are very similar to other comprehensions available in Python.

"""