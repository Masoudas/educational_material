"""
Me: All we say in the following is that a pydantic class can be created from another arbitrary class (or
an ORM) so longs as the public fields of that class are the same as those of our pydantic. There's an
implicit conversion happenning between the two.

To do so, just define the nested Config class, and then also set the from_orm to True.
"""
from pydantic import BaseModel

class ORM:
	my_field: int = 10

class pydan_data(BaseModel):
	my_field: int

	class Config:
		orm_mode = True

strct = pydan_data.from_orm(ORM())