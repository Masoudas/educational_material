"""
PassLib is a great Python package to handle password hashes. It supports many secure hashing algorithms and utilities to work with them. The recommended algorithm is "Bcrypt".
So, install PassLib with Bcrypt:

pip install "passlib[bcrypt]"

With passlib, you could even configure it to be able to read passwords created by Django, a Flask security plug-in or many others. So, you would be able to, for example, share the same data from a Django application in a database with a FastAPI application. Or gradually migrate a Django application using the same database.

And your users would be able to login from your Django app or from your FastAPI app, at the same time.
"""
