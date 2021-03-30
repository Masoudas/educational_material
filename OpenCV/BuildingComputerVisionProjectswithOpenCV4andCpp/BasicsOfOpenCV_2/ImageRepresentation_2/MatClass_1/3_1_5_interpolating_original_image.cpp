/**
 * As mentioned earlier, a copied image (whether whole copy and in particular a sub matrix of the original image)
 * contains enough information about the original matrix header (through the datastart and dataend fields.) The
 * following methods tells us the size of the original matrix, as well as a set of offset points indicating the
 * location of the current ROI. 
 *
 *      -   void cv::Mat::locateROI(Size& wholeSize, Point&	ofs) const
 *      Locates the matrix header within a parent matrix.
 *      After you extracted a submatrix from a matrix using Mat::row, Mat::col, Mat::rowRange, Mat::colRange, and 
 *      others, the resultant submatrix points just to the part of the original big matrix. However, each submatrix 
 *      contains information (represented by datastart and dataend fields) that helps reconstruct the original 
 *      matrix size and the position of the extracted submatrix within the original matrix. The method locateROI 
 *      does exactly that. 
 *      -   wholeSize   :	Output parameter that contains the size of the whole matrix containing this as a part.
 *      -   ofs         :   Output parameter that contains an offset of this inside the whole matrix. 
 *
 * 
 */

#include <opencv2/core.hpp>
#include <iostream>

void extracting_info_of_original_image(){
    cv::Mat o{5, 5, CV_16U, cv::Scalar::all(0)};
    cv::Mat cp{o, cv::Rect{2, 2, 1, 2}};

    cv::Size size{};    // integer size
    cv::Point point{};  // integer 2D point.
    cp.locateROI(size, point);

    std::cout << "Size of the original matrix is (" << size.width << ", " << size.height << ")\n"; 
    std::cout << "Location of the copy ROI is (" << point.x << ", " << point.y << ")\n"; 
}

// int main(){
//     extracting_info_of_original_image();
// }