"""
NOTE: Prefer to use individual Connection objects each with just one isolation level, rather than switching isolation on a single Connection. The code will be easier to read and less error prone.

Isolation level settings, including autocommit mode, are reset automatically when the connection is released back to the connection pool. Therefore it is preferable to avoid trying to switch isolation levels on a single Connection object as this leads to excess verbosity.

To illustrate how to use “autocommit” in an ad-hoc mode within the scope of a single Connection checkout, the Connection.execution_options.isolation_level parameter must be re-applied with the previous isolation level. The previous section illustrated an attempt to call Connection.begin() in order to start a transaction while autocommit was taking place; we can rewrite that example to actually do so by first reverting the isolation level before we call upon Connection.begin():

# if we wanted to flip autocommit on and off on a single connection which... we usually don't.

with engine.connect() as connection:

    connection.execution_options(isolation_level="AUTOCOMMIT")

    # run statement(s) in autocommit mode
    connection.execute("<statement>")

    # "commit" the autobegun "transaction"
    connection.commit()

    # switch to default isolation level
    connection.execution_options(isolation_level=connection.default_isolation_level)

    # use a begin block
    with connection.begin() as trans:
        connection.execute("<statement>")

Above, to manually revert the isolation level we made use of Connection.default_isolation_level to restore the default isolation level (assuming that’s what we want here). However, it’s probably a better idea to work with the architecture of of the Connection which already handles resetting of isolation level automatically upon checkin. The preferred way to write the above is to use two blocks

# use an autocommit block
with engine.connect().execution_options(isolation_level="AUTOCOMMIT") as connection:

    # run statement in autocommit mode
    connection.execute("<statement>")

# use a regular block
with engine.begin() as connection:
    connection.execute("<statement>")
"""