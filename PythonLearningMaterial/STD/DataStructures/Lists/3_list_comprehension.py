"""
This includes consice operations to create lists from a particular operation. Some examples are given below.
"""

my_list = list(map(lambda x : x**2, range(10)))	# Notice that a map is not a dictionary, but is essentially a C++ 
                                                # for each. The syntax is __init__(callable, iterable), meaning 
                                                # the mapping is done with callable on the range
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
transpose = [[x[i] for x in matrix] for i in range(len(matrix))]
print(matrix, transpose)