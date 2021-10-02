"""
To replace part of the string, we can use the replace method. Note that this method returns a new copy of the 
string.

To count the number of occurances of something, use the count method.
"""

my_str = "This is the string"

print(my_str.replace("This", "THIS"))
print("The original string remains: '", my_str, "'")


my_str += ". Really, This is the This I was This time doing This"
print(my_str.count("This"))