"""
Me: A list if I may recall is actually a contiguous array, but is essentially used like a linked list. This should
be considered when using lists.

	- list.append(x):	Add an item to the end of the list. Equivalent to a[len(a):] = [x].	
						Note me: Can only append a single item with this. list.append([...]) appends this list
						(not its items) to the end of this.
	- list.extend(iterable):	Extend the list by appending all the items from the iterable. Equivalent to 
								a[len(a):] = iterable.	
								Me: Appends every item of the list, not the entire list to the current list.
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
	- list.copy():		A SHALLOW copy of the list. Does not copy elements (unless they are primitives of course!)

Notice that methods like insert, remove or sort that only modify the list have no return value. They return the 
default None. This is a design principle for all mutable data structures in Python.
"""

ls = [1, 2, 3, 4]
ls[len(ls):] = ls	# Append this list manually, from len(ls), the first empty index.
ls[len(ls):] = 5, 6, 7	# Append the elements of this tuple.
ls.append(8)	# Append this item
ls.append([1, 2, 3])	 # Warning: Appends [1, 2, 3], and not its elements
ls.extend([9, 10 , 11])	# Appends the elements of this list.

print(ls)

ls.sort(reverse=True)	# Sorts in place.
print(ls)

# Various copies
ls1 = ls	# Reference
ls2 = ls.copy()

import copy
ls3 = copy.deepcopy(ls)