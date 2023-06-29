"""
Recall from Engine Configuration that an Engine is created via the create_engine() call:

>>> engine = create_engine("mysql+mysqldb://scott:tiger@localhost/test")

The typical usage of create_engine() is once per particular database URL, held globally for the lifetime of a single application process. A single Engine manages many individual DBAPI connections on behalf of the process and is intended to be called upon in a concurrent fashion. The Engine is not synonymous to the DBAPI connect() function, which represents just one connection resource - the Engine is most efficient when created just once at the module level of an application, not per-object or per-function call.

Me: Essentially, the singleton pattern I've come up with, or a module that has the parameter `engine` as a global variable is very useful.

Tip:
When using an Engine with multiple Python processes, such as when using os.fork or Python multiprocessing, it's important that the engine is initialized per process. 
"""
