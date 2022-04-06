from sqlalchemy import MetaData, select, insert, Integer, Column, Table, String, func, update

m = MetaData()

address_table = Table("address", m,
                      Column('user_id', Integer, primary_key=True),
                      Column('email_address', String, nullable=False)
                      )

my_table = Table("my_table", m,
                 Column('count', Integer, primary_key=True),
                 Column('id', String, nullable=False)
                 )

subq = select(
    func.count(address_table.c.user_id).label("count"),
    address_table.c.user_id
).group_by(address_table.c.user_id).cte()

update_stmt = update(my_table).where(subq.c.user_id == my_table.c.id)

print(update_stmt)
