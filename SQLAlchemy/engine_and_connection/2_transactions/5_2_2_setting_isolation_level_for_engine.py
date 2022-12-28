"""
The Connection.execution_options.isolation_level option may also be set engine wide, as is often preferable. This may be achieved by passing the create_engine.isolation_level parameter to create_engine():

>>> from sqlalchemy import create_engine
>>> eng = create_engine(
    "postgresql://scott:tiger@localhost/test", isolation_level="REPEATABLE READ"
    )
    
With the above setting, each new DBAPI connection the moment it’s created will be set to use a "REPEATABLE READ" isolation level setting for all subsequent operations.
"""
