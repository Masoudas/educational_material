/**
 * This is a list of implemented matrix operations that can be combined in arbitrary complex expressions (here A, B 
 * stand for matrices ( Mat ), s for a scalar ( Scalar ), alpha for a real-valued scalar ( double )):
 *
 *  Note from me: These are not member functions!
 * 
 *  -    Addition, subtraction, negation: A+B, A-B, A+s, A-s, s+A, s-A, -A
 *  -    Scaling: A*alpha
 *  -    Per-element multiplication and division: A.mul(B), A/B, alpha/A
 *  -    Matrix multiplication: A*B
 *  -    Transposition: A.t() (means AT)
 *  -    Matrix inversion and pseudo-inversion, solving linear systems and least-squares problems: A.inv([method]) 
 *       (~A<sup>-1</sup>), A.inv([method])*B (~X: AX=B)
 *  -    Comparison: A cmpop B, A cmpop alpha, alpha cmpop A, where cmpop is one of >, >=, ==, !=, <=, <. The 
 *       result of comparison is an 8-bit single channel mask whose elements are set to 255 (if the particular 
 *       element or pair of elements satisfy the condition) or 0.
 *  -    Bitwise logical operations: A logicop B, A logicop s, s logicop A, ~A, where logicop is one of &, |, ^.
 *  -    Element-wise minimum and maximum: min(A, B), min(A, alpha), max(A, B), max(A, alpha)
 *  -    Element-wise absolute value: abs(A)
 *  -    Cross-product, dot-product: A.cross(B), A.dot(B)
 *  -    Any function of matrix or matrices and scalars that returns a matrix or a scalar, such as norm, mean, sum, 
 *       countNonZero, trace, determinant, repeat, and others.
 *  -    Matrix initializers ( Mat::eye(), Mat::zeros(), Mat::ones() ), matrix comma-separated initializers, matrix 
 *       constructors and operators that extract sub-matrices (see Mat description).
 *  -    Mat_<destination_type>() constructors to cast the result to the proper type. 
 *
 * Question: Is MatExpr a view of the original matrix? Yes! Note that through the constructor of MatExpr, we can
 * convert a Mat into a MatExpr. Moreover, MatExpr has an implicit cast to Mat. Once the cast operation takes place,
 * the new matrix is ready for use.
 * What's implied here is that we can make as many complicated expressions as we desire, and once we convert to Mat,
 * then that new mat is generated. Note that each cast to Mat generates a new underlying structure, which is quite
 * interesting!
 * 
 */

#include <opencv2/core.hpp>
#include <iostream>

void MatExpr_is_a_view(){
    cv::Mat m{2,2, CV_8U, cv::Scalar::all(1)};
    cv::Mat m1{2,2, CV_8U, cv::Scalar::all(3)};

    auto result_matExpr = m.mul(m1);

    std::cout << "The original matrix is: \n";
    std::cout << m;

    std::cout << "\nThe multiplied matrix is \n";
    std::cout << result_matExpr;

    auto result_ptr = ((cv::Mat&)result_matExpr).ptr<uchar>();
    if (m.ptr<uchar>() != result_ptr && m1.ptr<uchar>() != result_ptr)
    {
        std::cout << "\n\nNote that the pointer is not the same for the three mats\n";
    }
    
    cv::Mat result_2 = result_matExpr;  // A new cast to Mat does not generate a new matrix.
    if (result_2.ptr<uchar>() != result_ptr){
        std::cout << "Result of new cast produces a new data structure.\n\n";
    }
}
Structure of Matexpr. Then some examples on expressions.
// int main(){
//     MatExpr_is_a_view();
// }