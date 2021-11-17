"""
Returns all the possible combinations and permutations from an iterable. By combination, we mean all choose k
from n (hence, non-repetitive k pairs) and by combinations, we mean all n! permutations (and not 2^k).

If we wanted repetition, we use the product function, which returns the Cartesian product of our items.
It's interesting to note that with product, we can pass several iterables, and the products of those iterable
members is made.
"""
from itertools import combinations, permutations, product, combinations_with_replacement


print(list(combinations(range(10), 2)))	# Returns a list of 2 element tuples of combinations of 0 to 9, Order does
										# not matter. In other words, (0,0) and (1,1) are not there.
# [(0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (0, 6), ..., (7, 8), (7, 9), (8, 9)]

l1 = ['a', 'b', 'c']
l2 = [1, 2, 3]
print(list(combinations(l1, 2)))  # 3 choose 2 is 3
#[('a', 'b'), ('a', 'c'), ('b', 'c')]

print(list(combinations_with_replacement(l1, 2)))  # 3 choose 2 is 3
#[('a','a'), [('a', 'b'), ...]

print(list(permutations(l1, 2))) # 3! is 6
# [('a', 'b'), ('a', 'c'), ('b', 'a'), ('b', 'c'), ('c', 'a'), ('c', 'b')]

print(list(product(l1, repeat=2))) # 3 * 3 = 9
# [('a', 'a'), ('a', 'b'), ('a', 'c'), ... ]

t1 = (0,1)
t2 = (1,0)
print(list(product(t1, t2, repeat=2))) # 3 * 3 = 9
# [(0, 1, 0, 1), (0, 1, 0, 0), ...