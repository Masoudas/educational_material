"""
To make a string: 
	-	lower case: We can use the lower method
	-	upper case: Use the upper method.
	-	title case: Meaning like a title, each word starts with a capital letter, use the title method.
	-	swap case: To swap cases in the string, use the swao method.

Remember that always a copy is returned.
"""
import re
my_string = "This is my original string"

# Generating the title string and at the same time removing the Original keyword.
print("The title version is: ", re.sub('[oO]riginal ', '', my_string.title())) 	