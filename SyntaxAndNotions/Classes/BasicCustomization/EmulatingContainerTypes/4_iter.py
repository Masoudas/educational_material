"""
	-	object.__iter__(self)
This method is called when an iterator is required for a container. This method should return a new iterator 
object that can iterate over all the objects in the container. For mappings, it should iterate over the keys 
of the container.

Iterator objects also need to implement this method; they are required to return themselves. For more 
information on iterator objects, see Iterator Types.

	-	object.__reversed__(self)
Called (if present) by the reversed() built-in to implement reverse iteration. It should return a new iterator 
object that iterates over all the objects in the container in reverse order.

If the __reversed__() method is not provided, the reversed() built-in will fall back to using the sequence 
protocol (__len__() and __getitem__()). Objects that support the sequence protocol should only provide 
__reversed__() if they can provide an implementation that is more efficient than the one provided by 
reversed().
"""