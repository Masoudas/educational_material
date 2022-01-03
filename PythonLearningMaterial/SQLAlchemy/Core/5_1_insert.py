"""
When using Core, a SQL INSERT statement is generated using the insert() function - this function generates a new instance of Insert which represents an INSERT statement in SQL, that adds new data into a table.

A simple example of Insert illustrating the target table and the VALUES clause at once.


>>> print(stmt)
INSERT INTO user_account (name, fullname) VALUES (:name, :fullname)

The stringified form is created by producing a Compiled form of the object which includes a database-specific string SQL representation of the statement; we can acquire this object directly using the ClauseElement.compile() method:

>>> compiled = stmt.compile()

Overall, the full transaction has to be committed.

In its simple form below, the INSERT statement does not return any rows, and if only a single row is inserted, it will usually include the ability to return information about column-level default values that were generated during the INSERT of that row, most commonly an integer primary key value. In the above case the first row in a SQLite database will normally return 1 for the first integer primary key value, which we can acquire using the CursorResult.inserted_primary_key accessor

>>> result.inserted_primary_key
(1,)

https://docs.sqlalchemy.org/en/14/tutorial/data_insert.html
"""
from sqlalchemy import insert, Table, MetaData, create_engine

engine = create_engine("", future=True)
user_table = Table("user_table", MetaData())
stmt = insert(user_table).values(
    name='spongebob', fullname="Spongebob Squarepants")

with engine.connect() as conn:
    result = conn.execute(stmt)
    conn.commit()
