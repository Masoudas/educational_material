"""
Use the unique decorator to ensure that enum values are unique.
"""
import enum 

@enum.unique
class myEnum:
	VAL1 = 1
	VAL2 = 2
	# VAL3 = 2 This will throw an error.
