"""
Aside from normal group by, an important technique, in particular on some database backends, is the ability to ORDER BY or GROUP BY an expression that is already stated in the columns clause, without re-stating the expression in the ORDER BY or GROUP BY clause and instead using the column name or labeled name from the COLUMNS clause. This form is available by passing the string text of the name to the Select.order_by() or Select.group_by() method. The text passed is not rendered directly; instead, the name given to an expression in the columns clause and rendered as that expression name in context, raising an error if no match is found. The unary modifiers asc() and desc() may also be used in this form:

Me: In this example, we count the user ids, but then again, we label the counts as num_addresses. Bu at the same time, to order the table, we actually order by the new label we defined for the counts. Notice that with group by, we always need new labels, because we're generating new columns.

>>> from sqlalchemy import func, desc
>>> stmt = select(
...         Address.user_id,
...         func.count(Address.id).label('num_addresses')).\
...         group_by("user_id").order_by("user_id", desc("num_addresses"))
>>> print(stmt)
SELECT address.user_id, count(address.id) AS num_addresses
FROM address GROUP BY address.user_id ORDER BY address.user_id, num_addresses DESC
"""
