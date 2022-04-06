"""
Me: We can directly pass parameters to the execute clause for an insert statement. This is because the insert clause generates parameter binds automatically.

The usual way that Insert is used is such that the VALUES clause is generated automatically from the parameters passed to the Connection.execute() method; below we INSERT two more rows to illustrate this.

The execution features “executemany” form first illustrated at Sending Multiple Parameters, however unlike when using the text() construct, we didn’t have to spell out any SQL. By passing a dictionary or list of dictionaries to the Connection.execute() method in conjunction with the Insert construct, the Connection ensures that the column names which are passed will be expressed in the VALUES clause of the Insert construct automatically.

>>> with engine.connect() as conn:
...     result = conn.execute(
...         insert(user_table),
...         [
...             {"name": "sandy", "fullname": "Sandy Cheeks"},
...             {"name": "patrick", "fullname": "Patrick Star"}
...         ]
...     )
...     conn.commit()
"""
