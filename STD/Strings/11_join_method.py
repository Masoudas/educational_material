"""
Using the join method, we'd be able to join the elements of an iterable in python. The join method accepts what
to use as the join string.
"""
words = ['This', 'is', 'good']

joined_string = ' '.join(words)	# Uses space as the joing char
print(joined_string)

joined_with_dot = '.'.join(words)
print(joined_with_dot)