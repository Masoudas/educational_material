#include <opencv2/highgui.hpp>

// In this exercise, we shall prove that RGB images are read as BGR.
void setting_red_of_rose_to_zero(){
    auto rose_original = cv::imread("Images/Rose.jpg", cv::IMREAD_UNCHANGED);   // Read as colored image.

    // Recall that colored im.
    auto rose_no_red = rose_original.clone();
    auto ptr = rose_no_red.ptr<uchar>();

    // Recal that total = rows * cols. Convery every third byte.
    for (int i = 2; i < rose_no_red.total() * 3; i+=3 ){
        *(ptr + i) = 0;
    }

    std::string orig_label = "Original Rose";
    std::string no_red_label = "No Red Rose";

    cv::namedWindow(orig_label, cv::WINDOW_FREERATIO); cv::namedWindow(no_red_label, cv::WINDOW_FREERATIO);
    cv::imshow(orig_label, rose_original); cv::imshow(no_red_label, rose_no_red);
    cv::waitKey(0);
}

int main(){
    setting_red_of_rose_to_zero();
}