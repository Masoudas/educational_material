"""
Recall that we can use not to check various internal types, such as strings, lists, etc.

>>> # Use "not" with numeric values
>>> not 0
True
>>> not 42
False
>>> not 0.0
True
>>> not 42.0
False
>>> not complex(0, 0)
True
>>> not complex(42, 1)
False

>>> # Use "not" with strings
>>> not ""
True
>>> not "Hello"
False

>>> # Use "not" with other data types
>>> not []
True
>>> not [1, 2, 3]
False
>>> not {}
True
>>> not {"one": 1, "two": 2}
False
"""
