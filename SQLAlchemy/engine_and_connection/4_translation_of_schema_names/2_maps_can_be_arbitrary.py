"""
The map can specify any number of target->destination schemas:

connection = engine.connect().execution_options(
    schema_translate_map={
        None: "user_schema_one",  # no schema name -> "user_schema_one"
        "special": "special_schema",  # schema="special" becomes "special_schema"
        "public": None,  # Table objects with schema="public" will render with no schema
    }
)
"""
