/**
 * There's also the randu function to generate a random number in a given range, with a uniform distribution
 * of course.
 * 
 *      -   void cv::randu(InputOutputArray dst, InputArray low, InputArray high)
 *          Generates a single uniformly-distributed random number or an array of random numbers.
 *          Non-template variant of the function fills the matrix dst with uniformly-distributed random  
 *          numbers from the specified range:
 *                                  low_c <= dst(I)_c < high_c
 *          Parameters:
 *          -    dst	output array of random numbers; the array must be pre-allocated.
 *          -    low	inclusive lower boundary of the generated random numbers.
 *          -    high	exclusive upper boundary of the generated random numbers.  		
 * 
 * 
 */

#include <opencv2/core.hpp>
#include <iostream>

cv::Mat iid_uniform_number(){
    cv::Mat uniform_noise{4, 4, CV_8S, cv::Scalar(0)};

    cv::randu(uniform_noise, cv::Scalar(-10), cv::Scalar(10));

    return uniform_noise;
} 

int main(){
    auto noise = iid_uniform_number();

    std::cout << noise << "\n";
}