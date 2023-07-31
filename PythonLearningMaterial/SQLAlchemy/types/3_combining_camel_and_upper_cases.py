"""
Reviewing the presence of “UPPERCASE” and “CamelCase” types leads to the natural use case of how to make use of “UPPERCASE” datatypes for backend-specific options, but only when that backend is in use. To tie together the database-agnostic “CamelCase” and backend-specific “UPPERCASE” systems, one makes use of the TypeEngine.with_variant() method in order to compose types together to work with specific behaviors on specific backends.

Such as, to use the String datatype, but when running on MySQL to make use of the VARCHAR.charset parameter of VARCHAR when the table is created on MySQL or MariaDB, TypeEngine.with_variant() may be used as below:

In the above table definition, the "bio" column will have string-behaviors on all backends. On most backends it will render in DDL as VARCHAR. However on MySQL and MariaDB (indicated by database URLs that start with mysql or mariadb), it will render as VARCHAR(255) CHARACTER SET utf8.
"""

from sqlalchemy import MetaData
from sqlalchemy import Table, Column, Integer, String
from sqlalchemy.dialects.mysql import VARCHAR

metadata_obj = MetaData()

user = Table(
    "user",
    metadata_obj,
    Column("user_name", String(100), primary_key=True),
    Column(
        "bio",
        String(255).with_variant(VARCHAR(255, charset="utf8"), "mysql", "mariadb"),
    ),
)