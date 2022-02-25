"""
Here's something so cool about date time. If we have a date time type object in the table, then it's RETURNED by the table as a date time object of python.

On the other hand, if we want to insert a datetime, we should directly insert a datetime object! So cool!
"""
from datetime import date
from sqlalchemy import (Column, Date, Integer, MetaData, Table,
                        create_engine, text)

engine = create_engine("sqlite:///:memory:", future=True)
metadata = MetaData(engine)

ids = Table(
    "ids", metadata,
    Column("id", Integer, primary_key=True),
    Column("date", Date))


conn = engine.connect()
metadata.create_all(conn)

insert_ids = ids.insert().values(
    [{"id": 1, "date": date(1394, 10, 10)}, {"id": 2, "date": date(1394, 10, 10)}, {"id": 3, "date": date(1394, 10, 10)}])

conn.execute(insert_ids)


for c in conn.execute(ids.select()):
    d: date = c[1]
    print(d.month, d.day)
