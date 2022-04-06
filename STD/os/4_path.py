"""
path is the module for working with paths.
	-	join: Join paths.
	-	basename: For grabbing the file name (for even non-existent paths.)
	-	dirname: For grabbing the dir name.
	-	exists: Check whether a path exists.
	-	isdir: Whether something is a directory
	-	isfile
	-	split: Splits the root of the file and its extension.
"""

from os import path, getcwd

path.join(getcwd(), "test.txt")