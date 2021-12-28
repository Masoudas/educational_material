"""
We may define aliases (table Alias) using the alias function of SQL.

Notice then how we use direct access of column name (st.c.<id>) with the alias.
The same can of course be done with the table itself.
"""
from sqlalchemy.sql import alias
from sqlalchemy import select, Table, Column, String, Integer, MetaData

students = Table(
   'students', MetaData(), 
   Column('id', Integer, primary_key = True), 
   Column('name', String), 
   Column('lastname', String), 
)

st = students.alias("a")
s = select([st]).where(st.c.id > 2)
students.select().where(students.columns.get['id'] > 2) # This is me!