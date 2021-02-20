/**
 * Used for declaring the type from an expression. As opposed to auto, where type is
 * deduced from an initializer. Hence, we say:
 *  
 * decltype(expr) x, as opposed to int x;
 * 
 * For example, we might say 'decltype(T{} + U{}) f', which in an expression with
 * two templates T and U implies whatever is the sum of the two types!
 */

/** As another example, take this declaration. 
 * Suppose this method is to return the sum of two matrices. The point is that the return
 * type is unknown, and we can't simply write Matrix(U + T) in the beginning. Hence, we use
 * this expression. The reason why we use the suffix return type syntax is because we want 
 * to express the return type in terms of the arguments:Matrix<decltype(T{}+U{})>.   
 * That  is,  the  result  is  a Matrix with  the  element  type  being  whatyou get from 
 * adding a pair of elements from the argument Matrixes:T{}+U{}.
 * 
*/
template<typename T>
class Matrix {};

template<typename T, typename U>
auto operator+(const Matrix<T>&  a, const Matrix<U>&  b) -> Matrix<decltype(T{}+U{})>;

/**
 * In the definition, we again need to declare the type.*/
template<typename T, typename U>
auto operator+(const Matrix<T>&  a, const Matrix<U>&  b) -> Matrix<decltype(T{}+U{})>{
    decltype(Matrix<T{} + U{}>) res; // Because this is a custom type, it's initialized with default constructor.

    for (int i=0; i!=a.rows(); ++i)
        for (int j=0; j!=a.cols(); ++j)
            res(i,j) += a(i,j) + b(i,j);
    
    return res;
}