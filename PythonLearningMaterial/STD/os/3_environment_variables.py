"""
For accessing environment variables, use the environ variable, which is a dictionary of variables.
"""
from os import environ

print(environ.get("HOME"))
print(environ.get("USERNAME"))
print(environ.get("PATH"))

for var, value in environ.items():
	print(var, value)