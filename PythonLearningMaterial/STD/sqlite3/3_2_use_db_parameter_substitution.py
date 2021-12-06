"""
Instead, use the DB-API’s parameter substitution. To insert a variable into a query string, use a placeholder in the string, and substitute the actual values into the query by providing them as a tuple of values to the second argument of the cursor’s execute() method. An SQL statement may use one of two kinds of placeholders: question marks (qmark style) or named placeholders (named style). For the qmark style, parameters must be a sequence. For the named style, it can be either a sequence or dict instance. The length of the sequence must match the number of placeholders, or a ProgrammingError is raised. If a dict is given, it must contain keys for all named parameters. Any extra items are ignored. Here’s an example of both styles:

Notice the use of execute many, through which we can substitute many values.
"""

import sqlite3

con = sqlite3.connect(":memory:")
cur = con.cursor()
cur.execute("create table lang (name, first_appeared)")

# This is the qmark style:
cur.execute("insert into lang values (?, ?)", ("C", 1972))

# The qmark style used with executemany():
lang_list = [
    ("Fortran", 1957),
    ("Python", 1991),
    ("Go", 2009),
]
cur.executemany("insert into lang values (?, ?)", lang_list)

# And this is the named style:
cur.execute("select * from lang where first_appeared=:year", {"year": 1972})
print(cur.fetchall())

con.close()