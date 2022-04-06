"""
Like list comprehensions, generator expressions allow you to quickly create a generator object in just a few 
lines of code. They’re also useful in the same cases where list comprehensions are used, with an added benefit: 
you can create them without building and holding the entire object in memory before iteration. In other words, 
you’ll have no memory penalty when you use generator expressions.

nums_squared_lc = [num**2 for num in range(5)]	# List comprehension
nums_squared_gc = (num**2 for num in range(5))

Notice that:
sys.getsizeof(nums_squared_lc)
87624

print(sys.getsizeof(nums_squared_gc))
120

There is one thing to keep in mind, though. If the list is smaller than the running machine’s available memory, 
then list comprehensions can be faster to evaluate than the equivalent generator expression. 

import cProfile
cProfile.run('sum([i * 2 for i in range(10000)])')
cProfile.run('sum((i * 2 for i in range(10000)))')

"""