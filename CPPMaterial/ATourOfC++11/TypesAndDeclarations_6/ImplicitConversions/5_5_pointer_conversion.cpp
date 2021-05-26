/**
* Me: Whereas void pointer can be converted to bool, it can't be directly converted to int. Of course, this
* is the case for all pointers, but I just wanted to emphasize that pointers can be converted to bools but
* not ints.
* 
* A null pointer constant (see NULL), can be converted to any pointer type, and the result is the null pointer 
* value of that type. Such conversion (known as null pointer conversion) is allowed to convert to a 
* cv-qualified type as a single conversion, that is, it's not considered a combination of numeric and 
* qualifying conversions.
* 
* A prvalue pointer to any (optionally cv-qualified) object type T can be converted to a prvalue pointer to 
* (identically cv-qualified) void. The resulting pointer represents the same location in memory as the 
* original pointer value. If the original pointer is a null pointer value, the result is a null pointer value 
* of the destination type.
* 
* A prvalue pointer to a (optionally cv-qualified) derived class type can be converted to a prvalue pointer 
* to its (identically cv-qualified) base class. If the base class is inaccessible or ambiguous, the conversion 
* is ill-formed (won't compile). The result of the conversion is a pointer to the base class subobject within 
* the pointed-to object. The null pointer value is converted to the null pointer value of the destination type.
*/

void null_pointer() {
	int x = 10;
	const int y = 10;

	void* p1 = &x;
	// void* p2 = &y; Error!
	const void* p3 = &y;	// Fine
}