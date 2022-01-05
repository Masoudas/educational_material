"""
We may also use the count from the func in databases to produce counts in the SELECT clause.
"""
from sqlalchemy import func, select
from sqlalchemy.sql.schema import MetaData, Table

user_table = Table("user_table", MetaData())
select(func.count('*')).select_from(user_table)

