"""
Scalar subquerry returns exactly zero or one row and exactly one column (hence, it's a scalar subquerry.)

SQLAlchemy represents the scalar subquery using the ScalarSelect construct, which is part of the ColumnElement expression hierarchy, in contrast to the regular subquery which is represented by the Subquery construct, which is in the FromClause hierarchy.

Scalar subqueries are often, but not necessarily, used with aggregate functions, introduced previously at Aggregate functions with GROUP BY / HAVING. A scalar subquery is indicated explicitly by making use of the Select.scalar_subquery() method as below. It's default string form when stringified by itself renders as an ordinary SELECT statement that is selecting from two tables:

>>> subq = select(func.count(address_table.c.id)).\
...             where(user_table.c.id == address_table.c.user_id).\
...             scalar_subquery()
(SELECT count(address.id) AS count_1
FROM address, user_account
WHERE user_account.id = address.user_id)

The above subq object now falls within the ColumnElement SQL expression hierarchy, in that it may be used like any other column expression:

>>> print(subq == 5)
(SELECT count(address.id) AS count_1
FROM address, user_account
WHERE user_account.id = address.user_id) = :param_1

"""
