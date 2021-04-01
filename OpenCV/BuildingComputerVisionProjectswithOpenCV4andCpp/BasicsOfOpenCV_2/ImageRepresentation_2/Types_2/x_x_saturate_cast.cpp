/**
 * This function is in the core/saturate.hpp module. The OpenCV documentation states that:

 * Template function for accurate conversion from one primitive type to another. The function saturate_cast 
 * resembles the standard C++ cast operations, such as static_cast<T>() and others. It perform an efficient and 
 * accurate conversion from one primitive type to another (see the introduction chapter). saturate in the name 
 * means that when the input value v is out of the range of the target type, the result is not formed just by taking 
 * low bits of the input, but instead the value is clipped. For example:
 *
 *      uchar a = saturate_cast<uchar>(-100); // a = 0 (UCHAR_MIN)
 *      short b = saturate_cast<short>(33333.33333); // b = 32767 (SHRT_MAX)

 * Such clipping is done when the target type is unsigned char , signed char , unsigned short or signed short. 
 * For 32-bit integers, no clipping is done.
 *
 */
#include <opencv2/core.hpp>
#include <iostream>

void conversion_to_short(){
    uchar saturated_high_int = cv::saturate_cast<uchar>(3333);  // Goes over 255, clips to 255.
    uchar saturated_low_int = cv::saturate_cast<uchar>(-100);   // Goes below 0, clips to 0.

    std::cout << "3333 after saturate cast to unsigned char becomes: " << (int)saturated_high_int << '\n';
    std::cout << "-100 after saturate cast to unsigned char becomes: " << (int)saturated_low_int << '\n';
}