/**
 * From OpenCV docs:
 *      -   void cv::split(const Mat& src, Mat* mvbegin)
 *      Divides a multi-channel array into several single-channel arrays. 
 *      The function cv::split splits a multi-channel array into separate single-channel arrays:
 *      mv[c](I)=src(I)c
 *      
 *      If you need to extract a single channel or do some other sophisticated channel permutation, 
 *      use mixChannels .
 * 
 * Note from me: The extracted planes don't share anything with the original image.
 */

#include <opencv2/imgproc.hpp>
#include <iostream>

void splitting_color_image(){
    char data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    cv::Mat m{2, 2, CV_8UC3, data};

    cv::Mat planes[3] = { {}, {}, {}};
    cv::split(m, planes);

    // Equally we could write
    std::vector<cv::Mat> planes_2{};
    cv::split(m, planes_2);

    *planes[0].ptr<uchar>() = 20;

    std::cout << "Original image: " << m;
    std::cout << "Plane B:" << planes[0];
    std::cout << "\nPlane G" << planes[1];
    std::cout << "\nPlane R" << planes[2];
}

int main(){
    splitting_color_image();
}