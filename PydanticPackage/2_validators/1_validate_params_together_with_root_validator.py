"""
If we wanted to check the ensemble of parameters together, we can use the root validator. This validator gets
the dictionary of the class, and must return it as well.

NOTE that root validators throw ValidationError regardless of the exception we raise.
"""
from pydantic import BaseModel, root_validator

class Data(BaseModel):
	v1 : int = 10
	v2 : int = 20

	@root_validator
	def check(cls, values):
		assert values.get('v1') + values.get('v2') == 30, "Not validated"
		return values

d1 = Data()
d2 = Data(v1=20)