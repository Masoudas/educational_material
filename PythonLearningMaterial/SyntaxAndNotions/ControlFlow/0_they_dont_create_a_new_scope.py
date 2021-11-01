"""
for loops, while loops and if loops don't create new scopes in Python. Yeah. Be careful! Sei vorsichtig!
"""

j = 0
while (j < 1):
	j += 1
	k = 1

for i in range(10):
	pass 

if True:
	l = 10

print(i, k, l)	# Prints them all! Can you believe it?!