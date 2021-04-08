/** Me:
 * In this exercise, we shall convert an RGB image into an RGBA image, and then write it to disk. Note that
 * JPEG images can't represent an alpha channel, which is why the RBGA image has to be stored as PNG instead.
 * 
 * The method I used is quite simple, I read each pixel using a vector3i and vector4i, and then assign them to
 * one another.
 * 
 * Of course, there's always a method provisioned in OpenCV for such trivial task. In this case, we can convert
 * the color spaces using cvtColor, which stands for convert color.
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void methodI_using_vector(){
    auto original_img = cv::imread("Images/Rose.jpg", cv::IMREAD_UNCHANGED);

    cv::Size size{original_img.cols, original_img.rows};    // width=cols, height=rows
    cv::Mat alpha_img{size, CV_8UC4, cv::Scalar(1)};    // Create based on the size of the original image.

    // For fun!
    for (int row = 0; row < size.height; row++){
        for (int col = 0; col < size.width; col++){
            auto& po = original_img.at<cv::Vec3b>(row, col);
            auto& pa = alpha_img.at<cv::Vec4b>(row, col);

            pa[0] = po[0]; pa[1] = po[1]; pa[2] = po[2];
            pa[3] = 1;
        }
    }

    cv::imwrite("Images/Rose-alpha.png", alpha_img);

    // Recall that only if we read as IMREAD_UNCHANGED (and not COLOR) do we get all four channels.
    cv::imread("Images/Rose-alpha.png", cv::IMREAD_UNCHANGED).channels() == 4 ? std::cout << "Rose alpha has four channels\n" :
        std::cout << "Rose alpha does not have four channels\n";
}

void methodII_use_convert_method(){
    auto original_img = cv::imread("Images/Rose.jpg", cv::IMREAD_COLOR);
    cv::Mat alpha_img{original_img.rows, original_img.cols, CV_8UC4 };

    cv::cvtColor(original_img, alpha_img, cv::COLOR_BGR2BGRA);

    cv::imshow("Converted alpha image", alpha_img);
    cv::waitKey(0);

    alpha_img.channels() == 4 ? std::cout << "Converted image has four channels\n" : 
        std::cout << "Converted image has three channels\n";

}

//int main(){
//    methodI_using_vector();
//}