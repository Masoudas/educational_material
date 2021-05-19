/**
 * Often, we want to add noise to our matrices in order to test the performance of algorithms under noise. This
 * is where methods like randn come in handy, as we discuss below.
 * 
 *  -   void cv::randn(InputOutputArray dst, InputArray mean, InputArray stddev)
 *      Fills the array with normally distributed random numbers.
 *      The function cv::randn fills the matrix dst with normally distributed random numbers with the specified 
 *      mean vector and the standard deviation matrix. The generated random numbers are clipped to fit the 
 *      value range of the output array data type.
 * 
 *      -   Parameters
 *          *    dst	output array of random numbers; the array must be pre-allocated and have 1 to 4 
 *                      channels.
 *          *    mean	mean value (expectation) of the generated random numbers.
 *          *    stddev	standard deviation of the generated random numbers; it can be either a vector 
 *               (in which case a diagonal standard deviation matrix is assumed) or a square matrix.  	
 *      (Me: The problem is that we don't have control over the seed.)
 *      
 * 
 * Note: Notice how the random number is generated for an iid matrix. We only supply a mean and std for all 
 * the entires, and the random matrix is generated. If we were seeking a non-iid generator from a Gaussian
 * distro, then we'd have to recall the famous 1/sqrt(2pi) * exp(XS^-1X^T). But I couldn't get the example
 * to work. 
 * 
 * Finally, note that as opposed to using a matrix as mean and std values, the standard uses scalars to take
 * care of it.
 */

#include <opencv2/core.hpp>
#include <iostream>

// Note that we usually want the noise matrix to be negative as well as positive. Note however with addition,
// we saturate to min and max values of each type.
auto non_standard_generating_iid_random_number(){
    cv::Mat noise{2, 2, CV_8S, cv::Scalar(0)};
    auto means = (cv::Mat)cv::Mat::zeros(1, 1, CV_8S);
    auto stds = (cv::Mat)cv::Mat::ones(1, 1, CV_8S) * 20;

    cv::randn(noise, means, stds);

    return noise;
}

auto standard_generating_iid_random_numbers(){
    cv::Mat noise{2, 2, CV_8S, cv::Scalar(0)};
    cv::randn(noise, cv::Scalar::all(0), cv::Scalar::all(16));

    return noise;
}

// Does not work right now.
cv::Mat generating_non_iid_random_number(){
    cv::Mat noise{2, 2, CV_8S, cv::Scalar(0)};
    auto means = (cv::Mat)cv::Mat::zeros(2, 1, CV_8S);
    auto stds = (cv::Mat)cv::Mat::ones(2, 2, CV_8S) * 20;

    cv::randn(noise, means, stds);

    return noise;
}

int main(){
    auto noise = standard_generating_iid_random_numbers();

    std::cout << noise;
}