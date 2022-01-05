"""
Insert returning allows for returning values in backends that support it.

The RETURNING clause for supported backends is used automatically in order to retrieve the last inserted primary key value as well as the values for server defaults. However the RETURNING clause may also be specified explicitly using the Insert.returning() method; in this case, the Result object that's returned when the statement is executed has rows which can be fetched:

ME: Notice how we customize what to return
>>> insert_stmt = insert(address_table).returning(address_table.c.id, address_table.c.email_address)
>>> print(insert_stmt)
INSERT INTO address (id, user_id, email_address)
VALUES (:id, :user_id, :email_address)
RETURNING address.id, address.email_address

NOTE: 
The RETURNING feature is generally only supported for statement executions that use a single set of bound parameters; that is, it wont work with the “executemany” form introduced at Sending Multiple Parameters. Additionally, some dialects such as the Oracle dialect only allow RETURNING to return a single row overall, meaning it won’t work with “INSERT..FROM SELECT” nor will it work with multiple row Update or Delete forms

"""
