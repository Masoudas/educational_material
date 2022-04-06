"""
It's possible to access the values of an enumeration with values (rather than their names,) as the following example
demonstrates.
"""

import enum

class myEnum(enum.Enum):
	VAL1 = 1
	VAL2 = 2

print(myEnum(1) is myEnum.VAL1)		# We compare instances with enums