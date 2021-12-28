"""
Using SQLAlchemy’s table object, more than one table can be specified in WHERE clause of update() method. The PostgreSQL and Microsoft SQL Server support UPDATE statements that refer to multiple tables. This implements “UPDATE FROM” syntax, which updates one table at a time. However, additional tables can be referenced in an additional “FROM” clause in the WHERE clause directly. The following lines of codes explain the concept of multiple table updates clearly.
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

# Updating two different tables together.
stmt = students.update().\
values({
   students.c.name:'xyz',
   addresses.c.email_add:'abc@xyz.com'
}).\
where(students.c.id == addresses.c.id)