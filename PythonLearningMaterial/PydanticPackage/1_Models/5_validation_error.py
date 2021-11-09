"""
pydantic will raise ValidationError whenever it finds an error in the data it's validating.

The docs say "Validation code should not raise ValidationError itself, but rather raise ValueError, 
TypeError or AssertionError (or subclasses of ValueError or TypeError) which will be caught and used to 
populate ValidationError."

One exception will be raised regardless of the number of errors found, that ValidationError will contain 
information about all the errors and how they happened.

Below is an example. Note that the exception class has a .json, or .errors itself.
"""

from pydantic import BaseModel, ValidationError, validator


class Model(BaseModel):
    foo: str

    @validator('foo')
    def name_must_contain_space(cls, v):
        if v != 'bar':
            raise ValueError('value must be "bar"')

        return v


try:
    Model(foo='ber')
except ValidationError as e:
    print(e.errors())
    """
    [
        {
            'loc': ('foo',),
            'msg': 'value must be "bar"',
            'type': 'value_error',
        },
    ]
    """