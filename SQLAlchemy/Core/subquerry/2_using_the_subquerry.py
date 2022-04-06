"""
The subquerry object now behaves like any other from object. As such, we can use it in place of a from statement. The interesting point, however, is that we can use this subquerry object to refer both to the columns of the original table, and the subquerry result itself. Consider the following:

>>> subq = select(
...     func.count(address_table.c.id).label("count"),
...     address_table.c.user_id
... ).group_by(address_table.c.user_id).subquery())

We can use it to refer to address_table elements as well. We see that the querry is formed properly for us:

>>> querry = select(subq.user_id, subq.count)
SELECT anon_1.user_id, anon_1.count
FROM (SELECT count(address.id) AS count, address.user_id AS user_id
FROM address GROUP BY address.user_id) AS anon_1
"""
