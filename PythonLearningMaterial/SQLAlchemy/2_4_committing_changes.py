"""
We just learned that the DBAPI connection is non-autocommitting. What if we want to commit some data? We can alter our above example to create a table and insert some data, and the transaction is then committed using the Connection.commit() method, invoked inside the block where we acquired the Connection object:

# "commit as you go"
>>> with engine.connect() as conn:
...     conn.execute(text("CREATE TABLE some_table (x int, y int)"))
...     conn.execute(
...         text("INSERT INTO some_table (x, y) VALUES (:x, :y)"),
...         [{"x": 1, "y": 1}, {"x": 2, "y": 4}]
...     )
...     conn.commit()

Above, we emitted two SQL statements that are generally transactional, a “CREATE TABLE” statement 1 and an “INSERT” statement that's parameterized. As we want the work we've done to be committed within our block, we invoke the Connection.commit() method which commits the transaction. After we call this method inside the block, we can continue to run more SQL statements and if we choose we may call Connection.commit() again for subsequent statements. SQLAlchemy refers to this style as commit as you go.

There is also another style of committing data, which is that we can declare our “connect” block to be a transaction block up front. For this mode of operation, we use the Engine.begin() method to acquire the connection, rather than the Engine.connect() method. This method will both manage the scope of the Connection and also enclose everything inside of a transaction with COMMIT at the end, assuming a successful block, or ROLLBACK in case of exception raise. This style may be referred towards as begin once.

# "begin once"
>>> with engine.begin() as conn:
...     conn.execute(
...         text("INSERT INTO some_table (x, y) VALUES (:x, :y)"),
...         [{"x": 6, "y": 8}, {"x": 9, "y": 10}]
...     )
# Translation
BEGIN (implicit)
INSERT INTO some_table (x, y) VALUES (?, ?)
[...] ((6, 8), (9, 10))
<sqlalchemy.engine.cursor.CursorResult object at 0x...>
COMMIT

“Begin once” style is often preferred as it is more succinct and indicates the intention of the entire block up front. However, within this tutorial we will normally use “commit as you go” style as it is more flexible for demonstration purposes.

NOTE: You might have noticed the log line “BEGIN (implicit)” at the start of a transaction block. “implicit” here means that SQLAlchemy did not actually send any command to the database; it just considers this to be the start of the DBAPI’s implicit transaction. You can register event hooks to intercept this event, for example.
"""