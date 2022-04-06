"""
Use pip to install this package as follows:
$ pip3 install pydantic

The advantage with pydantic is that it provides validation methods, easy data snitization, etc.

Imagine from now on that we have a json with booknames, ISBN number, etc. Inherit from BaseModel to create the
data structure. Notice the use of Optional for indicating optional fields. Notice also the unpacking syntax for
construction of item.
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

with open("book_list.json") as f:
	data = json.load(f)
	book : List[Book] = [Book(**item) for item in data]