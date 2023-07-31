"""
The rudimental types have “CamelCase” names such as String, Numeric, Integer, and DateTime. All of the immediate subclasses of TypeEngine are “CamelCase” types. The “CamelCase” types are to the greatest degree possible database agnostic, meaning they can all be used on any database backend where they will behave in such a way as appropriate to that backend in order to produce the desired behavior.

An example of a straightforward “CamelCase” datatype is String. On most backends, using this datatype in a table specification will correspond to the VARCHAR database type being used on the target backend, delivering string values to and from the database, as in the example below:

When using a particular TypeEngine class in a Table definition or in any SQL expression overall, if no arguments are required it may be passed as the class itself, that is, without instantiating it with (). If arguments are needed, such as the length argument of 60 in the "email_address" column above, the type may be instantiated.

Another “CamelCase” datatype that expresses more backend-specific behavior is the Boolean datatype. Unlike String, which represents a string datatype that all databases have, not every backend has a real “boolean” datatype; some make use of integers or BIT values 0 and 1, some have boolean literal constants true and false while others dont. For this datatype, Boolean may render BOOLEAN on a backend such as PostgreSQL, BIT on the MySQL backend and SMALLINT on Oracle. As data is sent and received from the database using this type, based on the dialect in use it may be interpreting Python numeric or boolean values.

The typical SQLAlchemy application will likely wish to use primarily “CamelCase” types in the general case, as they will generally provide the best basic behavior and be automatically portable to all backends.
"""
from sqlalchemy import MetaData
from sqlalchemy import Table, Column, Integer, String

metadata_obj = MetaData()

user = Table(
    "user",
    metadata_obj,
    Column("user_name", String, primary_key=True),
    Column("email_address", String(60)),
)