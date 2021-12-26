"""
So far, we talked how to define expressions, but not how to execute them.

Executing expressions is in fact quite simple. We need to get the connection object from the engine (just like sqlite3,) and then pass in our expression, and then execute and commit it.

A connection object represents an actively checked out DBAPI connection resource.
"""
from sqlalchemy import create_engine
from sqlalchemy import Table, Column, Integer, String, MetaData

engine = create_engine("sqlite:///myDB")    # No user, no password, no nothing!

conn = engine.connect()

meta = MetaData()
students = Table(
   'students', meta, 
   Column('id', Integer, primary_key = True), 
   Column('name', String), 
   Column('lastname', String))

# Creating the table.
meta.create_all(engine)

# Insert values
insert = students.insert().values(id=123, name="Masoud", lastname="Sharbaf")
conn.execute(insert)