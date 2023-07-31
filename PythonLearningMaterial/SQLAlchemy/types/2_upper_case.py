"""
In contrast to the “CamelCase” types are the “UPPERCASE” datatypes. These datatypes are always inherited from a particular “CamelCase” datatype, and always represent an exact datatype. When using an “UPPERCASE” datatype, the name of the type is always rendered exactly as given, without regard for whether or not the current backend supports it. Therefore the use of “UPPERCASE” types in a SQLAlchemy application indicates that specific datatypes are required, which then implies that the application would normally, without additional steps taken, be limited to those backends which use the type exactly as given. Examples of UPPERCASE types include VARCHAR, NUMERIC, INTEGER, and TIMESTAMP, which inherit directly from the previously mentioned “CamelCase” types String, Numeric, Integer, and DateTime, respectively.

The “UPPERCASE” datatypes that are part of sqlalchemy.types are common SQL types that typically expect to be available on at least two backends if not more.

Backend-specific “UPPERCASE” datatypes
Most databases also have their own datatypes that are either fully specific to those databases, or add additional arguments that are specific to those databases. For these datatypes, specific SQLAlchemy dialects provide backend-specific “UPPERCASE” datatypes, for a SQL type that has no analogue on other backends. Examples of backend-specific uppercase datatypes include PostgreSQL’s JSONB, SQL Server’s IMAGE and MySQL’s TINYTEXT.

Specific backends may also include “UPPERCASE” datatypes that extend the arguments available from that same “UPPERCASE” datatype as found in the sqlalchemy.types module. An example is when creating a MySQL string datatype, one might want to specify MySQL-specific arguments such as charset or national, which are available from the MySQL version of VARCHAR as the MySQL-only parameters VARCHAR.charset and VARCHAR.national.

API documentation for backend-specific types are in the dialect-specific documentation, listed at Dialects.
"""