"""
Often I wonder, how can we run multiple select statements together? The answer lies in using bindparams. This is exactly like the use of bindparams in update.

>>> select_stmt = select(my_table).where(column1=bindparam("value"))
... connect.executemany(select_stmt,{
    "value": "value1",
    "value": "value2",
})
"""
