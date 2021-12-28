"""
It's not necessary to construct a meta object for the table every time. We can use the select function directly, and then define our query. In this case, we must pass the string with a text object.
"""
from sqlalchemy import select
from sqlalchemy.sql.sqltypes import Text

select([Text("table.c1, table.c2 FROM table")]) # To be passed to a connection object.

select([Text("* FROM table")]) # To be passed to a connection object.