/**
* An ordinary member function declaration has three significances:
* [1] The function can access the private part of the class declaration
* [2] The function is in the scope of the class (recall that a class is essentially a namespace)
* [3] The function must be invoked on an object (has a this pointer)
* 
* By declaring a member function static (§16.2.12), we can give it the first two properties only. By declaring a non member
* function a friend, we can give it the first property only.  That is, a function declared friend is granted access to the
* implementation of a class just like a member function but is otherwise independent of that class.
* 
* Note that when declaring a function friend of another, the complete signature of the other function (including its
* return type) must be written after the friendship statement.
* 
* For example, the stand-alone operator* is declared a friend of both vector and matrix function, so as to allow it access
* to elements for multiplying a vector by a matrix.
* 
* Friends can be in the public or private part of the class, it makes no difference.
* Note also that a member function of a class can be a friend of another.
*/

constexpr int rc_max{ 4 }; // row and column size
class Matrix; 

class Vector {
	float v[rc_max];
	// ...
	friend Vector operator*(const Matrix&, const Vector&);
	// friend void Matrix::vector_friend(); Declaring this member function as friend, but commented because it's still
	// unknown in this context!
};

class Matrix {
	Vector v[rc_max];
	// ...
	friend Vector operator*(const Matrix&, const Vector&);

public:
	void vector_friend() {};
};

Vector operator*(const Matrix& m, const Vector& v) {
	Vector r{};
	for (int i = 0; i != rc_max; i++) { // r[i] = m[i] * v;
		r.v[i] = 0;
		for (int j = 0; j != rc_max; j++)
			r.v[i] += m.v[i].v[j] * v.v[j];
	}
	return r;
}

