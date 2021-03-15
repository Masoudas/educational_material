/**
 * The macros of the form:
 *      -   CV_nuC2   (n=8,16,32,64) (u=S,U,F)   
 * 
 * constitute a special form of image. Essentially, These are your typical complex images, and normally instead of 
 * 2 channel images are called complex images. 
 * 
 * To create an instance of such images, we can supply a particular 2 argument Scalar (a complex scalar), which
 * would initialize all the elements with the given COMPLEX value.
 * 
 */

#include <opencv2/core.hpp>
#include <iostream>

void creating_a_complex_image(){
    // 2*2 img, fill it with 1+7j
    cv::Mat c_im{2, 2, CV_8UC2, cv::Scalar(1,7)};   

    std::cout << c_im;
}

// int main(){
//     creating_a_complex_image();
// }