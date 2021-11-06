"""
We can add validation methods as class methods (oddly enough!) to our classes. For example, below, we check that
our ISBN numbers have the correct value. It's important that the validator method returns the value in the end,
because the validate method is used for assignment to the field.
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

	@pydantic.validator("isbn_10")
	@classmethod
	def isbn_10_valid(cls, value):
		chars = [c for c in value if c in "123456789Xx"]	# List of chars inside the string with only digits and 
															# Xx
		if len(chars) != 10:
			raise Exception

		def char_to_int(char: str):
			if char == "x" or char == "X":
				return 10
			int(char)

		weighted_sum = sum((10 - i) * char_to_int(x) for i, x in enumerate(chars))
		if weighted_sum % 11 != 0:
			raise Exception

		return value
