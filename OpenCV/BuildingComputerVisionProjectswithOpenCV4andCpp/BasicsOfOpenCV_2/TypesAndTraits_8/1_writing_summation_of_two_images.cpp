/**
 * We start this section by trying to write an addition operator between two images.
 * 
 * The question is how can we get a proper pointer to the matrix element? An obvious and rudimentary
 * approach is to get the element_type of a matrix, and then use that to set the proper pointer. But
 * note that doing so can't be done at compile time. Moreover, if we have a for loop, we have to have
 * this if expression inside the loop, which is just disasterous.
 * 
 * I don't actually think we can do such an operation at compile-time. This is because the Mat class
 * is not created until run-time, hence we can't determine the type until run-time. Hence, all we can do
 * is to write a templated operator, which accepts the element depths by hand. This is also the approach
 * I've seen in many of the examples on the OpenCV website, like for example 6_2_2, in
 * chapter 2, section 2, MatClass_1.
 * 
 * To ensure that the result of summation does not overflow, we use saturate cast, which we shall discuss
 * in the documentations.
 * 
 * As a final note, gcc throws an exception because it finds one + operator with ADL and one in the global
 * namespace. In fact the standard says "Name lookup rules make it impractical to declare operators in 
 * global or user-defined namespace that operate on types from the std namespace, e.g. a custom 
 * operator>> or operator+ for std::vector or for std::pair (unless the element types of the vector/pair 
 * are user-defined types, which would add their namespace to ADL). Such operators would not be looked 
 * up from template instantiations, such as the standard library algorithms."
 */
#include <opencv2/core.hpp>
#include <iostream>

// Not setting one argument to const& on purpose, because in many examples in OpenCV docs, they don't do 
// either, because Mat is very light.
template<typename T>
cv::Mat operator+(cv::Mat lhs, cv::Mat rhs){ 
    std::cout << "Summing two matrices\n";
    CV_Assert(rhs.size == lhs.size && lhs.depth() == rhs.depth());
    CV_Assert(rhs.isContinuous() == lhs.isContinuous());    // For the sake of argument.
    CV_Assert(lhs.dims < 3 && rhs.dims < 3);    // Both images are at most two dimensional.

    auto result = lhs.clone();  // Simply clone this.

    // One pointer is enough for both.
    auto p_rhs = rhs.ptr<T>();
    auto p_result = result.ptr<T>();
    
    for (int i = 0; i < lhs.total() * lhs.channels(); i++){
        *p_result++ = cv::saturate_cast<T>(*p_result + *p_rhs++);
    }

    return result;
}

// A wrapper to not see the template parameter
cv::Mat operator+(const cv::Mat& lhs, cv::Mat rhs){
    if (lhs.depth() == CV_16U){
        return operator+<ushort>(lhs, rhs);
    }

    return lhs;
}

//int main(){
//    cv::Mat m1{2, 2, CV_16UC2, cv::Scalar(7, 4)};   // Complex image of 7+4j
//
//    // We need to resolve the ambiguity here.
//    auto r = ::operator+(m1, m1);
//    std::cout << r;   
//}