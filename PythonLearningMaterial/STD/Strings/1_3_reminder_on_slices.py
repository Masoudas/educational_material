"""
Recall that slices in python are exclusive. As such, the last index is never chosen by the slice.

Recall also that to invert a string, we may use negative slicing (and I tend to forget to indicate that the steps
should be -1, and I always put +1)
"""

string = "This is my string"
sub_str = string[0:4:2]	# Even indexes from zero, excluding 4
print(sub_str)

reverse_str = string[-1::-1]	# Or more simply [::-1]
print(reverse_str)
