"""
Me: Essentially, row factory determines how a row is converted to a python object.

You can change this attribute to a callable that accepts the cursor and the original row as a tuple and will return the real result row. This way, you can implement more advanced ways of returning results, such as returning an object that can also access columns by name.

If returning a tuple doesn’t suffice and you want name-based access to columns, you should consider setting row_factory to the highly-optimized sqlite3.Row type. Row provides both index-based and case-insensitive name-based access to columns with almost no memory overhead. It will probably be better than your own custom dictionary-based approach or even a db_row based solution.
"""

import sqlite3

def dict_factory(cursor, row):
    d = {}

    for idx, col in enumerate(cursor.description):
        d[col[0]] = row[idx]

    #Me: Or equivalently I guess:
    class obj: 
        a: int
        b: int 

    o = obj()
    o.a = row["a"]; o.b = row["b"]    
    return d

con = sqlite3.connect(":memory:")
con.row_factory = dict_factory
cur = con.cursor()
cur.execute("select 1 as a")
print(cur.fetchone()["a"])

con.close()