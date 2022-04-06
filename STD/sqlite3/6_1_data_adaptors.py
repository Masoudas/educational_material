"""
SQL has methods for adapting a class to python input type. As such, we needn't create insertion strings, and we directly supply the class to SQL.

The first method is to add a __conform__ method to the class. Imagine we have a class as follows:

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y

Note that we return a string from the protocol function.
"""

import sqlite3

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y

    def __conform__(self, protocol):
        if protocol is sqlite3.PrepareProtocol:
            return "%f;%f" % (self.x, self.y)

con = sqlite3.connect(":memory:")
cur = con.cursor()

# I think all of this creates a table and inserts in it and then reads from it.
p = Point(4.0, -3.2)
cur.execute("select ?", (p,))
print(cur.fetchone()[0])

# Notice that in my execution, I only define p, and not:
# (p1 float, p2 float)
cur.execute("CREATE TABLE points (p)")
cur.execute("INSERT INTO points VALUES (?)", (p,))
cur.execute("SELECT * FROM points")
print(cur.fetchone()[0])    # This is an string righ now!

con.close()
