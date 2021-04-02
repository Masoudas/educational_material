/**
 * We can create simple masks using logical operations on images. For example, we can and or Or two images to
 * figure out which elements are non-empty.
 */

#include <opencv2/core.hpp>
#include <iostream>

void create_masks(){
     cv::Mat m1{2, 2, CV_64F, cv::Scalar(1)};
    auto m2 = m1.clone(); 

    auto ptr = m2.ptr<double>();
    ptr[0] = 1; ptr[1] = 0; ptr[2] = 0; ptr[3] = 1;

    std::cout << "Anding two matrices leads: \n";
    std::cout << (m1 & m2);

    std::cout << "\nOring two matrices leads: \n";
    std::cout << (m1 | m2);
}

int main(){
    create_masks();
}