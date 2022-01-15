"""
If you plan to use Django’s database API functionality, you’ll need to make sure a database server is running. Django supports many different database servers and is officially supported with PostgreSQL, MariaDB, MySQL, Oracle and SQLite.

In addition to a database backend, you’ll need to make sure your Python database bindings are installed.

    -   If you’re using PostgreSQL, you’ll need the psycopg2 package. Refer to the PostgreSQL notes for further details.
    -   If you’re using MySQL or MariaDB, you’ll need a DB API driver like mysqlclient. See notes for the MySQL backend for details.
    -   If you’re using SQLite you might want to read the SQLite backend notes.
    -   If you’re using Oracle, you’ll need a copy of cx_Oracle, but please read the notes for the Oracle backend for details regarding supported versions of both Oracle and cx_Oracle.
    -   If you’re using an unofficial 3rd party backend, please consult the documentation provided for any additional requirements.

If you plan to use Django’s manage.py migrate command to automatically create database tables for your models (after first installing Django and creating a project), you’ll need to ensure that Django has permission to create and alter tables in the database you’re using; if you plan to manually create the tables, you can grant Django SELECT, INSERT, UPDATE and DELETE permissions. After creating a database user with these permissions, you’ll specify the details in your project’s settings file, see DATABASES for details.
"""