/**
 * As the book discusses, "Image equalization, or histogram equalization, tries to obtain a histogram with a 
 * uniform distribution of values. The result of equalization is an increase in the contrast of an image. 
 * Equalization allows lower local contrast areas to gain high contrast, spreading out the most frequent 
 * intensities. This method is very useful when the image is extremely dark or bright and there is a very small 
 * difference between the background and foreground. Using histogram equalization, we increase the contrast and 
 * the details that are over- or under-exposed. This technique is very useful in medical images, such as X-rays.
 * 
 * However, there are two main disadvantages to this method: the increase in background noise and a consequent 
 * decrease in useful signals."
 * 
 * Normally, we prefer to use a HSV or a YCrCb (Y is the luma component and CB and CR are the blue-difference and 
 * red-difference chroma components (chroma red, chroma blue). Less reduntant than RGB, used for transmission.)
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

void equalize_lumina(Mat img){
    // Convert color space to YCrCb
    Mat yCrCb{};

    cvtColor(img, yCrCb, COLOR_BGR2YCrCb);

    std::vector<Mat> y_Cr_Cb{};  // yCrCb planes.

    split(yCrCb, y_Cr_Cb);
    equalizeHist(y_Cr_Cb[0], y_Cr_Cb[0]);

    merge(y_Cr_Cb, yCrCb);

    cvtColor(yCrCb, img, COLOR_YCrCb2BGR);
}

void equalize_saturation(Mat img){
    // Convert color space to HSV
    Mat hsv{};

    cvtColor(img, hsv, COLOR_BGR2HSV);

    std::vector<Mat> h_s_v{};  // hsv planes.

    split(hsv, h_s_v);
    equalizeHist(h_s_v[1], h_s_v[1]);

    merge(h_s_v, hsv);
    cvtColor(hsv, img, COLOR_HSV2BGR);
}

void equalize_luminance_two_way(){
    auto rose = imread("Images/Rose.jpg");

    auto rose_yCrCb = rose.clone();
    equalize_lumina(rose_yCrCb);


    auto rose_hsv = rose.clone();
    equalize_saturation(rose_hsv);

    namedWindow("Rose", WINDOW_GUI_EXPANDED);
    namedWindow("Rose-YCrCb", WINDOW_GUI_EXPANDED);
    namedWindow("Rose-HSV", WINDOW_GUI_EXPANDED);
    imshow("Rose", rose);
    imshow("Rose-YCrCb", rose_yCrCb);
    imshow("Rose-HSV", rose_hsv);
    waitKey(0);
}

int main(){
    equalize_luminance_two_way();
}