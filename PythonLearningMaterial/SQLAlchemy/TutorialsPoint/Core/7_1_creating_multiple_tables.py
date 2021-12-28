"""
Notice that multiple tables can be made together, using the same meta class.
"""
from sqlalchemy import MetaData, create_engine, Table, Column, Integer, String, ForeignKey

engine = create_engine("")

meta = MetaData()

students = Table(
   'students', meta, 
   Column('id', Integer, primary_key = True), 
   Column('name', String), 
   Column('lastname', String), 
)

addresses = Table(
   'addresses', meta, 
   Column('id', Integer, primary_key = True), 
   Column('st_id', Integer, ForeignKey('students.id')), 
   Column('postal_add', String), 
   Column('email_add', String))

meta.create_all(engine)
