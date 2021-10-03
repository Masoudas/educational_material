"""
Me: A list if I may recall is actually a contiguous array, but is essentially used like a linked list. This should
be considered when using lists.

	- list.append(x):	Add an item to the end of the list. Equivalent to a[len(a):] = [x].	Me: Appending manually.
	- list.extend(iterable):	Extend the list by appending all the items from the iterable. Equivalent to 
								a[len(a):] = iterable.	Me: Essentially, like the previous one.
	- list.remove(x):	Remove the first item from the list whose value is equal to x. It raises a ValueError if 
						there is no such item.
	- list.pop([i]):	Remove the item at the given position in the list, and return it. If no index is specified, 
						a.pop() removes and returns the last item in the list. Recall that [] always means optional.
	- list.clear():		Equivalent to 'del list[:]'.
	- list.index(x[, start[, end]]):	Return zero-based index in the list of the first item whose value is equal 
										to x. Raises a ValueError if there is no such item. We may limit the search
										position.
	- list.count(x):	Return the number of times x appears in the list.
	- list.sort():		For sorting lists.
	- list.copy():		A shallow copy of the list.

Notice that methods like insert, remove or sort that only modify the list have no return value. They return the 
default None. This is a design principle for all mutable data structures in Python.
"""

ls = [1, 2, 3, 4]
ls[len(ls):] = ls	# Append this list manually, from len(ls), the first empty index.

print(ls)

ls.sort(reverse=True)	# Sorts in place.
print(ls)