/**
 * Me: Note that because the underlying data structure is (often) just a simple pointer, and the pixels are
 * stored consequtively, we can reinterpret the dimension of the image as we see fit. The purpose of reshape
 * is to change the header of the matrix structure, and not actually reshaping the matrix! As always, because
 * this method works with channels and rows, we can't use it for higher order (>=3) matrices. But overload that
 * we discuss next can work with matrix of arbitrary dimensions.
 * 
 * The documentation states:
 *      -   Mat cv::Mat::reshape(int cn, int rows = 0) const
 *          -- cn: New number of channels. If the parameter is 0, the number of channels remains the same. 
 *          -- rows: New number of rows. If the parameter is 0, the number of rows remains the same. 
 *  
 *          Changes the shape and/or the number of channels of a 2D matrix without copying the data.
 *          The method makes a new matrix header for *this elements. The new matrix may have a different size 
 *          and/or different number of channels. Any combination is possible if:
 * 
 *          -   No extra elements are included into the new matrix and no elements are excluded. Consequently, 
 *              the product rows*cols*channels() must stay the same after the transformation.     
 *          -   No data is copied. That is, this is an O(1) operation. Consequently, if you change the number of 
 *              rows, or the operation changes the indices of elements row in some other way, the matrix must be 
 *              continuous. See Mat::isContinuous.
 * 
 *          For example, if there is a set of 3D points stored as an STL vector, and you want to represent the 
 *          points as a 3xN matrix, do the following: 
 * 
 *          %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *          std::vector<Point3f> vec;
 *          ...
 *          Mat pointMat = Mat(vec). // convert vector to Mat, O(1) operation
 *                          reshape(1). // make Nx3 1-channel matrix out of Nx1 3-channel.
 *                                      // Also, an O(1) operation
 *                             t(); // finally, transpose the Nx3 matrix.
 *                                  // This involves copying all the elements
 *          %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 */

#include <opencv2/core.hpp>

void reshape_to_single_channel(){
    cv::Mat m1{3, 3, CV_16UC3, cv::Scalar{0}};    // An image with 3 channels.

    auto single_channel = m1.reshape(1);    // Now, this would be a single channel image with equal number of   
                                            // rows. Can be used with algorithms that require single channel.
    
    auto single_channel_single_row = m1.reshape(1, 1);  // One channel and row.
}