"""
The try … except statement has an optional else clause, which, when present, must follow all except clauses. It is 
useful for code that must be executed if the try clause does not raise an exception. For example:

Me: Note that the else clause is executed if no exception is raised, not if no exception was caught.
"""

import sys

try:
	pass
except BaseException:
	pass 
else:
	print("Inside else statement, because no exception was raised.")