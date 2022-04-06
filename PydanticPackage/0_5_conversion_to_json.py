"""We may also directly convert our data classes to json as well.
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

#Book().json()
