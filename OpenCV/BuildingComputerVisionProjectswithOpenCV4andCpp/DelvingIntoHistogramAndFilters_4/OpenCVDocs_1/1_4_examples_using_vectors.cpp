/**
 * Using vectors simplifies the notations of the previous examples. The only quirk here is that there's no
 * implicit conversion of a single image to ArrayOfArrays, and we need to explicitly use a std::vector!
 */

#include <opencv2/imgproc.hpp>
#include <iostream>

void hist_2D_gray_image(){
    uchar vals[] = {1, 1, 255, 255};
    cv::Mat img{2, 2, CV_8UC1, vals};  // Default is 8 bit gray.   

    cv::Mat histogram{};    // Resulting histogram

    // Calculate over channel 1, with 2 bins from 0 to 256 exlusive.
    cv::calcHist(std::vector{img}, {0}, cv::Mat{}, histogram, {2}, {0, 256});

    std::cout << histogram;
}

void hist_of_multiple_images(){
    // Same as hist_2D_gray_image.
    uchar vals[] = {1, 1, 255, 255};
    cv::Mat img1{2, 2, CV_8UC1, vals};
    cv::Mat img2{2, 2, CV_8UC1, vals}; 

    cv::Mat histogram;

    cv::calcHist(std::vector{img1, img2}, {0}, cv::Mat{}, histogram, {2}, {0, 256});
}

void hist_along_single_channel(){
    uchar vals[] = {1, 127, 255, 1, 127, 255};
    cv::Mat img{1, 1, CV_8UC3, vals};

    cv::Mat hist{};

    // Along channel 2
    cv::calcHist(std::vector{img}, {1}, cv::Mat{}, hist, {2}, {0, 256});
    std::cout << hist;
}

// Making 3D hist of channel 1 and channel 2.
void two_dim_hist(){
    uchar vals[] = {1, 255, 255, 1};
    cv::Mat img{2, 1, CV_8UC2, vals};

    cv::Mat histogram{};
    cv::calcHist(std::vector{img}, {0, 1}, cv::Mat{}, histogram, {2, 2}, {0, 256, 0, 256});

    std::cout << histogram << '\n';
}

int main(){
    two_dim_hist();
}