/**
 * There's two other overloads of the function given below. The point however is that both of these functions
 * accept a cn parameter. 
 * 
 *  -   Mat cv::Mat::reshape(int cn, int newndims, const int* newsz) const
 */

#include <opencv2/core.hpp>
#include <iostream>

void reshape_higher_order_to_two_dim_images(){
    int sz[] = {2, 3, 4};
    cv::Mat m1{3, sz, CV_16U, cv::Scalar{0}};    

    // Reshaping higher order mat into lower one.
    int new_sz[] = {3, 8};
    auto new_m = m1.reshape(1, 2, new_sz);

    std::cout << "\nThe reshaped matrix is has " << new_m.rows << " rows and " << new_m.cols << " columns"
    << "and has " << new_m.channels() << " channel\n\n";
}

//int main(){
//    reshape_higher_order_to_two_dim_images();
//}