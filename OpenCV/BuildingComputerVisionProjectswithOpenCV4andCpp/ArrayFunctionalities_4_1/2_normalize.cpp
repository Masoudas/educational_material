/**
 * Me: Essentially, with NORM_MINIMAX brings min to alpha and max to beta. With other norms, ensures that the
 * vector has norm equal to alpha.
 * 
 * Me: The way it works with MINIMAX is that it first shifts the values, then applies a scale.
 * 
 *  -   void cv::normalize(InputArray src, InputOutputArray dst, double alpha = 1, double beta = 0,
 *		int norm_type = NORM_L2, int dtype = -1, InputArray mask = noArray())
 * 
 *      Normalizes the norm or value range of an array.
 *      The function cv::normalize normalizes scale and shift the input array elements so that 
 *                                  ||dst||_L_p = alpha
 * 
 *      (where p=Inf, 1 or 2) when normType=NORM_INF, NORM_L1, or NORM_L2, respectively; or so that:
 *                                  min_I(dst(I)) = alpha, max_I(dst(I)) = beta
 *    
 *      when normType=NORM_MINMAX (for dense arrays only). The optional mask specifies a sub-array to be 
 *      normalized. This means that the norm or min-n-max are calculated over the sub-array, and then this 
 *      sub-array is modified to be normalized. If you want to only use the mask to calculate the norm or 
 *      min-max but modify the whole array, you can use norm and Mat::convertTo
 * 
 *      Note: With negative numbers, the numbers are indeed shifted up so that they are from the range alpha
 *      to beta, if alpha is positive.
 */

#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;
void normalization_examples(){
    vector<double> positiveData = { 2.0, 8.0, 10.0 };
    vector<double> normalizedData_l1, normalizedData_l2, normalizedData_inf, normalizedData_minmax;

    // Norm to probability (total count)
    // sum(numbers) = 20.0
    // 2.0      0.1     (2.0/20.0)
    // 8.0      0.4     (8.0/20.0)
    // 10.0     0.5     (10.0/20.0)
    normalize(positiveData, normalizedData_l1, 1.0, 0.0, NORM_L1);
    
    // Norm to unit vector: ||positiveData|| = 1.0
    // 2.0      0.15
    // 8.0      0.62
    // 10.0     0.77
    normalize(positiveData, normalizedData_l2, 1.0, 0.0, NORM_L2);
    
    // Norm to max element
    // 2.0      0.2     (2.0/10.0)
    // 8.0      0.8     (8.0/10.0)
    // 10.0     1.0     (10.0/10.0)
    normalize(positiveData, normalizedData_inf, 1.0, 0.0, NORM_INF);
    
    // Norm to range [0.0;1.0]
    // 2.0      0.0     (shift to left border)
    // 8.0      0.75    (6.0/8.0)
    // 10.0     1.0     (shift to right border)
    // Note : I checked extensively. alpha=0,beta=1 returns the same result.
    normalize(positiveData, normalizedData_minmax, 1.0, 0.0, NORM_MINMAX);
    
}

int main(){
    normalization_examples();
}