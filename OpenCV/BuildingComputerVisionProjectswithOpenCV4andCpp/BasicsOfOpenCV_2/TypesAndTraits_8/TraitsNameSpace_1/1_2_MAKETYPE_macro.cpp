/**
 * I bring the CV_MAKETYPE here just for convenience, to show its relation to depth trait.
 * The depth macros such as CV_nSUCn are made using the CV_MAKETYPE macro. Hence, if we have access to
 * the depth at compile time, we can generate the macro. The macro takes two arguments, namely depth
 * and channel (cn):
 *                                      #define CV_MAKETYPE(depth,cn)
 * 
 */

#include<opencv2/core.hpp>

template<typename T, int Channel>
constexpr int create_type_macro_from_depth(){
    return CV_MAKETYPE(cv::traits::Depth<T>::value, Channel);
}

void comparing_types(){
    assert((create_type_macro_from_depth<ushort, 3>()) == CV_16UC3);
    assert((create_type_macro_from_depth<uchar, 2>()) == CV_8UC2);
}

//int main(){
//    comparing_types();
//}