"""
To loop over an unsorted list in a sorted way, use the sorted metho, which returns a sorted copy of the original
list, and independent of it.

We may also use set on that list to eliminate duplicate values. The use of sorted() in combination with set() over 
a sequence is an idiomatic way to loop over unique elements of the sequence in sorted order.
"""

ls = [1, 4, 4, 2, 3, 2]

for item in sorted(ls):
	print(item)

for item in sorted(set(ls)):
	print(item)