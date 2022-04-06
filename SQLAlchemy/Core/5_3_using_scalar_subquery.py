"""
Me: So, there's a cool way we can combine select and insert together, to select from one table and insert into another. Consider we have a user_table and an address_table, where the first one has (id, name) and the second one has (id, email_address), where id is a primary key. The point is that we want both of these two tables to put the email_address and the name in the same incrementing id, while at the same time, we supply the (name, email_address) pair. So, how do we do this with an actual querry?

A querry would look something like this:
INSERT INTO address VALUES (user.id, email_address) (SELECT user.id FROM user 
WHERE user.name == ?,  ?)

What are the two question marks? Well, those are the values that are passed. Essentially, we seek the location inside the user table where the name exists, to find the id. Then, we supply it as the first parameter to be set. The second ? is the email address passed to us by the user (email address,) which we simply put also. The point is that the pair (user.id, email_address) is the pair we want to insert and the second one with question marks is the one passed by the user. The where clause uses that passed parameter (that is, name) to find the user we seek. So essentially, we're combining two querries here. Using scalar_subquery is the way to move forward with this.

Continuing from the docs:
A scalar subquery is constructed, making use of the select() construct introduced in the next section, and the parameters used in the subquery are set up using an explicit bound parameter name, established using the bindparam() construct (Me: This allows to bind parameters of different names).

This is some slightly deeper alchemy just so that we can add related rows without fetching the primary key identifiers from the user_table operation into the application. Most Alchemists will simply use the ORM which takes care of things like this for us.
"""

from sqlalchemy import select, bindparam, MetaData, Table, Column, Integer, ForeignKey, String, insert
from sqlalchemy.engine import create_engine
metadata_obj = MetaData()

user_table = Table(
    "address",
    metadata_obj,
    Column('id', Integer, primary_key=True),
    Column('name', String, nullable=False)
)

address_table = Table(
    "address",
    metadata_obj,
    Column('id', Integer, primary_key=True),
    Column('email_address', String, nullable=False)
)

scalar_subq = (
    select(user_table.c.id).
    where(user_table.c.name == bindparam('username')).
    scalar_subquery()  # What is this?
)

engine = create_engine("")
with engine.connect() as conn:
    result = conn.execute(
        insert(address_table).values(user_id=scalar_subq),
        [
            {"username": 'spongebob', "email_address": "spongebob@sqlalchemy.org"},
            {"username": 'sandy', "email_address": "sandy@sqlalchemy.org"},
            {"username": 'sandy', "email_address": "sandy@squirrelpower.org"},
        ]
    )
    conn.commit()
