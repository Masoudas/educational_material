/**
 * The RNG class is used for generating all sorts of random numbers and filling output arrays.
 * 
 * It has a nested enum which sets the type of random number to be generated, that has values UNIFORM = 0,
 * NORMAL = 1.
 * 
 * We can set the initial state with the constructor, though we usually leave it alone.
 * 
 *      -   cv::RNG::RNG() 	
 *      -   cv::RNG::RNG(uint64) 	
 *      -   void cv::RNG::fill(InputOutputArray mat, int distType, InputArray a, InputArray b, 
 *               bool saturateRange = false)
 *          -   mat:	2D or N-dimensional matrix; currently matrices with more than 4 channels are not supported 
 *                      by the methods, use Mat::reshape as a possible workaround. 
 *          -   distType:   Either NORMAL or UNIFORM
 *          -   a:  First distribution parameter (either mean or minvalue)
 *          -   b:  Second distribution parameter (either std or maxvalue)
 *          -   saturateRange	pre-saturation flag; for uniform distribution only; if true, the method will 
 *              first convert a and b to the acceptable value range (according to the mat datatype) and then 
 *              will generate uniformly distributed random numbers within the range [saturate(a), saturate(b)), 
 *              if saturateRange=false, the method will generate uniformly distributed random numbers in the 
 *              original range [a, b) and then will saturate them, it means, for example, that 
 *              theRNG().fill(mat_8u, RNG::UNIFORM, -DBL_MAX, DBL_MAX) will likely produce array mostly filled 
 *              with 0's and 255's, since the range (0, 255) is significantly smaller than [-DBL_MAX, DBL_MAX).
 *          Each of the methods fills the matrix with the random values from the specified distribution. As 
 *          the new numbers are generated, the RNG state is updated accordingly. In case of multiple-channel 
 *          images, every channel is filled independently, which means that RNG cannot generate samples from 
 *          the multi-dimensional Gaussian distribution with non-diagonal covariance matrix directly. To do 
 *          that, the method generates samples from multi-dimensional standard Gaussian distribution with zero 
 *          mean and identity covariation matrix, and then transforms them using transform to get samples from 
 *          the specified Gaussian distribution. 
 * 
 *      -   next():
 *          The method updates the state using the MWC algorithm and returns the next 32-bit random number. 
 *          (Me: We want to use the cast methods for this purpose, rather than next.) Note that this does
 *          not have any mean or std association. It's just a random number.
 * 
 *      -   uniform(min_v,max_v):
 *          A series of overload methods for getting uniform random numbers. So if we pass min_v and max_v
 *          as double, we get double random number, if float we get float, etc.
 * 
 *      -   gaussian(sigma):
 *          Returns the next random number sampled from the Gaussian distribution. Me: Notice that with this
 *          method, we can define a sigma for the random number, but no mean! Perhaps just an offset is fine.
 */

#include <opencv2/core.hpp>
#include <iostream>

void generate_rand_number(){
    cv::RNG rng{};

    auto d_v = (double)rng();
    auto f_v = (float)rng();    // Next random number.
}

void generating_uniform_random_number(){
    cv::RNG rng;
    
    // always produces 0
    double a = rng.uniform(0, 1);
    
    // produces double from [0, 1)
    double a1 = rng.uniform((double)0, (double)1);
    
    // produces float from [0, 1)
    float b = rng.uniform(0.f, 1.f);
    
    // produces double from [0, 1)
    double c = rng.uniform(0., 1.);
    
    // may cause compiler error because of ambiguity:
    //  RNG::uniform(0, (int)0.999999)? or RNG::uniform((double)0, 0.99999)?
    // double d = rng.uniform(0, 0.999999); Ahh! Error because should 0 be considered int or double?!
}

void generating_gaussian_random_number(){
    cv::RNG rng;
    
    // always produces 0
    double a = rng.gaussian(0);
    
    double a1 = rng.gaussian(10) + 1;   // Has a mean of 1.
}

void fill_with_gaussian(){
    cv::Mat noise{3, 3, CV_8S, cv::Scalar(0)};

    cv::RNG rng{};
    rng.fill(noise, cv::RNG::NORMAL, cv::Scalar(0), cv::Scalar(100));   // Fill matrix with rand dist of zero
                                                                        // ,eam amd std 100.

    std::cout << noise << "\n";
}

//int main(){
//    fill_with_gaussian();
//}