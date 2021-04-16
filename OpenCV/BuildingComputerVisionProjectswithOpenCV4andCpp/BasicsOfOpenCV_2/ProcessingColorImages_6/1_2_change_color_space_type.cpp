/**
 * Note that in the same manner, we can convert the color space of the image.
 * 
 * Recall that imshow can only render BGR images, hence be careful not to show other color spaces using this 
 * function. Moreover, when we write it as HSV, then when we read once again, they'd also be interpreted as 
 * BGR, and HSV (however we know that the pixels are HSV, and not BGR.)
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

void change_color_space_to_HSV(){
    auto im_bgr = cv::imread("Images/Rose.jpg", cv::IMREAD_UNCHANGED);

    cv::Mat img_HSV{};
    cv::cvtColor(im_bgr, img_HSV, cv::COLOR_BGR2HSV);

    cv::imshow("HSV image", img_HSV);
    cv::waitKey(0);

    cv::imwrite("Images/Rose-HSV.png", img_HSV);
}

int main(){
    change_color_space_to_HSV();
}