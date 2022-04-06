"""
There are two ways of defining tuples, as shown below. 

Single item tuples can be made a comma, or a paranthesis with comma. Note that a single paranthesis without 
paranthesis is considered a nesting paranthesis, and as such, it's not Ok to use it.

Me: I should not confuse the notion of sets with tuples. sets are not defined like tuples with paranthesis. Set
are defined with brackets. 

Tuples are immutable, hence faster!
"""

tp = 1, 2, 3
tp1 = (1, 2, 3)

print(type(tp), type(tp1))

single = 1,
single1 = (1)
print(type(single), type(single1))

## Neither assignment to existing items, or adding new items is possible.
#tp[1] = 2
#tp[3] = 5

# Tuples may contain immutable objects.
tp2 = ([],[])
tp2[1].append(5)