/**
 * Question: How does one set a Blue, or Green or Red plane to a particular value in a BGR image?
 * 
 * Several solutions come to mind of course. In what follows we shall observe each separately. In what follows,
 * we shall try and set the red plane to zero, and compare the methods.
 * 
 * Pay a special attention to the reshape method. In it, we first reshape our image into one with a single 
 * channel, with as many rows as rows*cols. This would imply that now each column represents one plane.
 * Hence, by getting a reference to a particular column, we can set to the value we seek. The method, however,
 * is surprisinly longer than the split-merge or the pointer method.
 * 
 * Well, split merge seems to be much faster than using a pointer. However, note that split merge uses twice
 * as much memory.
 */

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>
#include <iostream>

using namespace cv;
using namespace std::chrono;

// Is about .3milisec
void use_split_merge(cv::Mat& img){
    Mat bgr[3] = {{}, {}, {}};

    split(img, bgr);
    bgr[2] = 0;     // Jeez! I first said bgr[3] = 0, and it didn't complain a bit!
    merge(bgr, 3, img);
}

// Assume that we know the image is uchar
// It takes longer at .460milisec!!!
void using_ptr(cv::Mat& img){
    int rows = img.rows, cols = img.cols;

    if (img.isContinuous()){
        cols *= rows;
        rows = 1;
    }

    for (int i = 0; i < rows; ++i){
        auto ptr = img.ptr<uchar>(i) + 2;
        for (int j = 0; j < cols; ++j){
            *ptr = 0;
            ptr += 3;
        }
    }
}

// Longest method, with 1.1milisec

void reshape_and_set(cv::Mat& img){
    img.reshape(1, img.rows * img.cols).col(2).setTo(Scalar(0));
}

int main(){
    auto img = imread("Images/Rose.jpg");

    auto b = std::chrono::steady_clock::now();
    using_ptr(img);
    auto e = std::chrono::steady_clock::now();

    microseconds elapsed_s = duration_cast<microseconds>(e-b);   // Because std clock is in nano seconds
    std::cout << "Elapsed time is: " << elapsed_s.count() << '\n';

    imshow("", img);
    waitKey(0);
}

