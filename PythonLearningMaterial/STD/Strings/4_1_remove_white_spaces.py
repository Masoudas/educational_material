"""
It's essentially possible to remove all occurances of a particular string using the join method, as we show
below.

In a narrow-minded way, we can also do the same using the tokenization method as well, but because we want to
remove all possible white-spaces, we can use the regular expressions (from the re module) to do the same.

Just like in C++, we supply raw strings with r'', allowing the string information to be considered literal.

Also, notice that the space char \s is equivalent to space, \n, \t, \f and \v.
"""
import re

my_str = "This is the	 string.\nI use it as a play thing "

print(my_str)
print(re.sub(r'\s', '', my_str))