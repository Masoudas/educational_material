"""
To create an enum, we must simply inherit from the Enum class. Enum values are static members of our data system.

Member values can be anything: int, str, etc.. If the exact value is unimportant you may use auto instances and an 
appropriate value will be chosen for you. Care must be taken if you mix auto with other values.

Note that enums have automatic string representations as well. Notice that the name property of each enum value
returns its name.

Note that enums support iteration. Also, notice that (just like Java,) we can use enums as dictionary keys, because
they're hashable.
"""
import enum

class myEnum(enum.Enum):
	VAL1 = enum.auto()
	VAL2 = enum.auto()

print(myEnum.VAL1)
print(repr(myEnum.VAL1))

if type(myEnum.VAL1) == myEnum:
	print(myEnum.VAL1.name, " is my Enum")

for enum_val in myEnum:
	print(enum_val is myEnum.VAL1)	

dictionary = {myEnum.VAL1 : "value 1", myEnum.VAL2 : "value 2"}