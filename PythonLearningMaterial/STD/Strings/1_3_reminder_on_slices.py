"""
Recall that slices in python are exclusive. As such, the last index is never chosen by the slice.

Recall also that to invert a string, we may use negative slicing (and I tend to forget to indicate that the steps
should be -1, and I always put +1)

Me: Note that assignment to slices is not possible. Why? Because string immutability is violated as such, and
we need to create a new string in any case!
Also recall that with negative indexes, the last index is always -1, and the first one is exactly -len(str)
"""

string = "This is my string"
sub_str = string[0:4:2]	# Even indexes from zero, excluding 4
print(sub_str)

reverse_str = string[-1::-1]	# Or more simply [::-1]
print(reverse_str)

# Assigning to string slices is impossible! We must create a new string
# string[:4] = "T", "h", "a", "t"
string2 = "That" + string[4:]
print(string2)