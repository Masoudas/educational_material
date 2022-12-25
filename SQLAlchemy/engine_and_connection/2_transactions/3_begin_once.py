"""
The Connection object provides a more explicit transaction management style referred towards as begin once. In contrast to “commit as you go”, “begin once” allows the start point of the transaction to be stated explicitly, and allows that the transaction itself may be framed out as a context manager block so that the end of the transaction is instead implicit. To use “begin once”, the Connection.begin() method is used, which returns a Transaction object which represents the DBAPI transaction. This object also supports explicit management via its own Transaction.commit() and Transaction.rollback() methods, but as a preferred practice also supports the context manager interface, where it will commit itself when the block ends normally and emit a rollback if an exception is raised, before propagating the exception outwards. Below illustrates the form of a “begin once” block:

with engine.connect() as connection:
    with connection.begin():
        connection.execute(some_table.insert(), {"x": 7, "y": "this is some data"})
        connection.execute(
            some_other_table.insert(), {"q": 8, "p": "this is some more data"}
        )

    # transaction is committed

"""