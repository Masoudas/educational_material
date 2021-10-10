"""
We can use the format method of string to create formatted string. We must call the method as we create the string,
as the following example demonstrates.

Note: We can express percentages using {:n1.n2%}, where n1 and n2 represent the number of digits before and after
dot (see string format). Without the percentage, it will just be a floating point.

Me: Passing an integer after the ':' will cause that field to be a minimum number of characters wide. This is useful 
for making columns line up (me: I checked and negative and positive numbers are the same. It will add spaces to
our string.).

Note: Using the string methods, together with slicing etc, is also another way of formatting strings.

Notice that we can also use named arguments in the format method.
"""

yes_votes = 42_572_654	# Notice how the large literals are written.
no_votes = 43_132_495
percentage = yes_votes / (yes_votes + no_votes)

formatted_str = '{:-15} YES votes {:.2%}'.format(yes_votes, percentage)
print(formatted_str)


table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 7678}
for name, phone in table.items():
    print(f'{name:10} ==> {phone:10d}')

print('This {food} is {adjective}, this {food} I mean.'.format(food='spam', adjective='absolutely horrible'))