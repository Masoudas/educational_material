/**
 * The thing to recall about LUTs is that we can't apply them to floats. They can only be applied to discrete
 * intensities. Besides that, apparently OpenCV lets LUTs to be used only for 8 bit images.
 * 
 * The OpenCV documentation of LUT specifies:
 * 
 *      -   void cv::LUT(InputArray src, InputArray lut, OutputArray dst)
 * Performs a look-up table transform of an array.
 * The function LUT fills the output array with values from the look-up table. Indices of the entries are 
 * taken from the input array. That is, the function processes each element of src as follows:
 *
 *                          dst(I) <-- lut(src(I) + d)
 * where:
 *                  d = { 0 if src has depth CV_8U, 128 if src has depth CV_8S 	
 * 
 * Me: The latter implies the value -128 is read from the 0th element of the LUT, -127 from first, so forth.
 * 
 * In the following example, we apply the famous 1 / ( 1 + exp(-x + 0.5)/s) to an image. Notice that we used
 * the LUT function to directly apply this transformation to a color image. This is also possible by split
 * merge pattern. This algorithm is referred to as lomography.
 */

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

void mapping_darker_to_darker_light_to_lighter(cv::Mat img, float scale=0.1){
    using Pixel = Point3_<uchar>;
    Mat LUT_mat{256, 1, CV_8UC3, Scalar(0)};  //The look up table is a row matrix in our case.    

    const double exponential_e = std::exp(1.0);
    for (int i = 0; i < 256; i++){
        float index = i / 256.0F; // Don't forget to convert to float when dividing by float.
        auto exponent = 1 / (1 + pow(exponential_e, (-index + 0.5) / scale));   
        LUT_mat.at<Pixel>(i) = { exponent * 255, exponent * 255, exponent * 255};
    }

    std::cout << LUT_mat;

    Mat enhanced_img{};
    LUT(img, LUT_mat, enhanced_img);

    imshow("Original Image", img);
    imshow("Enhanced Image", enhanced_img);
    waitKey(0);
}

int main(){
    auto lena = imread(samples::findFile("lena.jpg"));  // By default, reads as color image.
    mapping_darker_to_darker_light_to_lighter(lena);
}