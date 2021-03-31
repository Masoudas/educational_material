/**
* Consider for example a comp method. Normally, we write such a method as:
* template<typename T>
* bool comp(T lhs, T rhs){
*		return lhs < rhs;
* }
* 
* The problem however is that if a pointer is passed, then this comparison compares the pointers. Hence, we add a 
* specialization for the case of pointers:
* 
* template<typename T>
* bool comp<T*>(T* lhs, T* rhs){	// Recall that T is a type, and not pointer, hence we get a T* as argument.
*		return *lhs < *rhs;
* }
* 
* We also require an extra addition for const char*
* template<typename T>
* bool comp<const char*>(const char* lhs, const char* rhs){
*		return strcmp(lhs, rhs);
* }
*
* But note that instead, we may use overload resolution rules to write:
* template<>
* bool comp<>(const char* lhs, const char* rhs){
*		return strcmp(lhs, rhs);
* }
* 
* But then, the brackets are unnecessary, so we can write:
* template<>
* bool comp(const char* ...){ ... }
* 
* But then we can go one final step and write
* bool comp(const char* ...){ ... }
* 
* Me: But then again, the fact that comp in such a state is considered a redefiniton is enough of an incentive to use 
* specialization rather than overload resolution.
*/

//???? Relation to template deduction!!!!!!