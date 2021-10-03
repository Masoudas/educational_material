"""
We may also use deques (double ended queues) from the collection module. Note, however, that the behavior of 
such a data structure can be modeled with a list as well.
"""
from collections import deque

my_dq = deque(["Masoud", "Navid", "Babak"])
my_dq.append("Ruhi")	# Don't use the insert method.

my_dq.popleft()	# Pop from the top of the deque
print(my_dq)