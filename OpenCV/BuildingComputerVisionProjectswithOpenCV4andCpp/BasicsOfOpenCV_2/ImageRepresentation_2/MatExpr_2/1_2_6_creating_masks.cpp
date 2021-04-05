/**
 * We can create simple masks using logical operations on images. For example, we can and or Or two images to
 * figure out which elements are non-empty.
 * 
 * Of particular interest are the spaceship operations, which allow us to generate masks based on value comparison.
 */

#include <opencv2/core.hpp>
#include <iostream>

void create_masks_with_logical_ops(){
    cv::Mat m1{2, 2, CV_64F, cv::Scalar(1)};
    auto m2 = m1.clone(); 

    auto ptr = m2.ptr<double>();
    ptr[0] = 1; ptr[1] = 0; ptr[2] = 0; ptr[3] = 1;

    std::cout << "Anding two matrices leads: \n";
    std::cout << (m1 & m2);

    std::cout << "\nOring two matrices leads: \n";
    std::cout << (m1 | m2);
}

void create_masks_with_comparison_ops(cv::Mat& m1, cv::Mat& m2){
    auto leq_mask = m1 <= m2;   // Where m1 is less than equal m2.

    auto value_mask = m1 < 50;
    auto abs_diff_mask = cv::abs(m1 - m2) < 10;

}

//int main(){
//    create_masks_with_logical_ops();
//}