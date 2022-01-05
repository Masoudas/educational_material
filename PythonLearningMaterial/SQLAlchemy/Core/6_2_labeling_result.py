"""
It's possible to rename columns or expressions using the label method. That way, we can reuse expressions or columns if needed in other expressions.
"""
from sqlalchemy import insert, Table, MetaData, create_engine

engine = create_engine("", future=True)
user_table = Table("user_table", MetaData())

my_querry = user_table.select().label("my new querry")

user_table.insert().from_select(["column1", "column2"], "my new querry")
