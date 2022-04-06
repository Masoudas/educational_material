"""
Consider the following two examples of openning a file. If the file is too big and we open all of it at once,
then we'd run out of memory. This can be avoided using a yield keyword as shown below (Me: Yes, of course
we don't open a file like this normally, but we rather loop through it. But the example has a point.)

def csv_reader(file_name):
    file = open(file_name)
    result = file.read().split("\n")
    return result

ctr = 0
for row in csv_reader(file):
	ctr += 1

# The version with yield
def csv_reader(file_name):
    for row in open(file_name, "r"):
        yield row

The second version is a generator function. Similarly, we can use a generator expression just like a list
function. This would lazily read the file (note the surrounding paranthesis):
csv_gen = (row for row in open(file_name))

Notice that:
	-	Using yield will result in a generator object.
	-	Using return will result in the first line of the file only.

"""

