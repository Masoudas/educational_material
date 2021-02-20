/**
* Same as with type concepts, we can have value concept constraints. For example, below we define a constraint to
* check whether a given int template has a small enough size.
* 
* Compared to the fundamental concepts for types, value concepts tend to be small and ad hoc.
*/

template<int N>
constexpr bool Small_size() {
	return N < 8;
}

template<typename T>
constexpr bool Regular() {
	return true;
}

constexpr int stack_limit = 2048;	// size in bytes
template<typename T, int N>
constexpr bool Stackable() // T is regular and N elements of T can fit on a small stack
{
	return Regular<T>() && sizeof(T) * N <= stack_limit;
}
