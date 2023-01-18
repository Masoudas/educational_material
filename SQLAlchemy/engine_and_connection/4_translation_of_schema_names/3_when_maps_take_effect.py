"""
The Connection.execution_options.schema_translate_map parameter affects all DDL and SQL constructs generated from the SQL expression language, as derived from the Table or Sequence objects. It does not impact literal string SQL used via the text() construct nor via plain strings passed to Connection.execute().

The feature takes effect only in those cases where the name of the schema is derived directly from that of a Table or Sequence; it does not impact methods where a string schema name is passed directly. By this pattern, it takes effect within the “can create” / “can drop” checks performed by methods such as MetaData.create_all() or MetaData.drop_all() are called, and it takes effect when using table reflection given a Table object. However it does not affect the operations present on the Inspector object, as the schema name is passed to these methods explicitly.
"""
