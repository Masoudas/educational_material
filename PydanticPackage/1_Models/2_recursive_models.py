"""
It's possible to use recursive models to compose pydantic data structures, as the following example
demonstrates. Notice how the initialization of nested data structures take place.

We see that the initialization syntax is hard without a static factory method.
"""

from typing import List
from pydantic import BaseModel

class Foo(BaseModel):
	n: int 

class Bar(BaseModel):
	id: str 

class Composition(BaseModel):
	foo : Foo
	bars: List[Bar]

Composition(foo={'n':1}, bars=[{'id': "a"}, {'id': "b"}, {'id': "c"}])	# Passing a dictionary is enough, 
				# just like initializing a normal pydantic class.
Composition(foo=Foo(n=1), bars=[Bar(id="id"), Bar(id="id")])	# Also fine, and I think better!