"""
We pass the dialect together with the url of the db to the create_engine function.

dialect[+driver]://user:password@host/dbname

The echo flag allows to log dB interactions.
"""
from sqlalchemy import create_engine

engine = create_engine("mysql://user:pwd@localhost/college", echo=True)
engine = create_engine("mysql+pymysql://<username>:<password>@<host>/<dbname>")
