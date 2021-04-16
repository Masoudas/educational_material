/**
 * Here's something to recall. Whereas we can easily read (and convert) color images into grayscale ones using
 * the imread method, the converse is not true. That is, a grayscale image cannot be easily converted to a color
 * image, and we need certain precautions, and coloring methods for that.
 * 
 * In fact, this is one of those rare occasions in which imread throws an exception.
 */

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

void cant_convert_gray_to_rgb_with_read(){
    auto gray_read_as_color = cv::imread("Images/Rose-gray.jpg", cv::IMREAD_COLOR);

    cv::imshow("gray image", gray_read_as_color);
    cv::waitKey(0);
}

//int main(){
//    cant_convert_gray_to_rgb_with_read();
//}