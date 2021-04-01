/**
 * The following are examples of matrix addition, multiplication, subtraction, etc. Note that for multi-channel
 * images, all channels are added to one another, and saturated if necessary.
 * 
 * As always, note that for such operations, no direct conversion to MatExpr classes is required, unless we want
 * to keep the result and do more complicated ops.
 *
 * Regarding multiplication and division, we should once again recall that * is the normal mat multiplication and
 * mul is the element-wise multiplcation. Note that / is an element-wise division. Moreover, if saturation may
 * occur and is important to us, we might as well convert our matrices to a suitable higher type.
 */

#include <opencv2/core.hpp>
#include <iostream>

void add_images(){
    cv::Mat m1{1, 2, CV_8UC2, cv::Scalar(255)};
    *m1.ptr<uchar>() = 1;

    auto m2 = m1.clone();

    std::cout << "The summation of mats leads:\n";
    std::cout << m1 + m2;

    std::cout << "\nThe subtration of mats leads:\n";
    std::cout << 2*m1 - m2 << '\n';

}

void multiply_matrices(){
    cv::Mat m1{2, 2, CV_64F, cv::Scalar(1)};
    auto m2 = m1.clone(); 

    auto ptr = m2.ptr<double>();
    ptr[0] = 1; ptr[1] = 0; ptr[2] = 0; ptr[3] = 1;

    std::cout << "Normal matrix multiplication leads: \n";
    std::cout << m1 * m2;

    std::cout << "\nWhereas element-wise multiplication leads:\n";
    std::cout << m1.mul(m2);
}

int main(){
    multiply_matrices();
}