/**
* This is a very tricky topic.
* 
* Consider the following example. First observe the definition of the operator*, which is used for
* multiplying a vector with a matrix down below. This is a templated operator, and fair enough.
* 
* Now, we want to make this operator a friend of both Matrix and Vector. As we can see below, 
* we don't declare the friend operator with the template. We just pass our parameters. But notice the
* empty <> after the operator name. Why is it there? Bjarne says:
* 
* Friends do not affect the scope in which the template class is defined, nor do they affect the scope
* in which the template is used. Instead, friend functions and operators are found using a lookup
* based on their argument types (§14.2.4, §18.2.5, §iso.11.3). Like a member function, a friend function 
* is instantiated only if it is used (§26.2.1).
* 
* (Me: I understand the first part. friends don't affect the scope. But what is that have to do with 
* anything?
*/

template<typename T> class Matrix;
template<typename T>
class Vector {
	T v[4];
public:
	// friend Vector operator*<>(const Matrix<T>&, const Vector&) {}; Bjarne version. Notice that only Matrix has
																     // a templated parameter, and not Vector,
	
};

template<typename T>
class Matrix {
	Vector<T> v[4];
public:
	// friend Vector<T> operator*(const Matrix&, const Vector<T>&) {}; Bjarne version. Notice that only Matrix has
				// a templated parameter, and not Vector. It does not work however.

	// friend Matrix<T> operator*<>(const Matrix<T>& m, const Vector<T>& v); Again, this version is 
				// recommended over the internet, but does not work.

	// friend Matrix<T> operator*(const Matrix<T>& m, const Vector<T>& v); 
	friend Matrix operator*(const Matrix& m, const Vector<T>& v); // Version with type deduction.

};

template<typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v) {
	Vector<T> r = m.v;
	// ... use m.v[i] and v.v[i] for direct access to elements ...
	
	return r;
}

