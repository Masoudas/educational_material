"""
Use the allow_mutation field to determine whether a class is mutable or not. This field is set inside the Config
class nested inside the data structure.
"""
import pydantic
from typing import Optional

class Book(pydantic.BaseModel):
	title : str
	author: str
	price: float
	isbn_10: Optional[str]
	isbn_13: Optional[str]
	subtitle: Optional[str]

	class Config:
		allow_mutation = False
		anystr_lower = True	# Convert any string value to lower!