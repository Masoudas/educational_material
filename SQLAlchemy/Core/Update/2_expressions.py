"""
UPDATE supports all the major SQL forms of UPDATE, including updates against expressions, where we can make use of Column expressions:

>>> stmt = update(user_table).
...     values(fullname="Username: " + user_table.c.name)
... 
>>> print(stmt)
UPDATE user_account SET fullname=(:name_1 || user_account.name)
"""
