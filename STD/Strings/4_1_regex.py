"""
It's essentially possible to remove all occurances of a particular string using the sub method of the regex package, 
as we show below. Notice that 'sub' substitutes all occurances of the given regex. 

Just like in C++, we supply raw strings with r'', allowing the string information to be considered literal.

Also, notice that the space char \s in regex is equivalent to space, \n, \t, \f and \v.
"""
import re

my_str = ["This is the	 string.\nI use it as	 a play thing " for i in range(1,100000)]

for i in range(1, 10000):
	#print(my_str)
	#print(re.sub(r'\s', '', my_str))
	my_str[i] = re.sub(r'\s', '', my_str[i])