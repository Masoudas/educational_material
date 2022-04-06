"""
To generate a multiline string, we may use the triple quote, as we do for comments. Note that the same can be
done with single quote as well.

We can also use paranthesis or \ to go to the next line. But note that these are not multi-line texts, and in 
fact, we need to add a \n to go to the next line.
"""

my_str = """This is my multi-line string.
I use it as a plaything.

Here's an @ letter."""

print(my_str)

my_single_quote_str = '''\nThis is my multi-line string.
I use it as a plaything.'''
print(my_single_quote_str)

########
single_line_string = ("This is a single line string."
"As we can see, no string breakup occures."
"We can use it as a plaything."
)

single_line_string = "This is another version of the same phenomena." \
	" We can use it to concatenate strings together as well."

print(single_line_string)