"""
Sets are (mutable) unordered collections of data, with no duplicate elements. We can create sets using curly braces
or the 'set' expression.
"""

s1 = {1, 2, 3}
s2 = set([1, 2, 4])

# Check this comparison. Recall that in can be used to check whether something exists in an iterable.
s3 = {x for x in "abcdefg,how I wonder what you are" if x not in "abcd"}
print(s3)