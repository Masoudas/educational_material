"""
If we want to create data without validation, we can skip it using the construct method.

Notice how we use the __fields_set__ parameter to construct our new data, allowing it to not validate those
fields that are passed by this parameter as a set. Note that fields set is optional. If we don't pass it,
the __fields_set__will not be set to all the fields, which is a hint for us. In any case, no exception is thrown 
for a missing field or invaild argument.
"""

from pydantic import BaseModel

class User(BaseModel):
    id: int
    age: int
    name: str = 'John Doe'

original_user = User(id=123, age=32)

user_data = original_user.dict()
print(user_data)
#> {'id': 123, 'age': 32, 'name': 'John Doe'}
fields_set = original_user.__fields_set__	# The fields set by the construction
print(fields_set)
#> {'age', 'id'}

# ...
# pass user_data and fields_set to RPC or save to the database etc.
# ...

# you can then create a new instance of User without
# re-running validation which would be unnecessary at this point:
new_user = User.construct(_fields_set=fields_set, **user_data)
print(repr(new_user))
#> User(id=123, age=32, name='John Doe')
print(new_user.__fields_set__)
#> {'age', 'id'}

# construct can be dangerous, only use it with validated data!:
bad_user = User.construct(id='dog')
print(repr(bad_user))
print(bad_user.__fields_set__)	# Only prints id.

#> User(id='dog', name='John Doe')

