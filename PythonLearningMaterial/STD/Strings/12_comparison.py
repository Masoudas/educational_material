"""
To compare:
	-	The content of strings: We use '==', '<=', '<' ... and other relational operators.
	-	Reference: We use the 'is' operator. (as for any other operator)

"""

str1 = "This"
str2 = "This"

if str1 == str2:	# And normally, str2 is str1 returns true in this case, due to string optimization.
	print("Content is equal")

str3 = "T" + str1[1:]

if str3 is not str and str3 == str1:
	print("The strings are not the same object, but have the same content")


