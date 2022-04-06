"""
You can provide the same functionality by implementing both the .__enter__() and the .__exit__() special methods in your class-based context managers. You can also create custom function-based context managers using the contextlib.contextmanager decorator from the standard library and an appropriately coded generator function.

Here are the methods to add:
    Method	                                Description
.__enter__(self)	                This method handles the setup logic and is called when entering 
                                    a new with context. Its return value is bound to the with target variable.
.__exit__(self, exc_type, exc_value, exc_tb)	This method handles the teardown logic and is
                                                called when the flow of execution leaves the with context. If an exception occurs, then exc_type, exc_value, and exc_tb hold the exception type, value, and traceback information, respectively.

When the with statement executes, it calls .__enter__() on the context manager object to signal that you’re entering into a new runtime context. If you provide a target variable with the as specifier, then the return value of .__enter__() is assigned to that variable.

When the flow of execution leaves the context, .__exit__() is called. If no exception occurs in the with code block, then the three last arguments to .__exit__() are set to None. Otherwise, they hold the type, value, and traceback associated with the exception at hand.

If the .__exit__() method returns True, then any exception that occurs in the with block is swallowed and the execution continues at the next statement after with. If .__exit__() returns False, then exceptions are propagated out of the context. This is also the default behavior when the method doesn’t return anything explicitly. You can take advantage of this feature to encapsulate exception handling inside the context manager.
"""