/**
 * The mat class defines several ops to allow for addition, multiplication, and other more complicated math ops.
 * The following are the ones from the mat matrix methods. As we can see, most of these methods return an object
 * called MatExpr, which we shall discuss next.
 *
 *      -   MatExpr cv::Mat::mul(InputArray	m, double scale = 1) const
 *          Performs an element-wise multiplication or division of the two matrices.
 *          The method returns a temporary object encoding per-element array multiplication, with optional scale. 
 *          Note that this is not a matrix multiplication that corresponds to a simpler "\*" operator.
 *          m: Must have same size and type as this.
 *
 *      Example:
 *          Mat C = A.mul(5/B); // equivalent to divide(A, B, C, 5) (me: divide A by B, scale by 5, set in C)
 *
 *      -   Mat cv::Mat::cross(InputArray m) const
 *          Computes a cross-product of two 3-element vectors.
 *          The method computes a cross-product of two 3-element vectors. The vectors must be 3-element 
 *          floating-point vectors of the same shape and size. The result is another 3-element vector of the same 
 *          shape and type as operands. 
 *          Note: Seriously, the two matrices must be 1*3! 
 *
 *      -   double cv::Mat::dot(InputArray m) const         # me: Note that it retuns a scalar.
 *          Computes a dot-product of two vectors.
 *          The method computes a dot-product of two matrices. If the matrices are not single-column or single-row 
 *          vectors, the top-to-bottom left-to-right scan ordering is used to treat them as 1D vectors. The vectors 
 *          must have the same size and type. If the matrices have more than one channel, the dot products from all 
 *          the channels are summed together. 
 *
 *      -   MatExpr cv::Mat::inv(int method = DECOMP_LU) const
 *          Inverses a matrix.
 *          The method performs a matrix inversion by means of matrix expressions. This means that a temporary 
 *          matrix inversion object is returned by the method and can be used further as a part of more complex 
 *          matrix expressions or can be assigned to a matrix. 
 *          Me: Seriously, stop thinking about dumb question. Nobody cares about the inverse of a three channel
 *          image, or the inverse of an image for that matter.
 *
 *      -   MatExpr cv::Mat::t() const
 *          Transposes a matrix.
 *          The method performs matrix transposition by means of matrix expressions. It does not perform the actual 
 *          transposition but returns a temporary matrix transposition object that can be further used as a part of 
 *          more complex matrix expressions or can be assigned to a matrix: 
 *          Mat A1 = A + Mat::eye(A.size(), A.type())*lambda;
 *          Mat C = A1.t()*A1; // compute (A + lambda*I)^t * (A + lamda*I)
 *
 */


