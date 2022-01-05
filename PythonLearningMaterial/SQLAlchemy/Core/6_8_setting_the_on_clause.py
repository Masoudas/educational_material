"""
The previous examples of JOIN illustrated that the Select construct can join between two tables and produce the ON clause automatically. This occurs in those examples because the user_table and address_table Table objects include a single ForeignKeyConstraint definition which is used to form this ON clause.

If the left and right targets of the join do not have such a constraint, or there are multiple constraints in place, we need to specify the ON clause directly. Both Select.join() and Select.join_from() accept an additional argument for the ON clause, which is stated using the same SQL Expression mechanics as we saw about in The WHERE clause:

>>> print(
...     select(address_table.c.email_address).
...     select_from(user_table).
...     join(address_table, user_table.c.id == address_table.c.user_id)
... )

SELECT address.email_address
FROM user_account JOIN address ON user_account.id = address.user_id
"""