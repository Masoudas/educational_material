"""
OUTER and FULL join
Both the Select.join() and Select.join_from() methods accept keyword arguments Select.join.isouter and Select.join.full which will render LEFT OUTER JOIN and FULL OUTER JOIN, respectively:

>>> print(
...     select(user_table).join(address_table, isouter=True)
... )
SELECT user_account.id, user_account.name, user_account.fullname
FROM user_account LEFT OUTER JOIN address ON user_account.id = address.user_id

>>> print(
...     select(user_table).join(address_table, full=True)
... )
SELECT user_account.id, user_account.name, user_account.fullname
FROM user_account FULL OUTER JOIN address ON user_account.id = address.user_id

There is also a method Select.outerjoin() that is equivalent to using .join(..., isouter=True).

Tip:
SQL also has a “RIGHT OUTER JOIN”. SQLAlchemy doesn’t render this directly; instead, reverse the order of the tables and use “LEFT OUTER JOIN”.

"""
