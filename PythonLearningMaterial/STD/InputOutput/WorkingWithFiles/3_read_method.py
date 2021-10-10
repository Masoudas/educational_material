"""
To read a file’s contents, call f.read(size), which reads some quantity of data and returns it as a string (in text 
mode) or bytes object (in binary mode). size is an optional numeric argument. When size is omitted or negative, the 
entire contents of the file will be read and returned; it’s your problem if the file is twice as large as your 
machine’s memory. Otherwise, at most size characters (in text mode) or size bytes (in binary mode) are read and 
returned. If the end of the file has been reached, f.read() will return an empty string ('').

Notice also how we read the entire file line by line, using a simple for loop.

At the same time, we can read all the lines of a file in a list using the readlines method as well.

The tell method returns the current position of the curser, and the seek method returns positions the cursor, both
in number of bytes. The seek method has a whence argument, where 0 means from the beginning, 1 from current position
and 2 from end.
"""

with open("InputOutput/WorkingWithFiles/1_open_method.py", "r") as f:
	print(f.read())	# This one reads the entire file

with open("InputOutput/WorkingWithFiles/1_open_method.py", "r") as f:
	n = 0
	for line in f:
		print(f"line {n}: ", line)
		n += 1	

with open("InputOutput/WorkingWithFiles/1_open_method.py", "r") as f:
	lines = f.readlines()	# Returns a list of strings.