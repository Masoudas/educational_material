/**
 * As was the case with the at method, to access a higher order image, we only need to get the pointer in a proper
 * manner. Once again, note that if the image is continous, we can easily access the entire image through one ptr,
 *
 * In the following example, we access the third dimension of the image directly with a pointer. 
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

void pointer_to_3d_image_example(){
    int sz[] = {2, 3, 4};   // Two images of 3 * 4.
    cv::Mat m(3, sz, CV_16U);   // Dealing with a 16 bit unsigned image.

    m.at<ushort>(1, 2, 0) = 1; m.at<ushort>(1, 2, 1) = 2; m.at<ushort>(1, 2, 2) = 3; m.at<ushort>(1, 2, 3) = 4;

    ushort* ptr = m.ptr<ushort>(1,2,0); // Naturlisch, we wanted to pointer to this location. 
    for (int i = 0; i < 4; i++){
        std::cout << "Pixel " << i << " is " << *ptr++ << "\n";
    }
}

// int main(){
//     pointer_to_3d_image_example();
// }