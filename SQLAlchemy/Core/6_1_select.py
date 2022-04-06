"""
For both Core and ORM, the select() function generates a Select construct which is used for all SELECT queries. Passed to methods like Connection.execute() in Core and Session.execute() in ORM, a SELECT statement is emitted in the current transaction and the result rows available via the returned Result object.

Selecting individual columns: With the select function, we can pass the column names. With the table.select, however, we need to use the with_only_columns method. Note that with select function, we needn't then pass the table name.
"""
from sqlalchemy import insert, Table, MetaData, create_engine, select

engine = create_engine("", future=True)
user_table = Table("user_table", MetaData())

select_stmt = user_table.select().with_only_columns(
    user_table.c.name, user_table.c.email)

# Notice that we're not passing the table name here.
select_stmt2 = select(user_table.c.name)
