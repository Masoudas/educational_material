"""
Notice that an empty select call implies selecting all columns (and records) of a table.

all_rows = table.select()
conn.execute(all_rows)

We may as well fetch one.
all_rows.fetchone()

We may as well (using a generator I guess) iterate over all the rows of the table:
for row in all_rows:
    print(row)
"""
from sqlalchemy import create_engine, MetaData, Table, Column, Integer, String

engine = create_engine('sqlite:///college.db', echo = True)
meta = MetaData()

students = Table(
   'students', meta, 
   Column('id', Integer, primary_key = True), 
   Column('name', String), 
   Column('lastname', String), 
)

conn = engine.connect()
s = students.select()
result = conn.execute(s)

for row in result:
   print (row)