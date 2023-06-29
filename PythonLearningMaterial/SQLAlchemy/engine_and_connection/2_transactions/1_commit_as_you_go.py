"""
The Connection object always emits SQL statements within the context of a transaction block. The first time the Connection.execute() method is called to execute a SQL statement, this transaction is begun automatically, using a behavior known as autobegin. The transaction remains in place for the scope of the Connection object until the Connection.commit() or Connection.rollback() methods are called. Subsequent to the transaction ending, the Connection waits for the Connection.execute() method to be called again, at which point it autobegins again.

Me: Essentially, committing begins once we have a invoke the commit method.
ME: Also note that threre's no begin method. All it takes to create a begin method is to create the connection object
Me: I wonder whether creating multiple connection objects, then closing them, and then finally committing with one of them would save the created transactions. 

This calling style is referred towards as commit as you go

with engine.connect() as connection:
    connection.execute(some_table.insert(), {"x": 7, "y": "this is some data"})
    connection.execute(
        some_other_table.insert(), {"q": 8, "p": "this is some more data"}
    )

    connection.commit()  # commit the transaction
"""
