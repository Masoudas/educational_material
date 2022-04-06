"""
Goes through an iterable and groups them based on a certain key. It streams tuples of key together with the items
grouped by that key. The problem, however, is that we need to sort the iterable first, otherwise, we don't get
the result we except! So, sort first.
"""
from itertools import groupby

people = [
	{ 'name': 'John',
	  'city': 'Mashhad',
	  'state': 'Khorasan'},
	{ 'name': 'Jeff',
	  'city': 'Torbat',
	  'state': 'Khorasan' },
	{ 'name': 'Jj',
	  'city': 'Tehran',
	  'state': 'Tehran' },
	{ 'name': 'Jeff',
	  'city': 'Torbat',
	  'state': 'Khorasan' },
	{ 'name': 'Mamad',
	  'city': 'Torbat',
	  'state': 'Khorasan' }
]

# Group by the state value
def get_state(person):
	return person['state']

people = sorted(people, key=get_state)	# Needs to be sorted first.
groub_by_state = groupby(people, get_state)

for key, group in groub_by_state:
	print(key)
	for person in group:
		print(person)
