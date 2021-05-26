/**
 *  -   void cv::max(std::initializer_list<_Tp>)
 *  Passing a couple of ints or floats results in calculating the max among a list as such. Note that because
 *  this is not a constructor, we use braces.
 * 
 *  -   void cv::max(InputArray src1, InputArray src2, OutputArray dst)
 *  Calculates per-element maximum of two arrays or an array and a scalar. 
 * 
 *  -   void cv::max(const Mat&	src1, const Mat& src2, Mat& dst) 	
 *  Another convenience method.
 *  
 * How do we calculate the max of a matrix? Those kind of operations can be done with the reduce function.
 */

#include <opencv2/core.hpp>

void max_between_scalars(){
    using namespace cv;
    max({1, 2, 3, 4});

    Mat element_max{};
    max(Mat{}, Mat{});

    
}