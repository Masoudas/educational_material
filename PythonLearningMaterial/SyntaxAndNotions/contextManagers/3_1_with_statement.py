"""
The Python with statement creates a runtime context that allows you to run a group of statements under the control of a context manager. PEP 343 added the with statement to make it possible to factor out standard use cases of the try … finally statement.

Compared to traditional try … finally constructs, the with statement can make your code clearer, safer, and reusable. Many classes in the standard library support the with statement. A classic example of this is open(), which allows you to work with file objects using with.

To write a with statement, you need to use the following general syntax:

with expression as target_var:
    do_something(target_var)

The context manager object results from evaluating the expression after with. In other words, expression must return an object that implements the context management protocol. This protocol consists of two special methods:

    -   .__enter__() is called by the with statement to enter the runtime context.
    -   .__exit__() is called when the execution leaves the with code block.

The as specifier is optional. If you provide a target_var with as, then the return value of calling .__enter__() on the context manager object is bound to that variable.

Here’s how the with statement proceeds when Python runs into it:

    -   Call expression to obtain a context manager.
    -   Store the context manager’s .__enter__() and .__exit__() methods for later use.
    -   Call .__enter__() on the context manager and bind its return value to target_var if provided.
    -   Execute the with code block.
    -   Call .__exit__() on the context manager when the with code block finishes.

In this case, .__enter__(), typically provides the setup code. The with statement is a compound statement that starts a code block, like a conditional statement or a for loop. Inside this code block, you can run several statements. Typically, you use the with code block to manipulate target_var if applicable.
"""
