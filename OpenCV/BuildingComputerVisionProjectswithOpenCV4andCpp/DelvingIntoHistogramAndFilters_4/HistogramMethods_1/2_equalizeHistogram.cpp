/**
 *  -   void cv::equalizeHist(InputArray src, OutputArray dst)
 *  Equalizes the histogram of a grayscale image.
 *  The function equalizes the histogram of the input image using the following algorithm:
 *      -    Calculate the histogram H for src .
 *      -    Normalize the histogram so that the sum of histogram bins is 255.
 *      -    Compute the integral of the histogram:
 *                                  H'i=sum_0_i{H(j)}
 *  Transform the image using H′ as a look-up table: dst(x,y)=H'(src(x,y))
 *  The algorithm normalizes the brightness and increases the contrast of the image.
 * 
 * Recall that y-axis of histogram is frequency. Imagine the sum of frequencies is 255. Now, the cdf of the image
 * leads to a distribution that increases till reaching peak at 255, with value being 255. Hence, a mapping of 
 * the pixels from the x axis of this histogram (old pixel brightness) to new values (y-axis) causes more
 * contrast, because we're using a sloped line which maxes out at 225.
 * 
 * Me: We can equivalently apply the method for 3D images.
 */

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void equalize_gray(){
    auto base = cv::imread("Images/Rose.jpg", cv::IMREAD_GRAYSCALE);  

    cv::Mat enhanced{};
    cv::equalizeHist(base, enhanced);

    cv::namedWindow("base", cv::WINDOW_GUI_NORMAL);
    cv::namedWindow("enhanced", cv::WINDOW_GUI_NORMAL);

    cv::imshow("base", base);
    cv::imshow("enhanced", enhanced);

    cv::waitKey(0);
}

void equalize_color(){
    auto base = cv::imread("Images/Rose.jpg"); // Default is color 8 bit.

    std::vector<cv::Mat> brg = { {}, {}, {}};
    cv::split(base, brg);

    for (int i = 0; i < 3; i++){
        cv::equalizeHist(brg[i], brg[i]);
    }

    cv::Mat enhanced{};
    cv::merge(brg, enhanced);

    cv::namedWindow("base", cv::WINDOW_GUI_NORMAL);
    cv::namedWindow("enhanced", cv::WINDOW_GUI_NORMAL);

    cv::imshow("base", base);
    cv::imshow("enhanced", enhanced);

    cv::waitKey(0);
}

int main(){
    equalize_color();
}