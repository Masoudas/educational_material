"""
By autocommit, we imply isolation level AUTOCOMMIT. For example, we may set the level as follows:
with engine.connect() as connection:
    connection.execution_options(isolation_level="AUTOCOMMIT")
    connection.execute("<statement>")
    connection.execute("<statement>")

Above illustrates normal usage of “DBAPI autocommit” mode. There is no need to make use of methods such as Connection.begin() or Connection.commit(), as all statements are committed to the database immediately. When the block ends, the Connection object will revert the “autocommit” isolation level, and the DBAPI connection is released to the connection pool where the DBAPI connection.rollback() method will normally be invoked, but as the above statements were already committed, this rollback has no change on the state of the database.

It is important to note that “autocommit” mode persists even when the Connection.begin() method is called; the DBAPI will not emit any BEGIN to the database, nor will it emit COMMIT when Connection.commit() is called. This usage is also not an error scenario, as it is expected that the “autocommit” isolation level may be applied to code that otherwise was written assuming a transactional context; the “isolation level” is, after all, a configurational detail of the transaction itself just like any other isolation level.
"""