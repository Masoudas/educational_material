/**
 * How do we create a matrix of higher dimensions? We already mentioned that the convention is 
 * {..., cube, plane, row, column}. We need to feed this array as the size to cv::Mat, and that's the way to create
 * higher dimension images.
 * 
 * We must not forget to define the number of channels as one. We should also not forget that except for the
 * step variable and number of dimensions and size, none of the other dimensionality functions (including row, column
 * number of channels) work for such matrices.
 * 
 * As a final point, we must NEVER define a higher dimensional image with more than one channel. Hence, the image
 * type (or macro) must always be chosen from the ones that have no channel, like CV_8U or CV_64F, etc.
 * 
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

void print_row_columns_dim(const cv::Mat& m)
{
    std::cout << "\nNumber of dimensions is: " << m.dims;
    std::cout << "\nNumber of rows and columns is: (" << m.rows << "," << m.cols << ")\n";

    cv::MatStep step = m.step;
    std::cout << "\n\nAnd the step vector is: ";
    for (int i = 0; i < m.dims; i++) std::cout << step[i] << '\t';

    cv::MatSize m_size = m.size;
    std::cout << "\n\nAnd the size vector is: ";
    for (int i = 0; i < m_size.dims(); i++) std::cout << m_size[i] << '\t';

}

void creating_higher_dim_matrices(){
    int sz_2[] = {3, 4, 5}; // Three planes of four rows and five columns.
    cv::Mat m_2{3, sz_2, CV_8U, cv::Scalar::all(0)};    
    print_row_columns_dim(m_2);
}

// int main(){
//     creating_higher_dim_matrices();
// }
