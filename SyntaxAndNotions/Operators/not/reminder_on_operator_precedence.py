"""
Whereas assignment has a low priority, equality has even higher priority than unary operators, like '='.

>>> not True == False
True

>>> False == not True
File "<stdin>", line 1
    False == not True
             ^
SyntaxError: invalid syntax

>>> False == (not True)
True
"""
