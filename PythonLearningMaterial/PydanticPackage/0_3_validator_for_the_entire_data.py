"""
Suppose now that we want to check the integrity of the data. Especially, we'd like to know that the book has one of
isbn_10 or isbn_30 inside of it (which is optional in the presence of the other one.) This can be done using the
root validator.

The validator can be applied before or after the data is converted to the type. Here, we use the pre version to 
avoid conversion. Notice that values is the dictionary of the class, so we may check presence inside of it with
the in keyword.
"""

import json
import pydantic
from typing import Optional, List

class Book(pydantic.BaseModel):
	title : str
	author: str
	price: float
	isbn_10: Optional[str]
	isbn_13: Optional[str]
	subtitle: Optional[str]

	@pydantic.root_validator(pre=True)
	@classmethod
	def check_isbn10_or_isbn13(cls, values):
		"""Check if it has isbn10 or 13"""
		if "isbn_10" not in values and "isbn_13" not in values:
			raise Exception

		return values

