"""
Me: The goal is to use a querry inside another querry. When a querry forms a table, we can select from it once again. So, subquerries are used in FROM statements.

A subquery in SQL is a SELECT statement that is rendered within parenthesis and placed within the context of an enclosing statement, typically a SELECT statement but not necessarily.

This section will cover a so-called “non-scalar” subquery, which is typically placed in the FROM clause of an enclosing SELECT. We will also cover the Common Table Expression or CTE, which is used in a similar way as a subquery, but includes additional features.

We can construct a Subquery that will select an aggregate count of rows from the address table

>>> subq = select(
...     func.count(address_table.c.id).label("count"),
...     address_table.c.user_id
... ).group_by(address_table.c.user_id).subquery()
SELECT count(address.id) AS count, address.user_id
FROM address GROUP BY address.user_id
"""
