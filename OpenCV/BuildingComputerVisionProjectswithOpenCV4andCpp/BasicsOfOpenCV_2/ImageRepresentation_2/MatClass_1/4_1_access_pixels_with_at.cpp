/**
 * We can access a reference to the pixels of an image through the at method, where the index starts from zero.
 * Given the returned value is a reference, we can manipulate the underlying image as such.
 * 
 * The discussion below is limited to 2D images. See next the discussion on how to access multi-channel images.
 *      -   _Tp& cv::Mat::at(int row, int col) 	
 *      The template methods return a reference to the specified array element. For the sake of higher performance, 
 *      the index range checks are only performed in the Debug configuration.
 * 
 *      Keep in mind that the size identifier used in the at operator cannot be chosen at random. It depends on 
 *      the image from which you are trying to retrieve the data. The table below gives a better insight in this:
 *          --  If matrix is of type CV_8U then use Mat.at<uchar>(y,x).
 *          --  If matrix is of type CV_8S then use Mat.at<schar>(y,x).    
 *          --  If matrix is of type CV_16U then use Mat.at<ushort>(y,x). 
 *          --  If matrix is of type CV_16S then use Mat.at<short>(y,x).    
 *          --  If matrix is of type CV_32S then use Mat.at<int>(y,x).    
 *          --  If matrix is of type CV_32F then use Mat.at<float>(y,x).    
 *          --  If matrix is of type CV_64F then use Mat.at<double>(y,x).
 *      Note from me: The reason why we can't do this is because of pointer conversion, which would be discussed
 *      next.
 * 
 * Note: We also have the following single parameter methods (apart from const methods):
 *      -   _Tp& cv::Mat::at(int i0 = 0) 	
 *      This method is a special case, and it's used to access row or column images, so that we wouldn't have to 
 *      write at(0,i) or at(j,0).    
 */

#include <opencv2/core.hpp>
#include <iostream>

void accessing_pixels_of_uint_single_channel_image(){
    cv::Mat m{2, 2, CV_8U, cv::Scalar(0)};

    m.at<uchar>(0,0) = 0; m.at<uchar>(0,1) = 1; m.at<uchar>(1,0) = 2; m.at<uchar>(1,1) = 3;

    std::cout << m;
    std::cout << '\n';
}

// int main(){
//     accessing_pixels_of_uint_1c_image();
// }