"""At least, it appears for the core functionalities that all exceptions are extension of sqlalchemy.exc.SQLAlchemyError. As such, no matter what the exception is, we can catch it with this,"""
from sqlalchemy import create_engine
from sqlalchemy.exc import SQLAlchemyError

try:
    create_engine("asdad")
except SQLAlchemyError as e:
    print(e)
    raise 1 # My custom exception
