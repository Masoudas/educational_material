"""
As mentioned previously, most of the patterns and examples above apply to use with the ORM as well, so here we will introduce this usage so that as the tutorial proceeds, we will be able to illustrate each pattern in terms of Core and ORM use together.

The fundamental transactional / database interactive object when using the ORM is called the Session. In modern SQLAlchemy, this object is used in a manner very similar to that of the Connection, and in fact as the Session is used, it refers to a Connection internally which it uses to emit SQL.

When the Session is used with non-ORM constructs, it passes through the SQL statements we give it and does not generally do things much differently from how the Connection does directly, so we can illustrate it here in terms of the simple textual SQL operations we’ve already learned.

The Session has a few different creational patterns, but here we will illustrate the most basic one that tracks exactly with how the Connection is used which is to construct it within a context manager.

The example below can be compared to the example in the preceding section in Bundling Parameters with a Statement - we directly replace the call to with engine.connect() as conn with with Session(engine) as session, and then make use of the Session.execute() method just like we do with the Connection.execute() method.

Also, like the Connection, the Session features “commit as you go” behavior using the 
Session.commit() method, illustrated below using a textual UPDATE statement to alter some of our data:

https://docs.sqlalchemy.org/en/14/tutorial/metadata.html
"""
from sqlalchemy import create_engine, text
from sqlalchemy.orm import Session

engine = create_engine("sqlite:///:memory:")

stmt = text("SELECT x, y FROM some_table WHERE y > :y ORDER BY x, y").bindparams(y=6)
with Session(engine) as session:
    result = session.execute(stmt)

    for row in result:
        print(f"x: {row.x}  y: {row.y}")


with Session(engine) as session:
    result = session.execute(
        text("UPDATE some_table SET y=:y WHERE x=:x"),
        [{"x": 9, "y": 11}, {"x": 13, "y": 15}],
    )
    session.commit()
