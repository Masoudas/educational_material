/**
 * In these examples, we create new headers for sections of the image, which allow us to work with those sections,
 * or index them from zero for example.
 *
 * Note that the method cv::Mat::isSubmatrix() returns true if a matrix is in fact a sub-matrix.
 */

#include <opencv2/core.hpp>
#include <iostream>
void creating_sub_images(cv::Mat& o){
    cv::Mat sub1{o, cv::Rect{10, 10, 100, 100}};    // Using the copy constructor
    cv::Mat sub2{o, cv::Range{10, 111}, cv::Range{10, 111}};    // Using range, copy from ro 10 to 111 exclusive.

    cv::Mat sub3 = o(cv::Range::all(), cv::Range(1,4));    // Copy all the rows, but only three columns.
    std::cout << "\n(rows,columns)=(" << sub3.rows << "," << sub3.cols << ")\n\n";

    cv::Mat sub4{};
    sub4 = o(cv::Rect{10, 10, 100, 100});    // Using the assignment operator!
}

// int main(){
//     cv::Mat sub1(200, 200, CV_16U, cv::Scalar::all(0));    // Using the copy constructor
//     creating_sub_images(sub1);
// }

