"""
This is very similar to the __init__ method of the model, except it takes a dict rather than keyword 
arguments. If the object passed is not a dict a ValidationError will be raised.
"""
import pickle
from datetime import datetime
from pathlib import Path

from pydantic import BaseModel, ValidationError


class User(BaseModel):
    id: int
    name = 'John Doe'
    signup_ts: datetime = None


m = User.parse_obj({'id': 123, 'name': 'James'})
print(m)