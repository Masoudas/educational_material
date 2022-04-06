"""
It's been suggested in Python docs that sometimes checking for the ability to access a file takes a lot of time,
and as such, openning the file might throw, as we show in example 1.

It's been suggested to use a try/else construct to to avoid this problem, as the following example demonstrates.
It does make sense, because even though the size of the code increases, the speed would improve as well.
"""
from os import R_OK, W_OK, X_OK, access
if access("my_file.txt", R_OK | X_OK | W_OK):
	with open("my_file.txt") as f:	# This may already throw when getting here
		print(f.read())

# A suggested approach:
try:
	f = open("my_file.txt", "r")
except OSError:
	print("Couldn't open the file")
else:
	print(f.read())
	f.close()

