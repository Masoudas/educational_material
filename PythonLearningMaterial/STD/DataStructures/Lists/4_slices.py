"""
Note that slices can be assigned to, but the assignment form is important. Moreover, note that the last element is 
-1, and the first one is exactly -len(list)
"""
ls = [1, 2, 3, 4]
ls[0:2] = 5, 6

# ls[0:2] = [5, 6]	# We're assigning only one element here, that is [5,6]! No assignment to ls[1]

print(ls)

