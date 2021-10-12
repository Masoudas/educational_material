"""
The first variation of Enum that is provided is also a subclass of int. Members of an IntEnum can be compared to 
integers; by extension, integer enumerations of different types can also be compared to each other.

These, however, can't be compared to standard Enums.
"""

from enum import IntEnum
class Shape(IntEnum):
    CIRCLE = 1
    SQUARE = 2

class Request(IntEnum):
    POST = 1
    GET = 2

Shape == 1
Shape.CIRCLE == 1
Shape.CIRCLE == Request.POST