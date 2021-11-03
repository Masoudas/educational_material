"""
As another example, consider the following sequence creations:

a = range(5) # Method 1, and returns a lazy iterator.

def infinite_loop():
    ctr = 0
    while True:
        yield ctr
        ctr += 1

Note that instead of using a for loop, you can also call next() on the generator object directly.

print(next(infinite_loop());
print(next(infinite_loop()); 

Notice that as such, the function keeps the state up until the execution of yield.

Note that in practice, you’re unlikely to write your own infinite sequence generator. The itertools module 
provides a very efficient infinite sequence generator with itertools.count().
"""

