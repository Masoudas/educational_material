"""
Using eval, we can compile code at runtime. The entire processes of compilation and execution is thus done
at runtime, as the following example demonstrates. The result (at least in the following case) is an 
int (or I guess whatever the result of such an expression might be).
"""

a = 'abc'
b = '4 + len(a)'
print(eval(b), type(eval(b)))