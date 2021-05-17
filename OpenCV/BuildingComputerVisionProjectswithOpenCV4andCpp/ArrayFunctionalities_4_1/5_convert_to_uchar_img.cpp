/**
 * Often, it's the case that we want to convert the result of an operation which is in float or other types
 * into an 8 bit unsigned image. Note that we can't do this with the convert method of image, because that
 * method does not calculate the absolute value, hence converting signed values to unsigned values causes
 * a problem with the saturate cast of those methods.
 * 
 * The method we seek is called convertScaleAbs.
 * 
 *      -   void cv::convertScaleAbs(InputArray src, OutputArray dst, double alpha = 1,	double beta = 0) 	
 *      Scales, calculates absolute values, and converts the result to 8-bit.
 *      
 *      On each element of the input array, the function convertScaleAbs performs three operations 
 *      sequentially: scaling, taking an absolute value, conversion to an unsigned 8-bit type:
 *                      dst(I)=saturate_cast<uchar>(|src(I)*alpha+beta|)
 * 
 * In case of multi-channel arrays, the function processes each channel independently. When the output is not 
 * 8-bit, the operation can be emulated by calling the Mat::convertTo method (or by using matrix expressions) 
 * and then by calculating an absolute value of the result. For example:
 * 
 * Mat_<float> A(30,30);
 * randu(A, Scalar(-100), Scalar(100));
 * Mat_<float> B = A*5 + 3;     // Will allocate temporary memory here.
 * B = abs(B);
 * 
 * In the example below, we see that it converts {-100, -1, 0, 1, 100} to {100, 1, 0, 1, 100}.
 */
#include <opencv2/imgproc.hpp>
#include <iostream>

int main(){
    short d[] = {-100, -1, 0, 1, 100};  /
    cv::Mat m{5, 1, CV_16S, d};

    cv::Mat m_8bit{};
    cv::convertScaleAbs(m, m_8bit);

    std::cout << m_8bit;
}