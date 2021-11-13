"""
Beside regex, we can use the find method to check for a particular substring. The find method returns the first
position where our goal string is found, or -1.

There's also the famous 'in' operator, which works because Strings are iterables. 

Notice, however, the difference between this method and the index method, where the index method throws in case
the substring does not exist, but find does not.
"""

if "You" in "YouTube" and "YouTube".find("You") != -1:
	print("You exists, two ways!")