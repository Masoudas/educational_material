/**
* In overload resolution against user-defined operators, for every pair of promoted arithmetic types L and R and for every 
* object type T, the following function signatures participate in overload resolution:
* 
*	-	LR operator+(L, R)
*	-	LR operator-(L, R)
*	-	T* operator+(T*, std::ptrdiff_t)
*	-	T* operator+(std::ptrdiff_t, T*)
*	-	T* operator-(T*, std::ptrdiff_t)
*	-	std::ptrdiff_t operator-(T*, T*)
* where LR is the result of usual arithmetic conversions on L and R
*/