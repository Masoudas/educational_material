"""
Notice that these are linux like.

	-	getcwd: Retrieves the current working directory (on which the program started functioning)
	-	chdir:	For changing dir during execution of the program.
	-	listdir: Lists the files in the current folder, as a list of strings
	-	mkdir: For making dir (non-recursively)
	-	mkdirs:	For making dirs
	-	rmdir: Remove one folder
	-	removedirs: Remove folders recusively (don't use this, unless with caution.)
	-	rename: To rename a file or a folder.
	-	walk: Gives a generator for walking the path.
"""
from os import walk 

for dirpath, dirname, filename in walk("."):
	print(dirpath, dirname, filename)
