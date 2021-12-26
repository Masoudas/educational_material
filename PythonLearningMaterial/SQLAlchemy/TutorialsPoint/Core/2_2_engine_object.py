"""
The engine object that is returned has the following methods:

1   connect()
Returns connection object

2   execute()
Executes a SQL statement construct

3   begin()
Returns a context manager delivering a Connection with a Transaction established. Upon successful operation, the Transaction is committed, else it is rolled back.

4   dispose()
Disposes of the connection pool used by the Engine

5   driver()
Driver name of the Dialect in use by the Engine

6   table_names()
Returns a list of all table names available in the database

7   transaction()
Executes the given function within a transaction boundary
"""