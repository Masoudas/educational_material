"""
It's possible to write the following condition in an if statement:

if a < b == c:

This implies if a is less than b. Moreover, if b equals C (recall that logical comparisons have less priority than
numerical comparisons.) Don't do it, however!

Recall also that 'and' and 'or' have less priority than comparison operators, yet 'not' has a higher priority than
'and' and 'or', but less than numerical comparison, and equiality, etc. Note that 'and' and 'or' are short-circuit
operators. When used as a general value and not as a Boolean, the return value of a short-circuit operator is the 
last evaluated argument. For example, consider the following expression

string1, string2, string3 = '', 'Trondheim', 'Hammer Dance'
non_null = string1 or string2 or string3
non_null
'Trondheim'

Note that in Python, unlike C, assignment inside expressions must be done explicitly with the walrus operator :=. 
This avoids a common class of problems encountered in C programs: typing = in an expression when == was intended.
"""

x = 10

if (x := 20) > 15:	# Recall that assignment has lower priority than >. x = 20 > 15 would be an error
	print(x)	# x is not 20