/**
 * The last assignment operator that we need to discuss has the following syntax:
 * 
 *      -   Mat& cv::Mat::operator=(const Scalar&)
 *          Sets all or some of the array elements to the specified value.
 *
 * 
 */

#include <opencv2/core.hpp>

void assigning_to_an_RGB_image(){
    cv::Mat m{256, 256, CV_8UC3, cv::Scalar(125, 0, 255)};  // Assign to an R=125, G=0, B=255.

    m = cv::Scalar(0.5);
}