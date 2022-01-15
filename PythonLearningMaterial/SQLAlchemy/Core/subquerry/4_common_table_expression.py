"""
Me: It's called a Common Table Expression because it defines an expression before defining the querry, which then can be used inside the table. For example below, anon_1 is the expression we define (WITH expression_name AS ...), which then use throught the actuall querry starting from the FROM expression. 

Common Table Expression is pretty much like subquerry, and we need only to use the cte function to get it. However, the resulting expression is quite different from the a subquerry. We see that it introduces a WITH ... AS ... statement for us.

>>> subq = select(
...     func.count(address_table.c.id).label("count"),
...     address_table.c.user_id
... ).group_by(address_table.c.user_id).cte()

>>> stmt = select(
...    user_table.c.name,
...    user_table.c.fullname,
...    subq.c.count
... ).join_from(user_table, subq)

WITH anon_1 AS
(SELECT count(address.id) AS count, address.user_id AS user_id
FROM address GROUP BY address.user_id)
 SELECT user_account.name, user_account.fullname, anon_1.count
FROM user_account JOIN anon_1 ON user_account.id = anon_1.user_id
"""
