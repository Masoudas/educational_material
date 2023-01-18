"""
To support multi-tenancy applications that distribute common sets of tables into multiple schemas, the Connection.execution_options.schema_translate_map execution option may be used to repurpose a set of Table objects to render under different schema names without any changes.

Given a table:

user_table = Table(
    "user",
    metadata_obj,
    Column("id", Integer, primary_key=True),
    Column("name", String(50)),
)

The “schema” of this Table as defined by the Table.schema attribute is None. The Connection.execution_options.schema_translate_map can specify that all Table objects with a schema of None would instead render the schema as 'user_schema_one':

connection = engine.connect().execution_options(
    schema_translate_map={None: "user_schema_one"}
)

result = connection.execute(user_table.select())

The above code will invoke SQL on the database of the form:

##########
SELECT user_schema_one.user.id, user_schema_one.user.name FROM
user_schema_one.user
##########


"""
