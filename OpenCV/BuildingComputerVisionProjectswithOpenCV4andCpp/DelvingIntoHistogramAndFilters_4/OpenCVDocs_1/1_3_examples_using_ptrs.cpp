/**
 * In what follows, we shall calculate the histogram for a serious of common cases (that I can think of!)
 */

#include <opencv2/imgproc.hpp>
#include <iostream>

void hist_2D_gray_image(){
    uchar vals[] = {1, 1, 255, 255};
    cv::Mat img{2, 2, CV_8UC1, vals};  // Default is 8 bit gray.   

    int nImgs = 1;
    int dim = 1;    // A 1 dim histogram
    const int channels[] = { 0 };   // Channels must start at 0.

    const int nbins[1] = {2};  // Number of bins.
    const float range_d1[] = {0, 256};  // Range of values among dimension 1. Last range is 0 to 256 exclusive.
    const float* ranges[] = {range_d1}; // Accumulation of all ranges.

    cv::Mat mask{};         // An empty matrix for mask, meaning no mask.
    cv::Mat histogram{};    // Resulting histogram

    cv::calcHist(&img, nImgs, channels, cv::Mat{}, histogram, dim, nbins, ranges);

    std::cout << histogram;
}

void hist_of_multiple_images(){
    // Same as hist_2D_gray_image.
    uchar vals[] = {1, 1, 255, 255};
    cv::Mat images[2] = {{2, 2, CV_8UC1, vals},{2, 2, CV_8UC1, vals}}; 

    //...
}

void hist_along_single_channel(){
    uchar vals[] = {1, 127, 255, 1, 127, 255};
    cv::Mat img{1, 1, CV_8UC3, vals};

    int nbins = 3;
    int channel = 1;    // This would be the second channel, not channel 1
    const float range_d1[] = {0, 256};
    const float* ranges[]{range_d1};

    cv::Mat hist{};
    cv::calcHist(&img, 1, &channel, cv::Mat(), hist, 1, &nbins, ranges);
    std::cout << hist;
}

// Making 3D hist of channel 1 and channel 2.
void two_dim_hist(){
    uchar vals[] = {1, 255, 255, 1};
    cv::Mat img{2, 1, CV_8UC2, vals};

    int nbins[] = {2, 2};
    int channels[] = {0, 1};    // First and second channel
    const float range_d1[] = {0, 256};
    const float* ranges[]{range_d1, range_d1};  // We need to ranges

    cv::Mat histogram{};
    cv::calcHist(&img, 1, channels, cv::Mat{}, histogram, 2, nbins, ranges);

    std::cout << histogram << '\n';
}


int main(){
    two_dim_hist();
}