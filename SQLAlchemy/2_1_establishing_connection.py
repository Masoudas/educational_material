"""
The start of any SQLAlchemy application is an object called the Engine. This object acts as a central source of connections to a particular database, providing both a factory as well as a holding space called a connection pool for these database connections. The engine is typically a global object created just once for a particular database server, and is configured using a URL string which will describe how it should connect to the database host or backend.

###
Me: Note: As such, creating connections to a database from various locations in the code does not lead to different connections, but rather the same (one) connection. Say we write:

conn1 = create_enginge("db1")
conn2 = create_enginge("db1")

These are the same connections, and as such transactions with them go through the same channel. This is good, but the problem is that as such, we may have conflicts between two threads possibly (or maybe not, because there would be a queuing of the requests.)
###

For this tutorial we will use an in-memory-only SQLite database. This is an easy way to test things without needing to have an actual pre-existing database set up. The Engine is created by using create_engine(), specifying the create_engine.future flag set to True so that we make full use of 2.0 style usage:

>>> from sqlalchemy import create_engine
>>> engine = create_engine("sqlite+pysqlite:///:memory:", echo=True, future=True)

The main argument to create_engine is a string URL, above passed as the string "sqlite+pysqlite:///:memory:". This string indicates to the Engine three important facts:

What kind of database are we communicating with? This is the sqlite portion above, which links in SQLAlchemy to an object known as the dialect.

What DBAPI are we using? The Python DBAPI is a third party driver that SQLAlchemy uses to interact with a particular database. In this case, we're using the name pysqlite, which in modern Python use is the sqlite3 standard library interface for SQLite. If omitted, SQLAlchemy will use a default DBAPI for the particular database selected.

How do we locate the database? In this case, our URL includes the phrase /:memory:, which is an indicator to the sqlite3 module that we will be using an in-memory-only database. This kind of database is perfect for experimenting as it does not require any server nor does it need to create new files.

Me: Recall that sqlite does not require username or password.

Lazy Connecting

The Engine, when first returned by create_engine(), has not actually tried to connect to the database yet (me: Very important to note that unless we connect, no exceptions will be raises); that happens only the first time it is asked to perform a task against the database. This is a software design pattern known as lazy initialization.

We have also specified a parameter create_engine.echo, which will instruct the Engine to log all of the SQL it emits to a Python logger that will write to standard out. This flag is a shorthand way of setting up Python logging more formally and is useful for experimentation in scripts. Many of the SQL examples will include this SQL logging output beneath a [SQL] link that when clicked, will reveal the full SQL interaction.

With the Engine object ready to go, we may now proceed to dive into the basic operation of an Engine and its primary interactive endpoints, the Connection and Result. We will additionally introduce the ORM's facade for these objects, known as the Session.
"""