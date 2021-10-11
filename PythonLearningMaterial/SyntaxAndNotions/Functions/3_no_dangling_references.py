"""
Notice that returning even a local variable from Python keeps that location in memory. As such, we can have very
weird examples like below, where the third print statement actually prints [1, 2, 3]!

As such, we tend to add an if statement with optional parameters in case we have optional parameters that we 
want to return.
"""

def f(a, L=[]):
	L.append(a)
	return L

print(f(1))
print(f(2))
print(f(3))

def f(a, L=None):
    if L is None:
        L = []
    L.append(a)
    return L