"""
In “commit as you go” style, we can call upon Connection.commit() and Connection.rollback() methods freely within an ongoing sequence of other statements emitted using Connection.execute(); each time the transaction is ended, and a new statement is emitted, a new transaction begins implicitly:

New in version 2.0: “commit as you go” style is a new feature of SQLAlchemy 2.0. It is also available in SQLAlchemy 1.4’s “transitional” mode when using a “future” style engine.

with engine.connect() as connection:
    connection.execute("<some statement>")
    connection.commit()  # commits "some statement"

    # new transaction starts
    connection.execute("<some other statement>")
    connection.rollback()  # rolls back "some other statement"

    # new transaction starts
    connection.execute("<a third statement>")
    connection.commit()  # commits "a third statement"
"""