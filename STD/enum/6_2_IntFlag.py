"""
Don't use this stupid thing!

The next variation of Enum provided, IntFlag, is also based on int. The difference being IntFlag members can be 
combined using the bitwise operators (&, |, ^, ~) and the result is still an IntFlag member. However, as the name 
implies, IntFlag members also subclass int and can be used wherever an int is used. Any operation on an IntFlag 
member besides the bit-wise operations will lose the IntFlag membership.

Me: Note that the object created as a result of Oring two values is a bizarre VAL1 | VAL2, but it's the same idea
as a C++ bitfield. 1 | 2 = 3 for example
"""
import enum

class myEnum(enum.IntFlag):
	VAL1 = 1
	VAL2 = 2
	VAL3 = 3

ored = myEnum.VAL1 | myEnum.VAL2 
print(myEnum.VAL1 in ored)	# True. because, well, 1 is in 3!!!!
print(myEnum.VAL3 in ored)	# True, because, well, 3 is in 3!!!!
print(myEnum.VAL2 in ored)	# True, because, well, 2 is in 3!!!!