"""
This includes consice operations to create lists from a particular operation. Some examples are given below.

https://docs.python.org/3/tutorial/datastructures.html#
"""

my_list = list(map(lambda x : x**2, range(10)))	# Notice that is essentially a C++ for each.
print(my_list)

# Equivalently
my_list = [x**2 for x in range(10)]

## More complex examples
my_list = [ (x,y) for x in [1, 2, 3] for y in [2, 3, 4] if x != y ]	# Notice that this is a nested loop.
																	# Always read these expressions as nested loops.
print(my_list)															

# So, equivalently:
combs = []
for x in [1,2,3]:
    for y in [3,1,4]:
        if x != y:
            combs.append((x, y))

# We may also create nested lists as well:
matrix = [[i for row in range(4)] for i in range(4)]
transpose = [ [ x[i] for x in matrix ] for i in range(len(matrix)) ]
print(matrix, transpose)