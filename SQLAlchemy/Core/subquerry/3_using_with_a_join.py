"""
In the same manner, we can use the subquerry to form a join, as follows. Notice that the ON clause is inferred once again, because we have a foreign key constraint in place.

>>> subq = select(
...     func.count(address_table.c.id).label("count"),
...     address_table.c.user_id
... ).group_by(address_table.c.user_id).subquery())

>>> stmt = select(
...    user_table.c.name,
...    user_table.c.fullname,
...    subq.c.count
... ).join_from(user_table, subq)
SELECT user_account.name, user_account.fullname, anon_1.count
FROM user_account JOIN (SELECT count(address.id) AS count, address.user_id AS user_id
FROM address GROUP BY address.user_id) AS anon_1 ON user_account.id = anon_1.user_id
"""
