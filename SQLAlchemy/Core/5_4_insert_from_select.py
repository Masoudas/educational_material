"""
Me: We may combine what we discussed in the previous session, to have an insert that uses a select, directly from the insert function. It's also interesting how we may alter the output of our select statement directly, as the following example demonstrates.

The only thing we need to notice here is how we supply a list to the from_select statement, which contains the column names of our table.
"""
from sqlalchemy import MetaData, select, insert, Integer, Column, Table, String

user_table = Table("address", MetaData(),
                   Column('id', Integer, primary_key=True),
                   Column('name', String, nullable=False)
                   )

address_table = Table("address", MetaData(),
                      Column('id', Integer, primary_key=True),
                      Column('email_address', String, nullable=False)
                      )
# Creating the email address directly from the output string!
select_stmt = select(user_table.c.id, user_table.c.name + "@hotmail.com")

insert(address_table).from_select(["user_id", "email_address"], select_stmt)
