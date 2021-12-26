"""
SQL expressions are constructed using corresponding methods relative to target table object. For example, the INSERT statement is created by executing insert() method as follows:
ins = students.insert()

The result of above method is an insert object that can be verified by using str() function. The below code inserts details like student id, name, lastname.

'INSERT INTO students (id, name, lastname) VALUES (:id, :name, :lastname)'

To insert parameters into the table, use the values function. Then, we can see the compiled expression using the compile method.

We may also insert multiple records.

"""
from sqlalchemy import MetaData, Table, Column, Integer, String

meta = MetaData()
students = Table(
   'students', meta, 
   Column('id', Integer, primary_key = True), 
   Column('name', String), 
   Column('lastname', String))

ins = students.insert()
print(str(ins))


print(ins.values(name="Masoud", id=212, lastname="Sharbaf").compile().params)

students.insert(), [
   {'name':'Rajiv', 'lastname' : 'Khanna'},
   {'name':'Komal','lastname' : 'Bhandari'},
   {'name':'Abdul','lastname' : 'Sattar'},
   {'name':'Priya','lastname' : 'Rajhans'},
]