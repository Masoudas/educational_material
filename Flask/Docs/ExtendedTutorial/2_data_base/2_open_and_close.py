"""
The first thing to do when working with a SQLite database (and most other Python database libraries) is to create 
a connection to it. Any queries and operations are performed using the connection, which is closed after the work 
is finished.

In web applications this connection is typically tied to the request. It is created at some point when handling a 
request, and closed before the response is sent.

Note that current_app allows us to access the current app from anywhere.

What is 'g'? g is a special object that is unique for each request. It is used to store data that might be 
accessed by multiple functions during the request. The connection is stored and reused instead of creating a new 
connection if get_db is called a second time in the same request.

Note sqlite3.connect is the function for connecting to our DB. We also have to supply the row factory to the
g.db object as well. sqlite3.Row tells the connection to return rows that behave like dicts. This allows 
accessing the columns by name.

Also note that close_db checks if a connection was created by checking if g.db was set. If the connection exists, 
it is closed. Further down you will tell your application about the close_db function in the application factory 
so that it is called after each request.
"""

import sqlite3

import click
from flask import current_app, g
from flask.cli import with_appcontext

def get_db():
    if 'db' not in g:
        g.db = sqlite3.connect(
            current_app.config['DATABASE'],
            detect_types=sqlite3.PARSE_DECLTYPES
        )
        g.db.row_factory = sqlite3.Row

    return g.db


def close_db(e=None):
    db = g.pop('db', None)

    if db is not None:
        db.close()
