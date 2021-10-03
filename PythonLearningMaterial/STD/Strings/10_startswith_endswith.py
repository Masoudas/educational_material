"""
To check whether a string:
	-	Starts with something: Use startswith
	-	Ends with something: Use endswith

"""
my_str = "Starts with, 	, and ends with"
if my_str.startswith("Starts with") and my_str.endswith("ends with"):
	print("Yep!")