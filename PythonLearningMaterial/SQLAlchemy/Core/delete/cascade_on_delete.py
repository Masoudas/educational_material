"""
Me: I couldn't find anything on the internet for this. But I imagine this is going to work. We simply have to add a foreign key constraint to the target table.

Of importance and interest is the fact that we need to turn on foreign key constraint:
$ conn.execute(text("PRAGMA foreign_keys = on"))

"""
from operator import and_, or_
from select import select
from sqlalchemy import text, ForeignKey, MetaData, Table, Column, Integer, Date, create_engine
from datetime import date

engine = create_engine("sqlite:///my_db.db", future=True)
metadata = MetaData(engine)

ids = Table(
    "ids", metadata,
    Column("id", Integer, primary_key=True),
    Column("date", Date))

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
    [{"id": 1, "date": date(1394, 10, 10)}, {"id": 2, "date": date(1394, 10, 10)}, {"id": 3, "date": date(1394, 10, 10)}])
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

for c in conn.execute(ids.select()):
    d: date = c[1]
    print(d.month, d.day)

conn.commit()
conn.close()
