/**
 * There are Matlab style initializers for creating matrices. These include 
 * 
 *  -   static MatExpr cv::Mat::eye(int	rows, int cols, int type)
 *      Returns an identity matrix of the specified size and type.
 *      The method returns a Matlab-style identity matrix initializer, similarly to Mat::zeros. 	
 * 
 *  -   static MatExpr cv::Mat::eye(Size size, int type)
 *      An overload for creating an arbitrary size.
 * 
 *  -   zeros
 *      Same signature and overloads as eye.
 * 
 *  -   ones
 *      Same signature and overloads as eye.
 */

#include <opencv2/core.hpp>
#include <iostream>

void creating_float_identity_of_arbitrary_value(){
    cv::Mat m = cv::Mat::eye(10, 10, CV_64FC1) * 0.8;   

    std::cout << m;
}

// Not that this really matters in practice, but in case we were interested.
void only_the_first_channel_is_set_to_one(){
    cv::Mat m = cv::Mat::eye(2, 2, CV_8UC3) * 255;   

    std::cout << m;
}

int main(){
    creating_float_identity_of_arbitrary_value();
}