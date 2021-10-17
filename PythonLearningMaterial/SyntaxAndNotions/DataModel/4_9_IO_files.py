"""
A file object represents an open file. Various shortcuts are available to create file objects: the open() built-in 
function, and also os.popen(), os.fdopen(), and the makefile() method of socket objects (and perhaps by other 
functions or methods provided by extension modules).

The objects sys.stdin, sys.stdout and sys.stderr are initialized to file objects corresponding to the interpreter's 
standard input, output and error streams; they are all open in text mode and therefore follow the interface defined 
by the io.TextIOBase abstract class.
"""
import sys 
import logging

logging.basicConfig(stream=sys.stderr)	# Notice that stderr as such is a stream, and not a file.
logging.error("Logging to stderror")