/**
* A prvalue of integral, floating-point, unscoped enumeration, pointer, and pointer-to-member types can be 
* converted to a prvalue of type bool.
* 
* The value zero (for integral, floating-point, and unscoped enumeration) and the null pointer and the null 
* pointer-to-member values become false. All other values become true.
* 
* In the context of a direct-initialization, a bool object may be initialized from a prvalue of type 
* std::nullptr_t, including nullptr. The resulting value is false. However, this is not considered to be an 
* implicit conversion.
*/