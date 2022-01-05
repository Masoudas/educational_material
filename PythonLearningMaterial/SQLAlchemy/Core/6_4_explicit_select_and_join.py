"""
If in the select statement we put the name of two different tables or columns, then those two are joined together. 

We may also use the join method to actually easily join the two tables together, as the following example demonstrates.

The two methods of join:
    -   join_from: Allows us to indicate both the left and the right side of join (This does not seem to be there now!).
    -   join: Only indicate the right side, and the left is inferred. It also has options for full, outer, and inner join

NOTE: Notice that we're not passing any ON clauses here. Why? Because both tables have a ForeignKey definition in their tables (which I did not put here because I was lazy.) As such, the function itself figures out this relationship and acts accordingly.

We also have the option to add elements to the FROM clause explicitly, if it is not inferred the way we want from the columns clause. We use the Select.select_from() method to achieve this, as below where we establish user_table as the first element in the FROM clause and Select.join() to establish address_table as the second:

>>> print(
...     select(address_table.c.email_address).
...     select_from(user_table).join(address_table)
... )
SELECT address.email_address
FROM user_account JOIN address ON user_account.id = address.user_id
"""
from sqlalchemy import select, create_engine, MetaData, Table

engine = create_engine("", future=True)
user_table = Table("user_table", MetaData())
address_table = Table("address_table", MetaData())

print(select(user_table.c.name, address_table.c.email_address))
# SELECT user_account.name, address.email_address
# FROM user_account, address

select(user_table.c.name, address_table.c.email_address).join_from(
    user_table, address_table)
select(user_table.c.name, address_table.c.email_address).join(user_table)
# SELECT user_account.name, address.email_address
# FROM user_account JOIN address ON user_account.id = address.user_id
