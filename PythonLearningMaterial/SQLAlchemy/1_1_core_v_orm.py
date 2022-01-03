"""
SQLAlchemy is presented as two distinct APIs, one building on top of the other. These APIs are known as Core and ORM.

SQLAlchemy Core is the foundational architecture for SQLAlchemy as a “database toolkit”. The library provides tools for managing connectivity to a database, interacting with database queries and results, and programmatic construction of SQL statements.

This tutorial describes a new API that's released in SQLAlchemy 1.4 known as 2.0 style. The purpose of the 2.0-style API is to provide forwards compatibility with SQLAlchemy 2.0, which is planned as the next generation of SQLAlchemy.

In order to provide the full 2.0 API, a new flag called future will be used, which will be seen as the tutorial describes the Engine and Session objects. These flags fully enable 2.0-compatibility mode and allow the code in the tutorial to proceed fully. When using the future flag with the create_engine() function, the object returned is a subclass of sqlalchemy.engine.Engine described as sqlalchemy.future.Engine. This tutorial will be referring to sqlalchemy.future.Engine.
"""
import sqlalchemy
print(sqlalchemy.__version__)