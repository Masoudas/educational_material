"""
This takes in a file path, reads the file and passes the contents to parse_raw. If content_type is omitted, 
it is inferred from the file's extension.
"""
import pickle
from datetime import datetime
from pathlib import Path

from pydantic import BaseModel, ValidationError

class User(BaseModel):
    id: int
    name = 'John Doe'
    signup_ts: datetime = None

# The path module seem to be interesting as well.
path = Path('data.json')
path.write_text('{"id": 123, "name": "James"}')

m = User.parse_file(path)
print(m)
#> id=123 signup_ts=None name='James'