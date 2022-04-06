"""
To check whether a string is only alpha-numeric (chars and numbers) or only contains spaces, use the corresponding
methods.

The printable chars returns false if carriage return (\r) line feed (\f), \n, \t or \v exist in the string.
"""
my_str = "This is my string"
if my_str.isalnum() and not my_str.isupper():
	print(my_str)

my_str1 = "\f\n\v\t"	# All these are not printable.
print(my_str1.isprintable())