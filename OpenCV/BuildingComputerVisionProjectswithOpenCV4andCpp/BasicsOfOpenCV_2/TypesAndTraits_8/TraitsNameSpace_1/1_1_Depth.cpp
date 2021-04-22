/**
 * The openCV documentation states:
 
 template<typename _Tp>
 class cv::DataDepth< _Tp >

 * A helper class for cv::DataType.
 * The class is specialized for each fundamental numerical data type supported by OpenCV. It provides 
 * DataDepth<T>::value constant. 
 * 
 * Note that depth once again is not number of chars, but rather the CV_nSU macros. Hence for example 
 * the depth for short and ushort is not the same.
 */
#include <opencv2/core.hpp>
#include <iostream>

template<typename T>
int get_depth(){
    return cv::traits::Depth<T>::value;
}

//int main(){
//    std::cout << "depth of ushort is " << get_depth<int>()
//        << "\nand depth of short is the same and " << get_depth<short>() << '\n';
//        << "\nand depth of uint is greater and is " << get_depth<int>;
//}