/*
* Note that when overloading operators in a class, binary operators require one parameter. This
* is because the other parameter is the class instance. However, if we're overloading the operator
* as an stand-alone operation (not belonging to any class), we need two parameters for binary operators.
*/
class Matrix {
	Matrix& operator+(const Matrix&){}	// Using only one parameter for binary operation.
};

// As an stand-alone operation, we need to overload with two parameters.
Matrix operator+(const Matrix& a, const Matrix& b) {
	Matrix m{};
	return m;
}