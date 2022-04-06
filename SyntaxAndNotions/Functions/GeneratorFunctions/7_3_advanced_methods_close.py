"""
The close methods provides a way for us to close a generator function (if for example it has an infinite loop
or recursion.)

Instead of calling .throw(), you use .close() in line 6. The advantage of using .close() is that it raises 
StopIteration, an exception used to signal the end of a finite iterator:
"""