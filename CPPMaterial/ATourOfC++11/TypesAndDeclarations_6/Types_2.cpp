/**
 * C++ holds the most basic types. These are bool, char, int, long, float, double, and void.
 * We sometimes initialize built-in types in brackets. This sometimes help avoid unexpected operations, like
 * truncating floating point types.
 * int x {10};  // x is an int with value  10.
 * bool b1 {true};
 * 
 * a bool can be assigned to int. In that case, false would be zero, and true would be one.
 * On the other hand, a zero is assigned to false, and any non-zero int is assigned to true.
 * int i2 {true};//i2 becomes 1
 * bool b {10}; // b would be true.
 * 
 * A pointer can also be converted to bool. A nullptr is false, and other values are true.
 * Though we prefer explicit comparison (although Mr. Bjarne doesn't!)
 * double* p;
 * if (p){}; // Equivalent to p!=nullptr
 * 
 * Then we have pointers, array types and references.
 * 
 * Finally, we have user defined types such as classes, enums and structures.
 * 
 * */