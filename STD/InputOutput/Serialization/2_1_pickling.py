"""
The pickle module implements binary protocols for serializing and de-serializing a Python object structure. 
“Pickling” is the process whereby a Python object hierarchy is converted into a byte stream, and “unpickling” is 
the inverse operation, whereby a byte stream (from a binary file or bytes-like object) is converted back into an 
object hierarchy. 

As opposed to JSON, pickle is a binary file.

To serialize, we simply call the dump function of this class. The load method does the reverse.

The module provides the following consts:
	-	pickle.HIGHEST_PROTOCOL
An integer, the highest protocol version available. This value can be passed as a protocol value to functions 
dump() and dumps() as well as the Pickler constructor. (see page for various protocols. Use protocol 5 with python
5 and higher.)

	-	pickle.DEFAULT_PROTOCOL
An integer, the default protocol version used for pickling. May be less than HIGHEST_PROTOCOL. Currently the default 
protocol is 4, first introduced in Python 3.4 and incompatible with previous versions.

Notice that when dumping the object, we open the file as binary. Also, there should be no unpicklable fields inside
the class, such as file handlers. 

Check out the documentation page of pickle for writing custom handlers.
"""
import pickle

class S:
	def __init__(self):
		self.a = 10

with open("obj", "wb") as f:
	pickle.dump(S(), f)

a = None
with open("obj", "rb") as f:
	a = pickle.load(f)

