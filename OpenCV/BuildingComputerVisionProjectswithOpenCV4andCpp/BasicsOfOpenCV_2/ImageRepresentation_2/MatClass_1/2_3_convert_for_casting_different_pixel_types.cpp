/**
 * A very handy method of cv::Mat is the convertTo method, which allow us to convert this to any matrix we desire.
 *      -   void cv::Mat::convertTo(OutputArray m, int rtype, double alpha = 1, double beta = 0) const 
 *          Converts an array to another data type with optional scaling. The method converts source pixel values 
 *          to the target data type. saturate_cast<> is applied at the end to avoid possible overflows:
 *          m(x,y)=saturate_cast<rType>(α(∗this)(x,y)+β)
 *          Note that rtype need only to indicate the pixel type, as the dimension of the output matrix must be
 *          equal to the input.
 *
 * Question: Should we convert matrices in plance? Yes, it's fine. This is because the argument is not reference.
 * Hence, when we pass the matrix, a new matrix is created, leaving the old one to keep the underlying data. 
 * Therefore, the original data remain intact.
 *
 */

#include <opencv2/core.hpp>
#include <iostream>

void convert_schar_to_float(){
    cv::Mat m{2, 2, CV_8SC2, cv::Scalar(-10, 0)};
    m.convertTo(m, CV_32FC2, 1, .2);     // Convert to new matrix in place.

    std::cout << m;
}

// int main(){
//     convert_schar_to_float();
// }