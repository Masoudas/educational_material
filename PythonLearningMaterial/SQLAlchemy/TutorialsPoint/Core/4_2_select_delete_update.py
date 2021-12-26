"""
The same way, we have additional methods in the table object such as:
    -   delete: To delete a record
    -   update: To update an existing record
    -   select: To select records in a table.
"""
from sqlalchemy import MetaData, Table, Column, Integer, String

meta = MetaData()
students = Table(
   'students', meta, 
   Column('id', Integer, primary_key = True), 
   Column('name', String), 
   Column('lastname', String))

students.select().where("id > 5")