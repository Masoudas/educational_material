"""
Me: Essentially, in this example, we discuss how to get a table from metadata. That is, a table that's already created, and we want to use it, for example to create a foreign key constraint, etc.

To round out the section on working with table metadata, we will illustrate another operation that was mentioned at the beginning of the section, that of table reflection. Table reflection refers to the process of generating Table and related objects by reading the current state of a database. Whereas in the previous sections we've been declaring Table objects in Python and then emitting DDL to the database, the reflection process does it in reverse.

As an example of reflection, we will create a new Table object which represents the some_table object we created manually in the earlier sections of this document. There are again some varieties of how this is performed, however the most basic is to construct a Table object, given the name of the table and a MetaData collection to which it will belong, then instead of indicating individual Column and Constraint objects, pass it the target Engine using the Table.autoload_with parameter:

>>> some_table = Table("some_table", metadata_obj, autoload_with=engine)
BEGIN (implicit)
PRAGMA main.table_...info("some_table")
[raw sql] ()
SELECT sql FROM  (SELECT * FROM sqlite_master UNION ALL   SELECT * FROM sqlite_temp_master) WHERE name = ? AND type = 'table'
[raw sql] ('some_table',)
PRAGMA main.foreign_key_list("some_table")
...
PRAGMA main.index_list("some_table")
...
ROLLBACK

At the end of the process, the some_table object now contains the information about the Column objects present in the table, and the object is usable in exactly the same way as a Table that we declared explicitly:

>>> some_table
Table('some_table', MetaData(),
    Column('x', INTEGER(), table=<some_table>),
    Column('y', INTEGER(), table=<some_table>),
    schema=None)

"""
