"""
open() returns a file object, and is most commonly used with two arguments: open(filename, mode).

f = open('workfile', 'w')

The first argument is a string containing the filename. The second argument is another string containing a few 
characters describing the way in which the file will be used. mode can be 'r' when the file will only be read, 'w' 
for only writing (an existing file with the same name will be erased), and 'a' opens the file for appending; any 
data written to the file is automatically added to the end. 'r+' opens the file for both reading and writing. 
The mode argument is optional; 'r' will be assumed if it’s omitted.

Normally, files are opened in text mode, that means, you read and write strings from and to the file, which are 
encoded in a specific encoding. If encoding is not specified, the default is platform dependent (see open()). 
'b' appended to the mode opens the file in binary mode: now the data is read and written in the form of bytes 
objects. This mode should be used for all files that don’t contain text.

In text mode, the default when reading is to convert platform-specific line endings (\n on Unix, \r\n on Windows) 
to just \n. When writing in text mode, the default is to convert occurrences of \n back to platform-specific line 
endings. This behind-the-scenes modification to file data is fine for text files, but will corrupt binary data 
like that in JPEG or EXE files. Be very careful to use binary mode when reading and writing such files.
"""