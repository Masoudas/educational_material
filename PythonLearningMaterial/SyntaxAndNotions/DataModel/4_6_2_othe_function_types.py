"""
	-	Generator functions
A function or method which uses the yield statement (see section The yield statement) is called a generator 
function. Such a function, when called, always returns an iterator object which can be used to execute the body of 
the function: calling the iterator’s iterator.__next__() method will cause the function to execute until it 
provides a value using the yield statement. When the function executes a return statement or falls off the end, 
a StopIteration exception is raised and the iterator will have reached the end of the set of values to be returned.

	-	Coroutine functions
A function or method which is defined using async def is called a coroutine function. Such a function, when called, 
returns a coroutine object. It may contain await expressions, as well as async with and async for statements. See 
also the Coroutine Objects section.

	-	Asynchronous generator functions
A function or method which is defined using async def and which uses the yield statement is called a asynchronous 
generator function. Such a function, when called, returns an asynchronous iterator object which can be used in an 
async for statement to execute the body of the function.

Calling the asynchronous iterator’s aiterator.__anext__() method will return an awaitable which when awaited will 
execute until it provides a value using the yield expression. When the function executes an empty return statement 
or falls off the end, a StopAsyncIteration exception is raised and the asynchronous iterator will have reached 
the end of the set of values to be yielded.

	-	Built-in functions
A built-in function object is a wrapper around a C function. Examples of built-in functions are len() and 
math.sin() (math is a standard built-in module). The number and type of the arguments are determined by the C 
function. Special read-only attributes: __doc__ is the function’s documentation string, or None if unavailable; 
__name__ is the function’s name; __self__ is set to None (but see the next item); __module__ is the name of the 
module the function was defined in or None if unavailable.

	-	Built-in methods
This is really a different disguise of a built-in function, this time containing an object passed to the C function 
as an implicit extra argument. An example of a built-in method is alist.append(), assuming alist is a list object. 
In this case, the special read-only attribute __self__ is set to the object denoted by alist

	-	Classes
Classes are callable. These objects normally act as factories for new instances of themselves, but variations are 
possible for class types that override __new__(). The arguments of the call are passed to __new__() and, in the 
typical case, to __init__() to initialize the new instance.

Class Instances
Instances of arbitrary classes can be made callable by defining a __call__() method in their class.
"""