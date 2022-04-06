"""
Most containers in Python are implemented with iterators (me: implicitly convertible?). 

We can, however, explicitly use iterators as well, as shown below. The function returns an iterator object (with
methid __iter__) that defines the method __next__() which accesses elements in the container one at a time. When 
there are no more elements, __next__() raises a StopIteration exception which tells the for loop to terminate. You 
can call the __next__() method using the next() built-in function; this example shows how it all works
"""

for element in [1, 2, 3]:   # Uses the __itr__ method of lists.
    print(element)

# Equivalently:
for element in [1, 2, 3].__iter__():
    print(element)

for element in (1, 2, 3):
    print(element)

for key in {'one':1, 'two':2}:
    print(key)

for char in "123":
    print(char)

for line in open("myfile.txt"):
    print(line, end='')


## Using iterators explicitly
itr = iter([1, 2, 3])
print(itr.__next__())   # Implicit itr class next method.
print(next(itr))    # C++ type next.
print(next(itr))
