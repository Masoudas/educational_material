/**
 * How do we create a matrix of higher dimensions? Consider the following example:
 
int dims[] = {1, 3, 5}; // 1 plane, every plane has 3 rows and 5 columns
mat.create(3, dims, CV_32FC1); // for 3-d mat, it MUST have only 1 channel

 * We can see that the dims vector follows the same convention as the usual dimensionality holds, which is
 * {nth_dim, (n-1)th_dim, ..., 3rd_dim, 2nd_dim, 1st_dim}.
 * 
 * The documentation clearly states that a higher dimension image must set the number of channels to one.
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

void print_row_columns_dim(const cv::Mat& m, int* size, int sz_len)
{
    std::cout << "\n\nFor a matrix of size: ";
    for (int i = 0; i < sz_len; i++) std::cout << size[i] << "  ";

    std::cout << "\nNumber of rows and columns is: (" << m.rows << "," << m.cols << ")\n";
    std::cout << "\nNumber of dimensions is: " << m.dims;
    std::cout << "\nNumber of channels is: " << m.channels();

    cv::MatStep step = m.step;
    std::cout << "\n\nAnd the step vector is: ";
    for (int i = 0; i < sz_len; i++) std::cout << step[i] << '\t';

    cv::MatSize m_size = m.size;
    std::cout << "\n\nAnd the size vector is: ";
    for (int i = 0; i < m_size.dims(); i++) std::cout << m_size[i] << '\t';

}

// Let us first consider the proper ways of creating such matrices. We shall discuss the effects of setting channel
// non-one
void creating_higher_dim_matrices(){
    int sz_1[] = {2, 2};
    cv::Mat m_1{2, sz_1, CV_8U, cv::Scalar::all(0)};    // This is our normal 2D image.
    print_row_columns_dim(m_1, sz_1, 2);

    int sz_2[] = {3, 4, 5}; // Three planes of four rows and five columns.
    cv::Mat m_2{3, sz_1, CV_8U, cv::Scalar::all(0)};    // This is our normal 2D image.
    print_row_columns_dim(m_2, sz_2, 3);
    
}

