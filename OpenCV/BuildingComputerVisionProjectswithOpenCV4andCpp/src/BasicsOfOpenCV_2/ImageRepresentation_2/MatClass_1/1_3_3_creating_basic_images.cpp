/**
 * Now that we know how to feed the define the pixel resolution and the number of channels, it's time to build a
 * matrix.
 * 
 * The constructor of the Mat that we use here are these:
 *      - 	Mat (int rows, int cols, int type)
 *  	-   Mat (Size size, int type)
 *      -   Mat (int rows, int cols, int type, const Scalar &s)
 *      -   Mat (Size size, int type, const Scalar &s)
 * 
 * Note that mat can be effortlessly streamed (it has a operator<<.) We can use it to print the content of the image
 * we've created.
 */
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
https://docs.opencv.org/master/d6/d6d/tutorial_mat_the_basic_image_container.html
void create_sample_matrix(){
    cv::Mat m1{1, 1, cv::CV_8UC3, cv::Scalar{0,0,255}};

    std::cout << m1;
}

int main(){
    create_sample_matrix();
}