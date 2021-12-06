"""
SQLite is a C library that provides a lightweight disk-based database that doesn’t require a separate server process and allows accessing the database using a nonstandard variant of the SQL query language. Some applications can use SQLite for internal data storage. It’s also possible to prototype an application using SQLite and then port the code to a larger database such as PostgreSQL or Oracle.

The sqlite3 module was written by Gerhard Häring. It provides a SQL interface compliant with the DB-API 2.0 specification described by PEP 249, and requires SQLite 3.7.15 or newer.

To use the module, start by creating a Connection object that represents the database. Here the data will be stored in the example.db file:

Me: I don't think we need to install sqlite or anything with Python, because the C-library is just wrapped around python functions.

The special path name :memory: can be provided to create a temporary database in RAM. :D
"""
import sqlite3

con = sqlite3.connect('example.db')
