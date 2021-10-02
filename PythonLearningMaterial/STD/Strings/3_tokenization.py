"""
To tokenize a string, we can use the split method of python.

When tokenization occurs, the string is broken from the first char to the to token. If there are no tokens, then
the entire string is returned.

Below, we also have an example of csv file manipulation as well.
"""
my_str = "This is my string"
tokens = my_str.split(' ')

for token in tokens:
	print("The next token is: ", token)


no_space_str = "NoSpaces"
print(no_space_str.split(" "))

## csv file manipulation
csv_field = "masoud;as;masoudas@hotmail.com"

print("The email address of the person is: ", csv_field.split(";")[2])