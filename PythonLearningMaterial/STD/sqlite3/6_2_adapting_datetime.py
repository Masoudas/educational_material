"""
A simple way of adding date time in sql is to directly convert it to string (using the __str__ method.)

The sqlite3 module has two default adapters for Python’s built-in datetime.date and datetime.datetime types. Now let’s suppose we want to store datetime.datetime objects not in ISO representation, but as a Unix timestamp.

Notice that we register adaptors for the entire sqlite module
"""
from sqlite3 import connect, register_adapter
from time import mktime
from datetime import date, datetime

def adapt_datetime(ts: date):
    return mktime(ts.timetuple())

register_adapter(datetime, adapt_datetime)

con = connect(":memory:")
cur = con.cursor()

now = datetime.now()
cur.execute("select ?", (now,))
print(cur.fetchone()[0])

con.close()