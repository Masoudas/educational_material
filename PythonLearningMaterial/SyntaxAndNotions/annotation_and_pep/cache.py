"""
The cache annotator is an interesting one. It caches certain io for a function (pairs of inputs and their results.)
As such, it's possible to use the cached values instead of actually executing the function, which would immensly
improve speed in certain scenarios.

An example is given below where if we we use the cache annotation on the Fibonnaci function, we get faster
responses from the recursion (especially given that Fibonnaci has a lot of repetitive work.) It would make the
function go crazy in terms of speed.

Note that there's also the lru_cache annotator, which I think keeps the cache from growing without a bound.

Note that cache is in functools.
"""
from itertools import count
from functools import cache, lru_cache

@cache
def Fib(n):
	if n <= 1:
		return 1
	return Fib(n-1) + Fib(n-2)


for i in count():
	print(Fib(i))
