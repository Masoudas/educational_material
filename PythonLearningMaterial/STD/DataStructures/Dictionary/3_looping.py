"""
Looping directly over a dictionary provides the keys to that dictionary only. Looping with the items method provides 
an iterator that returns the key and value pair as a tuple.

Use zip to iterate over multiple dicts directly.
"""

dic = dict([("a", 1), ("b", 2), ("c", 3)])

for pair in dic:
	print(pair)

for pair in dic.items():
	print(pair)


questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for q, a in zip(questions, answers):
    print('What is your {0}?  It is {1}.'.format(q, a))

