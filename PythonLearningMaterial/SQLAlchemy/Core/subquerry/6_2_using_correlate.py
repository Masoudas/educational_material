"""
Simple correlated subqueries will usually do the right thing that’s desired. However, in the case where the correlation is ambiguous, SQLAlchemy will let us know that more clarity is needed:

Me: The problem with the select statement is that it's not clear we want to correlate the subquerry with which table

>>> subq = select(func.count(address_table.c.id)).\
...             where(user_table.c.id == address_table.c.user_id).\
...             scalar_subquery()

>>> stmt = select(
...     user_table.c.name,
...     address_table.c.email_address,
...     subq.label("address_count")
... ).\
... join_from(user_table, address_table).\
... order_by(user_table.c.id, address_table.c.id)
>>> print(stmt)
Traceback (most recent call last):

To specify that the user_table is the one we seek to correlate we specify this using the ScalarSelect.correlate() or ScalarSelect.correlate_except() methods:

>>> subq = select(func.count(address_table.c.id)).\
...             where(user_table.c.id == address_table.c.user_id).\
...             scalar_subquery().correlate(user_table)

Now, we can use this subquerry as follows:
>>> with engine.connect() as conn:
...     result = conn.execute(
...         select(
...             user_table.c.name,
...             address_table.c.email_address,
...             subq.label("address_count")
...         ).
...         join_from(user_table, address_table).
...         order_by(user_table.c.id, address_table.c.id)
...     )
...     print(result.all())
BEGIN (implicit)
SELECT user_account.name, address.email_address, (SELECT count(address.id) AS count_1
FROM address
WHERE user_account.id = address.user_id) AS address_count
FROM user_account JOIN address ON user_account.id = address.user_id ORDER BY user_account.id, address.id
[...] ()
"""
