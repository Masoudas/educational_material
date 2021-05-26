/**
* A null pointer constant (see NULL) can be converted to any pointer-to-member type, and the result is the 
* null member pointer value of that type. Such conversion (known as null member pointer conversion) is allowed 
* to convert to a cv-qualified type as a single conversion, that is, it's not considered a combination of 
* numeric and qualifying conversions.
*
* A prvalue pointer to member of some type T in a base class B can be converted to a prvalue pointer to member 
* of the same type T in its derived class D. If B is inaccessible, ambiguous, or virtual base of D or is a 
* base of some intermediate virtual base of D, the conversion is ill-formed (won't compile). The resulting 
* pointer can be dereferenced with a D object, and it will access the member within the B base subobject of 
* that D object. The null pointer value is converted to the null pointer value of the destination type.
*/

??????