"""
We can, like any data structure, delete elements from inside a dictionary. 

We can't, as we know, sort dictionaries based on keys or values, because they're hash-based data structures (neither
in the order we insert the elements, nor in their natural order). 

We can, however, convert a dictionary keys directly to a list. According to the standard, it returns the keys in
their order of insertion.
"""
dic = {"Masoud" : 1, "Navid" : 2, "Zanesh" : 3}
dic["Doctor"] = 4


print("Original unsorted dictionary is: ", dic)

ls = list(dic)	# Keys are returned with insertion order in this scheme
print("Keys with insertion order are:", ls)

ls.sort()
print("Printing sorted key value pairs:")
for key in ls:
	print("(", key, ",", dic[key], ")") 