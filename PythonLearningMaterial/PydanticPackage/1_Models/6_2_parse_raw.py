"""
This takes a str or bytes and parses it as json, then passes the result to parse_obj. Parsing pickle data 
is also supported by setting the content_type argument appropriately.
"""
import pickle
from datetime import datetime
from pathlib import Path

from pydantic import BaseModel, ValidationError


class User(BaseModel):
    id: int
    name = 'John Doe'
    signup_ts: datetime = None

# assumes json as no content type passed
m = User.parse_raw('{"id": 123, "name": "James"}')
print(m)
#> id=123 signup_ts=None name='James'

pickle_data = pickle.dumps({
    'id': 123,
    'name': 'James',
    'signup_ts': datetime(2017, 7, 14)
})
m = User.parse_raw(
    pickle_data, content_type='application/pickle', allow_pickle=True
)
print(m)