/**
 *  -   Scalar cv::mean(InputArray src, InputArray mask = noArray()) 	
 * Calculates the mean of the ENTIRE src. Hence, if it's a matrix, calculates the mean of the entire matrix,
 * and not for example a row or column. If multi-channel, calculates over each channel.
 * 
 * Especially, pay attention to how we calculate the mean of an RGB image, if we needed to for some ungodly
 * reason.
 */

#include <opencv2/imgproc.hpp>
#include <iostream>

void make_and_calculate_mean(){
    signed char d[] = {-2, -1, 0, 1, 1, 2};
    cv::Mat img{2, 3, CV_8S, d};

    cv::Mat mask = (img < 2) & (img > -2);    
    auto mean_value = cv::mean(img, mask);

    std::cout << mean_value;
}

void mean_bgr_image(){
    using namespace cv;
    Mat bgr{3, 3, CV_8SC3, Scalar(0, 0, 0)};

    auto ptr = bgr.ptr<char>();
    for (int i = 0; i < bgr.total() * 3; i++){
        ptr[i]=i; 
    }

    auto mean_bgr = mean(bgr);
    std::cout << "Mean of BGR image b=" << mean_bgr[0] << " g=" << mean_bgr[1] << " r=" << mean_bgr[2];

    auto reshaped = bgr.reshape(1, bgr.total());  
    std::cout << "\nMean of overall image =" << mean(reshaped)[0] << "\n";
}

//int main(){
//    mean_bgr_image();
//}