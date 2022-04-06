"""
To support UPDATE in an “executemany” context, where many parameter sets will be invoked against the same statement, the bindparam() construct may be used to set up bound parameters; these replace the places that literal values would normally go:

>>> from sqlalchemy import bindparam

>>> stmt = (
...   update(user_table).
...   where(user_table.c.name == bindparam('oldname')).
...   values(name=bindparam('newname'))
... )

>>> with engine.begin() as conn:
...   conn.execute(
...       stmt,
...       [
...          {'oldname':'jack', 'newname':'ed'},
...          {'oldname':'wendy', 'newname':'mary'},
...          {'oldname':'jim', 'newname':'jake'},
...       ]
...   )
BEGIN (implicit)
UPDATE user_account SET name=? WHERE user_account.name = ?
[...] (('ed', 'jack'), ('mary', 'wendy'), ('jake', 'jim'))
<sqlalchemy.engine.cursor.CursorResult object at 0x...>
COMMIT    
"""
