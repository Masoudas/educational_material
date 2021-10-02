"""
We can justify a string from left or right (default char is space). The justify char is added to the string.
Left justify add chars to the right, and right justify adds to left.

This way, we can make sure that the string is streched to a particular position to left or right.
"""

left_just = "Left justify"
print(left_just.ljust(18, '$'))

right_just = "Right justify"
print(right_just.rjust(42))
