"""
Here's a basic example of how a pydantic data structure works. Notice the optional field datetime, and how
it is defined. Moreover, notice that it, together with 'friends' (which are optional fields) are placed at
the end of the data structure.

Notice that signup_ts is a datetime field which is not required (and takes the value None if it's not 
supplied). pydantic will process either a unix timestamp int (e.g. 1496498400) or a string representing 
the date & time. 

Notice that we can directly print the data as json. The problem, however, is that the init method of the
data structure only accepts (key, value) pairs, and as such, we can't have a hint regarding fields. What I
personally prefer is to add a constructor method.

Notice that it's possible to pass a string to the int, and it will be converted to an int if it's possible.

"""
from datetime import datetime
from typing import List, Optional
from pydantic import BaseModel


class User(BaseModel):
    id: int
    name = 'John Doe'
    signup_ts: Optional[datetime] = None
    friends: List[int] = []

    @staticmethod
    def create(id: int, name: str, signup_ts: datetime = None, friends: List[int] = []):
        return User(id=id, name=name, signup_ts=signup_ts, friends=friends)

external_data = {
    'id': '123',
    'signup_ts': '2019-06-01 12:22',
    'friends': [1, 2, '3'],
}

user = User(**external_data)
print(user.id)
#> 123

print(repr(user.signup_ts))
#> datetime.datetime(2019, 6, 1, 12, 22)

print(user.friends)
#> [1, 2, 3]

print(user.dict())
"""
{
    'id': 123,
    'signup_ts': datetime.datetime(2019, 6, 1, 12, 22),
    'friends': [1, 2, 3],
    'name': 'John Doe',
}
"""

######### Unix datatime (starting from 1970-01-01)
me = User(id=1, name="Masoud", signup_ts=1636434218)
print(me.signup_ts)	# Prints zeroth-hour of 1970-0-0