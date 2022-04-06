"""
Me: We can't modify a row with the insert expression. This is tricky, because if we wanted to modify a row, but instead used insert, it would create a new row, if data is not duplicate.

Question: Can we INSERT a duplicate primary code? Nope. Note that we can insert two records that are different in one column, but a primary key if reinserted does violate the primary key constraint.

The update() function generates a new instance of Update which represents an UPDATE statement in SQL, that will update existing data in a table.

Like the insert() construct, there is a “traditional” form of update(), which emits UPDATE against a single table at a time and does not return any rows. However some backends support an UPDATE statement that may modify multiple tables at once, and the UPDATE statement also supports RETURNING such that columns contained in matched rows may be returned in the result set.

The Update.values() method controls the contents of the SET elements of the UPDATE statement. This is the same method shared by the Insert construct. Parameters can normally be passed using the column names as keyword arguments.

Me: Notice that the where construct determines where we want to update our table.
"""
from sqlalchemy import update
user_table = None

stmt = (
    update(user_table).where(user_table.c.name == 'patrick').
    values(fullname='Patrick the Star')
)
print(stmt)
# UPDATE user_account SET fullname=:fullname WHERE user_account.name = :name_1
