"""
The text type is one of the most common types out there and is often called string or, in Python, just str.

String concatenation is done using the + operator.
To select a particular char, use the [] operator. To get the size of the string, use the len operator of the 
string class.

If we use the multiply operator, the string will be repeated, as shown below.
"""

my_city = "New York"
print(type(my_city))

#Single quotes have exactly
#the same use as double quotes
my_city = 'New York'
print(type(my_city))

#Setting the variable type explicitly
my_city = str("New York")
print(type(my_city))

## String concatenation
my_address = my_city + " " + "my road"
print(my_address)

print("Printing the first char: " + my_address[0])
print("The length of the string is:", len(my_address))

print(my_city * 2)	# Prints New YorkNew York 