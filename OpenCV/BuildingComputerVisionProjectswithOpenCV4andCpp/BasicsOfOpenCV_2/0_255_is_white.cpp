/**
 * One point that I should not forget is that 255 is always white in BGR images. When we create an image by
 * default, we don't expect it to show white, we expect it to show black. This is why a blank image is black
 * rather than white!
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(){
    cv::Mat img{512, 512, CV_8UC3, cv::Scalar{0,0,0}}; // Black image of course.

    cv::circle(img, {255, 255}, 40, {255, 255, 255});

    cv::imshow("White circle", img);
    cv::waitKey(0);
}
