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
 */

#include <opencv2/core.hpp>

void reduction_to_sum(){
    using namespace cv;

    Mat m = (Mat_<uchar>(3,2) << 1,2,3,4,5,6);
    Mat col_sum, row_sum;
    reduce(m, col_sum, 0, REDUCE_SUM, CV_32F);
    reduce(m, row_sum, 1, REDUCE_SUM, CV_32F);
    /*
    m =
    [  1,   2;
        3,   4;
        5,   6]
    col_sum = [9, 12]
    row_sum = [3; 7; 11]*/
}

???????????????