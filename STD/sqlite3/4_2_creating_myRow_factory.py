"""
In this example, I try to create my own row factory.
"""
from sqlite3 import Cursor, Row, connect
class my_row:
    name: str
    surname: str

    
def my_row_factory(cursor: Cursor, row: Row):
    r = my_row()

    # This is assuming we always know the name of the tables
    #r.name = row[0]
    #r.surname = row[1]

    # But we can set from ORM
    r.__dict__[cursor.description[0][0]] = row[0]
    r.__dict__[cursor.description[1][0]] = row[1]

    return r

con = connect(":memory:")
con.row_factory = my_row_factory    # Setting the row factory

cur = con.cursor()

cur.execute("CREATE TABLE stock\
        (name text, surname text)")

vals = [
    ("Masoud", "AS"),
    ("Navid", "Yektay"),
    ("Jafar", "Babash")
]
cur.executemany("INSERT INTO stock VALUES (?,?)", vals)

con.commit()

# We must always execute a query before fetching
cur.execute("Select * from stock")
row1: my_row = cur.fetchone()

print(row1.name, row1.surname)

