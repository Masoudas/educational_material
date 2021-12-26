"""
An object of MetaData class from SQLAlchemy Metadata is a collection of Table objects and their associated schema constructs.

The SQL Expression Language constructs its expressions against table columns. SQLAlchemy Column object represents a column in a database table which is in turn represented by a Tableobject. Metadata contains definitions of tables and associated objects such as index, view, triggers, etc.

SQLAlchemy matches Python data to the best possible generic column data types defined in it. Some of the generic data types are:

    -   BigInteger  
    -   Boolean
    -   Date
    -   DateTime
    -   Float
    -   Integer
    -   Numeric
    -   SmallInteger
    -   String
    -   Text
    -   Time

Imagine, we want to create the following table. Here's the constructed table:
CREATE TABLE students (
   id INTEGER NOT NULL,
   name VARCHAR,
   lastname VARCHAR,
   PRIMARY KEY (id)
)

"""
from sqlalchemy import create_engine, MetaData
from sqlalchemy import Table, Column, Integer, String

engine = create_engine('sqlite:///college.db', echo = True)

meta = MetaData()

students = Table(
   'students', meta, 
   Column('id', Integer, primary_key = True), 
   Column('name', String), 
   Column('lastname', String))

meta.create_all(engine)


