"""
For an individual Connection object that’s acquired from Engine.connect(), the isolation level can be set for the duration of that Connection object using the Connection.execution_options() method. The parameter is known as Connection.execution_options.isolation_level and the values are strings which are typically a subset of the following names:

# possible values for Connection.execution_options(isolation_level="<value>")
    -   "AUTOCOMMIT"
    -   "READ COMMITTED"
    -   "READ UNCOMMITTED"
    -   "REPEATABLE READ"
    -   "SERIALIZABLE"

NOTE: Not every DBAPI supports every value; if an unsupported value is used for a certain backend, an error is raised.

Below, we set the isolation level to repeatable read:
>>> with engine.connect().execution_options(
    isolation_level="REPEATABLE READ"
    ) as connection:
        with connection.begin():
            connection.execute("<statement>")

NOTE: The return value of the Connection.execution_options() method is the same Connection object upon which the method was called, meaning, it modifies the state of the Connection object in place. This is a new behavior as of SQLAlchemy 2.0. This behavior does not apply to the              Engine.execution_options() method; that method still returns a copy of the Engine and as described below may be used to construct multiple Engine objects with different execution options, which nonetheless share the same dialect and connection pool.
"""
