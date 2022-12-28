"""
Most DBAPIs support the concept of configurable transaction isolation levels. These are traditionally the four levels “READ UNCOMMITTED”, “READ COMMITTED”, “REPEATABLE READ” and “SERIALIZABLE”. These are usually applied to a DBAPI connection before it begins a new transaction, noting that most DBAPIs will begin this transaction implicitly when SQL statements are first emitted.

DBAPIs that support isolation levels also usually support the concept of true “autocommit”, which means that the DBAPI connection itself will be placed into a non-transactional autocommit mode. This usually means that the typical DBAPI behavior of emitting “BEGIN” to the database automatically no longer occurs, but it may also include other directives. SQLAlchemy treats the concept of “autocommit” like any other isolation level; in that it is an isolation level that loses not only “read committed” but also loses atomicity.


"""
