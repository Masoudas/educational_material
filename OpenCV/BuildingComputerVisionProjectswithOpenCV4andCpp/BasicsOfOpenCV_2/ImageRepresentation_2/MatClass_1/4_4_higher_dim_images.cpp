/**
 * Reminder: Once again, note that a multi-channel 2D image is not a higher dimensional image (dim=2.) Therefore,
 * this discussion is about images of higher dimensions.
 * 
 * Using the following overloads of the at method, we can access the pixels of a higher dimensional image:
 *      -   _Tp& cv::Mat::at(int i0, int i1, int i2)
 *          Convenience method for accessing 3D images.
 * 
 *      -  _Tp& cv::Mat::at(const int * idx	) 	
 *          Convenience method for accessing images of higher dimension.
 */

#include <opencv2/core.hpp>
#include <iostream>

void accessing_three_dim_image(){
    int sz[] = {2, 3, 4};
    cv::Mat m{3, sz, CV_8U};

    m.at<uchar>(0, 0, 0) = 1; m.at<uchar>(1, 0, 0) = 1; m.at<uchar>(1, 2, 3) = 1; m.at<uchar>(0, 2, 3) = 1;

    for (int i = 0; i < sz[0]; i++)
    {
        for (int j = 0; j < sz[1]; j++)
        {
            for (int k = 0; k < sz[2]; k++){
                std::cout << "Channel values at pixel (" << i << "," << j << "," << k << ") is ";
                std::cout << (int)m.at<uchar>(i,j,k) << "\n";
            }
        }
    }
    
}

void accessing_multi_dim_image(){
    int sz[] = {2, 3, 4, 5};
    cv::Mat m{4, sz, CV_8U};

    int p1[] = {0,0,0,0};
    m.at<uchar>(p1) = 1; 
}

// int main(){
//     accessing_three_dim_image();
// }