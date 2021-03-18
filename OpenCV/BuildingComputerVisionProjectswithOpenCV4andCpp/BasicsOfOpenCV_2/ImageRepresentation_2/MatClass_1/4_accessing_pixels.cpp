/**
 * Indexes begin from 0, right?
 * 
 * We use the at() methods to access the elements of an image. Note that all overloads of this method return by
 * reference, meaning we can access the pixel using these elements.
 */

#include <opencv2/core.hpp>
#include <iostream>

void accessing_pixels_of_uint_1c_image(){
    cv::Mat m{2, 2, CV_8U, cv::Scalar(0)};

    m.at<uchar>(0,0) = 0; m.at<uchar>(0,1) = 1; m.at<uchar>(1,0) = 2; m.at<uchar>(1,1) = 3;

    std::cout << m;
    std::cout << '\n';
}

int main(){
    accessing_pixels_of_uint_1c_image();
}