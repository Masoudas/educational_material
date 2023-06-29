"""
The most basic function of the Engine is to provide access to a Connection, which can then invoke SQL statements. To emit a textual statement to the database looks like:

from sqlalchemy import text

with engine.connect() as connection:
    result = connection.execute(text("select username from users"))
    for row in result:
        print("username:", row["username"])

Above, the Engine.connect() method returns a Connection object, and by using it in a Python context manager (e.g. the with: statement) the Connection.close() method is automatically invoked at the end of the block. The Connection, is a proxy object for an actual DBAPI connection. The DBAPI connection is retrieved from the connection pool at the point at which Connection is created.

The object returned is known as CursorResult, which references a DBAPI cursor and provides methods for fetching rows similar to that of the DBAPI cursor. The DBAPI cursor will be closed by the CursorResult when all of its result rows (if any) are exhausted. A CursorResult that returns no rows, such as that of an UPDATE statement (without any returned rows), releases cursor resources immediately upon construction.

When the Connection is closed at the end of the with: block, the referenced DBAPI connection is released to the connection pool. From the perspective of the database itself, the connection pool will not actually “close” the connection assuming the pool has room to store this connection for the next use. When the connection is returned to the pool for re-use, the pooling mechanism issues a rollback() call on the DBAPI connection so that any transactional state or locks are removed (this is known as Reset On Return), and the connection is ready for its next use.
"""
