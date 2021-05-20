/**
 * A question that may arise here is can we sum a signed and unsigned matrix? The answer is no. This is because
 * the documentations indicate both matrices must have the same type.
 * 
 * Hence, we're left with an actuall loop together with saturation to add noise. 
 * 

 */

#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;

void sum_signed_and_unsigned(){
    Mat m1{2, 2, CV_8S, Scalar(-10)};
    Mat m2{2, 2, CV_8U, Scalar(5)}; 

    //m1 = m1 + m2;   // Error! What's being cast to what? unsigned to signed or vice versa!   
    auto ptr = m2.ptr<uchar>();

    // For loop.
}