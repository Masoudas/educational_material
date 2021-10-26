"""
	-	object.__setattr__(self, name, value)
Called when an attribute assignment is attempted. This is called instead of the normal mechanism (i.e. store the 
value in the instance dictionary). name is the attribute name, value is the value to be assigned to it.

If __setattr__() wants to assign to an instance attribute, it should call the base class method with the same name, 
for example, object.__setattr__(self, name, value).

For certain sensitive attribute assignments, raises an auditing event object.__setattr__ with arguments obj, name, 
value.
"""

class F:
	def __setattr__(self, name: str, value: Any) -> None:
		if (name == "Special attribute"):
			print("Setting the special value")
		else:
			super().__setattr__(self, name, value)	# The proper way of setting all attributes so that no infinite
													# recursion occurs. This is merely a contract in my opinion,
													# which calls the object class's setattr method.
