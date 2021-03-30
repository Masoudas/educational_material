/**
* Specialization can be used to provide alternative implementations of a class template for a specific
* set of template parameters. In that case, a specialization can even provide a representation that 
* differs from that of the general template. (Me: Note that the big guy made a mistake here and specializes
* when defining the template signature, which is wrong!)
*/

template<typename T, int N>
class Matrix {}; // N-dimensional Matrix of Ts

template<typename T>
class Matrix<T, 0> { // specialization for N==1 (me: N=0, but this means trivial matrix)
	T val;
	// ...
};

template<typename T>
class Matrix<T, 1> { // specialization for N=1
	T* elem;
	int sz; // number of elements
	// ...
};
template<typename T>
class Matrix<T, 2> { // specialization for N=2
	T* elem;
	int dim1; // number of rows
	int dim2; // number of columns
	// ...
};