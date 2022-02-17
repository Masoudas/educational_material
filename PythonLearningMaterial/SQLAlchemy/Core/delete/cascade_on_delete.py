"""
Me: I couldn't find anything on the internet for this. But I imagine this is going to work. We simply have to add a foreign key constraint to the target table.

Of importance and interest is the fact that we need to turn on foreign key constraint:
$ conn.execute(text("PRAGMA foreign_keys = on"))

"""
from operator import and_, or_
from select import select
from sqlalchemy import text, ForeignKey, MetaData, Table, Column, Integer, ForeignKeyConstraint, create_engine

engine = create_engine("sqlite:///my_db.db", future=True)
metadata = MetaData(engine)

ids = Table(
    "ids", metadata,
    Column("id", Integer, primary_key=True))

names = Table(
    "names",
    metadata,
    Column("id", Integer, ForeignKey(
        ids.c["id"], ondelete="CASCADE"), primary_key=True),
    Column("uid", Integer),
)

conn = engine.connect()
conn.execute(text("PRAGMA foreign_keys = on"))
metadata.create_all(conn)

insert_ids = ids.insert().values(
    [{"id": 1}, {"id": 2}, {"id": 3}])
insert_names = names.insert().values(
    [{"id": 1, "uid": 1}, {"id": 2, "uid": 2}, {"id": 3, "uid": 3}]
)

conn.execute(insert_ids)
conn.execute(insert_names)

delete = ids.delete().where(
    or_(
        ids.c["id"] == 1,
        ids.c["id"] == 2
    )
)
conn.execute(delete)

conn.commit()
conn.close()
