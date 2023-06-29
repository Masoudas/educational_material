"""
A convenient shorthand form for the above “begin once” block is to use the Engine.begin() method at the level of the originating Engine object, rather than performing the two separate steps of Engine.connect() and Connection.begin(); the Engine.begin() method returns a special context manager that internally maintains both the context manager for the Connection as well as the context manager for the Transaction normally returned by the Connection.begin() method:

with engine.begin() as connection:
    connection.execute(some_table.insert(), {"x": 7, "y": "this is some data"})
    connection.execute(
        some_other_table.insert(), {"q": 8, "p": "this is some more data"}
    )

# transaction is committed, and Connection is released to the connection pool

file:///home/masoud/Downloads/sqlalchemy_20/core/connections.html
"""
