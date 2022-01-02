"""
Bundling Parameters with a Statement

The two previous cases illustrate a series of parameters being passed to accompany a SQL statement. For single-parameter statement executions, SQLAlchemy’s use of parameters is in fact more often than not done by bundling the parameters with the statement itself, which is a primary feature of the SQL Expression Language and makes for queries that can be composed naturally while still making use of parameterization in all cases. This concept will be discussed in much more detail in the sections that follow; for a brief preview, the text() construct itself being part of the SQL Expression Language supports this feature by using the TextClause.bindparams() method; this is a generative method that returns a new copy of the SQL construct with additional state added, in this case the parameter values we want to pass along:

>>> stmt = text("SELECT x, y FROM some_table WHERE y > :y ORDER BY x, y").bindparams(y=6)
>>> with engine.connect() as conn:
...     result = conn.execute(stmt)
...     for row in result:
...        print(f"x: {row.x}  y: {row.y}")
BEGIN (implicit)
SELECT x, y FROM some_table WHERE y > ? ORDER BY x, y
[...] (6,)
x: 6  y: 8
x: 9  y: 10
x: 11  y: 12
x: 13  y: 14
ROLLBACK
The interesting thing to note above is that even though we passed only a single argument, stmt, to the Connection.execute() method, the execution of the statement illustrated both the SQL string as well as the separate parameter tuple.
"""
