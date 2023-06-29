"""
ME: Essentially, we're going to discuss how we can have an engine that creates connections with default isolation_level, but give enough flexibility on connection level, to set different levels there.
\
The isolation level may also be set per engine, with a potentially greater level of flexibility, using either the create_engine.execution_options parameter to create_engine() or the Engine.execution_options() method, the latter of which will create a copy of the Engine that shares the dialect and connection pool of the original engine, but has its own per-connection isolation level setting:

from sqlalchemy import create_engine

eng = create_engine(
    "postgresql+psycopg2://scott:tiger@localhost/test",
    execution_options={"isolation_level": "REPEATABLE READ"},
)

With the above setting, the DBAPI connection will be set to use a "REPEATABLE READ" isolation level setting for each new transaction begun; but the connection as pooled will be reset to the original isolation level that was present when the connection first occurred. At the level of create_engine(), the end effect is not any different from using the create_engine.isolation_level parameter.

However, an application that frequently chooses to run operations within different isolation levels may wish to create multiple “sub-engines” of a lead Engine, each of which will be configured to a different isolation level. One such use case is an application that has operations that break into “transactional” and “read-only” operations, a separate Engine that makes use of "AUTOCOMMIT" may be separated off from the main engine:

>>> from sqlalchemy import create_engine
>>> eng = create_engine("postgresql+psycopg2://scott:tiger@localhost/test")
>>> autocommit_engine = eng.execution_options(isolation_level="AUTOCOMMIT")

Above, the Engine.execution_options() method creates a shallow copy of the original Engine. Both eng and autocommit_engine share the same dialect and connection pool. However, the “AUTOCOMMIT” mode will be set upon connections when they are acquired from the autocommit_engine.

The isolation level setting, regardless of which one it is, is unconditionally reverted when a connection is returned to the connection pool.
"""
