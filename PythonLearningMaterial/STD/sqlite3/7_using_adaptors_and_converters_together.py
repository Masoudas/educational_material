"""
As such, we may use adaptors and converters together to convert python types to sql types and back. The way we do this is through use of adaptors and converters.

A note on the converter: Converter functions always get called with a bytes object, no matter under which data type you sent the value to SQLite.

Notice that when defining the sql table, we pass in a point Object. 

The detect_type in the connect is important. Also, notice the fetch querries.
"""

import sqlite3

class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y

    def __repr__(self):
        return "(%f;%f)" % (self.x, self.y)

def adapt_point(point):
    # Equivalently: f"float{point.x};float{point.y}".encode("ascii")
    return ("%f;%f" % (point.x, point.y)).encode('ascii') 

def convert_point(s: str):
    """ WE get a byte string here""" 
    x, y = list(map(float, s.split(b";")))
    return Point(x, y)

# Register the adapter
sqlite3.register_adapter(Point, adapt_point)

# Register the converter
sqlite3.register_converter("point", convert_point)

p = Point(4.0, -3.2)

#########################
# 1) Using declared types
con = sqlite3.connect(":memory:", detect_types=sqlite3.PARSE_DECLTYPES)
cur = con.cursor()
cur.execute("create table test(p point)")

cur.execute("insert into test(p) values (?)", (p,))
cur.execute("select p from test")
print("with declared types:", cur.fetchone()[0])
cur.close()
con.close()

#######################
# 1) Using column names
con = sqlite3.connect(":memory:", detect_types=sqlite3.PARSE_COLNAMES)
cur = con.cursor()
cur.execute("create table test(p)")

cur.execute("insert into test(p) values (?)", (p,))
cur.execute('select p as "p [point]" from test')
print("with column names:", cur.fetchone()[0])
cur.close()
con.close()