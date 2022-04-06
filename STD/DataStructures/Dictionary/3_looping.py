"""
Looping directly over a dictionary provides the keys to that dictionary only. Looping with the items method provides 
an iterator that returns the key and value pair as a tuple.
"""
dic = dict([("a", 1), ("b", 2), ("c", 3)])

for pair in dic:
	print(pair)

for key, value in dic.items():
	print(key, value)



