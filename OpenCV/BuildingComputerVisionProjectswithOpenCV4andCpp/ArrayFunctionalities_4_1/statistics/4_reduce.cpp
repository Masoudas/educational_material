/**
 * Reduce as we recall is the operation of reducing a collection to a single element.
 * 
 *  -   void cv::reduce(InputArray src,	OutputArray dst, int dim, int rtype, int dtype = -1)
 *      *   src -	input 2D matrix.
 *      *   dst -	output vector. Its size and type is defined by dim and dtype parameters.
 *      *   dim	-   dimension index along which the matrix is reduced. 0 means that the matrix is reduced to 
 *                  a single row. 1 means that the matrix is reduced to a single column.
 *      *   rtype   -	reduction operation that could be one of ReduceTypes
 *      *   dtype	-   when negative, the output vector will have the same type as the input matrix, otherwise, 
 *                      its type will be CV_MAKE_TYPE(CV_MAT_DEPTH(dtype), src.channels()). 	
 * 
 * The reduce flags provided by OpenCV are:
 *    - enum cv::ReduceTypes {
 *           cv::REDUCE_SUM = 0,  
 *           cv::REDUCE_AVG = 1,  
 *           cv::REDUCE_MAX = 2,  
 *           cv::REDUCE_MIN = 3}
 * 
 * Note: While we're here, don't forget that we can reduce using std::Algorithm library as well.
 */

#include <opencv2/core.hpp>

void reduction_to_sum(){
    using namespace cv;

    Mat m = (Mat_<uchar>(3,2) << 1,2,3,4,5,6);  // This is an interesting initialization notation.
    Mat col_sum, row_sum;
    reduce(m, col_sum, 0, REDUCE_SUM, CV_32F);  // The first dimension is always the columns [a,b,c].
    reduce(m, row_sum, 1, REDUCE_SUM, CV_32F);  // The second is always rows [[a,b,c],[d,e,f]].
    /*
    m =
    [  1,   2;
        3,   4;
        5,   6]
    col_sum = [9, 12]
    row_sum = [3; 7; 11]*/  // Thankfully, the matrix remains a row matrix.
}

void reduction_to_min_and_max(cv::Mat m){
    using namespace cv;

    double min, max;    // Ok, values are random.
    minMaxIdx(m, &min, &max);   // As we recall, we could possibly get the locations as well.

    Mat col_min, row_min;
    reduce(m, col_min, 0, REDUCE_MIN, -1);  // Min of each column.
    reduce(m, row_min, 1, REDUCE_MIN, -1);  // Min of each row.


}