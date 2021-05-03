/**
 * Imagine we want to draw a halo on a particular region of an image. That is, we want to accentuate a certain
 * region of an image, and then at the same time, make the region outside that point less transparent.
 * 
 * If we're talking about a gray image, we know that we can simply create an image that has values close to
 * 1 in the region we want, and close to 0 in the region we don't want, and then multiply the original image
 * with that. The point is that the image has to be float, so that the scaling is correct.
 * 
 * We can do the same thing with color images as well.
 */

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
void create_a_circle_halo(Mat img){
    cv::Mat halo{img.rows, img.cols, CV_32FC3, Scalar(1, 1, 1)};

    cv::circle(halo, {img.rows / 2, img.rows / 2}, 200, {0.3, 0.3, 0.3});  
    blur(halo, halo, {20, 20});  // Just a big blur   
    
    img.convertTo(img, CV_32FC3);
 //   img = img.mul(halo);
    multiply(img, halo, img);

    img.convertTo(img, CV_8UC3);

        imshow("halod lena", img);
    waitKey(0);
}

int main(){
    auto lena = samples::findFile("lena.jpg");
    auto img = imread(lena);

    create_a_circle_halo(img);

    ???
}