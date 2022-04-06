"""
Notice that the d.keys() or d.items() are views of dictionary. As such, deleting an item removes the element
from the view as well. Why? Well, it undermined my knowledge of programming for a while. But as it turns,
the keys returns a class called dict_keys, and items return dict_items, which are not lists! As such,
problem solved, and phew!


"""
my_dict = dict([(1,1), (2,2), (3,3)])
keys1, keys2 = my_dict.keys(), my_dict.keys()
items1, items2 = my_dict.items(), my_dict.items()

print(id(keys1), id(keys2))	# These are not the same
print(id(items1), id(items2))	# These are not the same

del my_dict[1]	# Delete from the view!

print(1 in keys1)	# This prints false, naturally!
