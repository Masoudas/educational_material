"""
A few things to note on validators:

	-	validators are "class methods", so the first argument value they receive is the UserModel class, not an 
	instance of UserModel. the second argument is always the field value to validate; it can be named as you 
	please you can also add any subset of the following arguments to the signature (the names must match):
	-	values: a dict containing the name-to-value mapping of any previously-validated fields
	-	config: the model config	
	-	field: the field being validated. Type of object is pydantic.fields.ModelField.
	-	**kwargs: if provided, this will include the arguments above not explicitly listed in the signature
	- 	VERY IMPORTANT: validators should either return the parsed value or raise a ValueError, TypeError, or 
		AssertionError (assert statements may be used).
"""