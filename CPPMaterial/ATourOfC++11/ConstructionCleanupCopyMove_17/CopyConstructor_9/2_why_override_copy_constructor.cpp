/*
* Particularly if a class creates and holds some resources (with a pointer), we need to define custom copy operations
* to ensure that those are handled properly during copy operations.
* 
* For example, with the default copy constructor below, the elements of the matrix are not copied, but rather 
* the pointer is. Hence, trying to call the remove constructor on one matrix deletes the memory, and when the
* other one goes out of scope, an exception is thrown.
* 
* This is why we define a custom copy constructor and assignment here, copying the underlying resource of the pointer.
* We can see the implementation below.
* 
* Question: Why do we check matrix size in assignment? One argument here is that we're not supposed to allocate
* memory in the assignment operator. Hence, even though an arbitrary matrix might make sense, we refrain from it
* by checking dimension equality.
* 
* The assignment operation may throw an exception when copying an element. In that case, we have a matrix with half
* old and half new elements. To provide a strong gurantee that this does not happen, we can make a copy of the original
* matrix, then for example swap it with the current matrix. Funny thing is that with the implementation below, we use
* the std::swap(). If swap used the assignment operator (mat1 = mat2), then we'd have a had an infinite loop here.
* However, it does not! This will be discussed further in this chapter.
*/
#include <array>
#include <exception>
using namespace std;

template<class T>
class Matrix {
	array<int, 2> dim; // two dimensions
	T* elem; // pointer to dim[0]*dim[1] elements of type T
public:
	Matrix(int d1, int d2) :dim{ d1,d2 }, elem{ new T[d1*d2] } {} // simplified (no error handling)
	int size() const { return dim[0]*dim[1]; }
	Matrix(const Matrix&); // copy constr uctor
	Matrix& operator=(const Matrix&); // copy assignment
	Matrix(Matrix&&); // move constr uctor
	Matrix& operator=(Matrix&&); // move assignment
	~Matrix() { delete[] elem; }
	// ...
};

template<typename T>
Matrix<T>::Matrix(const Matrix& ref) : dim{ ref.dim }, elem{ ref.size()} {
	std::memcpy(elem, this->elem, sizeof(T) * ref.size());
	
}

// Weak copy, may end up with half-and-half matrix if exception is thrown.
//template<typename T>
//Matrix<T>& Matrix<T>::operator=(const Matrix<T>& ref) {
//	if (this->dim[0] != ref.dim[0] || this->dim[1] != ref.dim[1]) throw exception{};
//	memcpy(this->elem, ref.elem, sizeof(T) * ref.size());
//
//	return *this;
//}

// Strong guarantee copy. First copy the matrix, then swap it with our current matrix. 
// We can't move or copy again, but swap does work!
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& ref) {
	if (this->dim[0] != ref.dim[0] || this->dim[1] != ref.dim[1]) throw exception{};
	Matrix<T> matrix{ ref };
	swap(*this, matrix);
	return *this;
}