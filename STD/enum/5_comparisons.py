"""
Enumeration members are compared by identity (using the is operator.)

Comparison against values (like ints) is not allowed.
"""
import enum

class myEnum(enum.Enum):
	VAL1 = 1
	VAL2 = 2

print(myEnum(1) is myEnum.VAL1)

