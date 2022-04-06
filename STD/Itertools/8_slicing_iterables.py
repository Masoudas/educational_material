"""
We can slice an iterable using islice! Again, this is far better than creating an slice from a list, which would
create a copy out of it.

See for example how we read the odd lines of a file. This would be a nice lazy iterator.
"""
from itertools import islice

ls = list(range(1, 100))

ls1 = ls[0:100:2]	# Copy of the list
print(ls1)
for i in islice(ls, 0, 100, 2):
	print(i)

for odd_lines in islice(open("myFile.txt", "r"), 1, 2, 100):
	print(odd_lines)