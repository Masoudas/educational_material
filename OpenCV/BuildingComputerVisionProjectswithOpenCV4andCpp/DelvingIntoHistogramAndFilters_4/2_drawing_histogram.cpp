/**
 * In this exercise, we shall draw the histogram of an RGB image as continuous lines. 
 * 
 * Note that the calcHis function of openCV can be used to calculate the histogram of a gray image, and
 * there's no equivalent one for a colored image. 
 * 
 * Moreover, there's no function to draw the histogram in openCV. For this end, we need to draw the graph
 * of histogram values using the line function ourselves.
 * 
 * Hence, here are the steps we need to take to calculate and draw the histogram:
 *      [1] Split the image into RGB
 *      [2] Calculate the histo for each channel
 *      [3] Create a new image to draw the histo inside. Assume that it's 512 to 512.
 *      [4] Each histogram value has a range that possibly exceeds 512. Normalize the histogram vals
 *          (which are between 0 to 1) using the normalize function.
 *      [5] Now, use the line function to draw each segement of the histogram in the image.
 *
 */
#include <opencv2/imgproc.hpp>

std::vector<cv::Mat> calculate_histogram(const cv::Mat& m){
    CV_Assert(m.channels() == 3);

    cv::Mat planes[3] = {{}, {}, {}}; 
    cv::split(m, planes);

    int numbins= 256; 
    float range[] = {0, 256} ; 
    const float* histRange = {range}; 
 
    std::vector<cv::Mat> hists{{},{},{}};

    // Note that mask is given as empty matrix, meaning don't mask!
    // Also notice that plane is given as reference.
    calcHist(&planes[0], 1, 0, cv::Mat(), hists[0], 1, &numbins, &histRange ); 
    calcHist(&planes[1], 1, 0, cv::Mat(), hists[1], 1, &numbins, &histRange ); 
    calcHist(&planes[2], 1, 0, cv::Mat(), hists[2], 1, &numbins, &histRange ); 

    return hists;
}

void draw_histogram(std::vector<cv::Mat>& hist_planes){
    cv::normalize(hist_planes[0], hist_planes[0], 0, 512, cv::NormTypes::NORM_MINMAX);
    cv::normalize(hist_planes[1], hist_planes[0], 0, 512, cv::NormTypes::NORM_MINMAX);
    cv::normalize(hist_planes[2], hist_planes[0], 0, 512, cv::NormTypes::NORM_MINMAX);
    ??
}