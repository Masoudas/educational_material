"""
Once a connection to the database file is created, create tables inside of that file, and insert rows into it by creating a cursor.
"""
import sqlite3

con = sqlite3.connect(":memory:")

cur = con.cursor()

cur.execute("""CREATE TABLE stocks
               (date text, trans text, symbol text, qty real, price real)""")   # Execution of a SQL querry. Recall that another method is to create a myDB.db file, and then pass its content to this string. Or, we may use the executescript function.

cur.execute("INSERT INTO stocks VALUES ('2006-01-05','BUY','RHAT',100,35.14)")
cur.execute("INSERT INTO stocks VALUES ('2001-01-05','SELL','RHT',10,15.14)")
cur.execute("INSERT INTO stocks VALUES ('2012-11-12','BUY','RHT',400,66)")

# Save (commit) the changes
con.commit()    # Notice that we commit with the connection, not with the cursor.

for row in cur.execute("SELECT * FROM stocks ORDER BY price"):
    print(row)

# We can also close the connection if we are done with it.
# Just be sure any changes have been committed or they will be lost.
con.close()