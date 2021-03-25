/**
 * -    depth:
 * The method returns the identifier of the matrix element depth (the type of each individual channel). For example, 
 * for a 16-bit signed element array, the method returns CV_16S . A complete list of matrix types contains the 
 * following values:
 * 
 *  -   CV_8U - 8-bit unsigned integers ( 0..255 )
 *  -   CV_8S - 8-bit signed integers ( -128..127 )
 *  -   CV_16U - 16-bit unsigned integers ( 0..65535 ) 
 *  -   CV_16S - 16-bit signed integers ( -32768..32767 )
 *  -   CV_32S - 32-bit signed integers ( -2147483648..2147483647 )
 *  -   CV_32F - 32-bit floating-point numbers ( -FLT_MAX..FLT_MAX, INF, NAN )
 *  -   CV_64F - 64-bit floating-point numbers ( -DBL_MAX..DBL_MAX, INF, NAN )
 * 
 * Me: Note that we don't measure depth in terms of the bits, to distinguish between signed and unsigned values.
 */

#include <opencv2/core.hpp>
#include <iostream>

void getting_depth(){
    cv::Mat m{2, 2, CV_8U, cv::Scalar::all(0)};
    std::cout << "depth of 8 bit unsigned image is " << m.depth() << '\n';  // Would be 0 and not 1 (standing for one
                                                                        // byte.)
    
    cv::Mat m1{2, 2, CV_16S, cv::Scalar::all(0)};
    std::cout << "depth of 16 bit unsigned image is " << m1.depth() << '\n'; // Would be 3, and not 2 (standing for
                                                                        // two bytes.)

    cv::Mat m2{2, 2, CV_32F, cv::Scalar::all(0)};
    std::cout << "depth of 32 bit float image is " << m2.depth() << '\n'; // Would be 5, rather than 4.
}

// int main(){
//     getting_depth();
// }