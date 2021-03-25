/**
 * As always, it's possible to iterate over the pixels of an image using an iterator. 
 *  
 *      -   MatIterator_<_Tp> cv::Mat::begin()
 *       	Returns the matrix iterator and sets it to the first matrix element.
 * 
 *          The methods return the matrix read-only or read-write iterators. The use of matrix iterators is very 
 *          similar to the use of bi-directional STL iterators 
 *          Me: Therefore, the iterators are not random access ones!
 *          
 *     -    MatConstIterator_<_Tp> cv::Mat::begin() const
 *          The corresponding constant iterator.
 * 
 * In what follows, we consider an alpha blending example from the openCV documentation. The method is pretty
 * straightforward. 
 *      (1)     We assert that both images have the same type, and same size, and that the type can be set in a
 *              four point vector.
 *      (2)     For the destination image, we create a new data equal to the size and type of the images.
 *      (3)     We get an iterator to the elements of the images.
 *      (4)     We blend the two images.
 * 
 * Note that the scaling formula is alpha/max_numeric and beta/max_numeric, which somewhat makes sense, considering
 * for example max value of 256 and alpha of 3 and 4 for the two images at a certain pixel, respectively.
 * 
 * What we should pay attention to is:
 *      (1) How we got the max value of the given image template
 *      (2) How we blend and then saturate, using the saturate cast.
 *      (2) Conversion of both pixel irrespectively to float and back for alpha blending (not doing it in
 *          int for example for an int image)
 */
#include <iostream>
#include <opencv2/core.hpp>
using namespace cv;

template<typename T>
void alphaBlendRGBA(const Mat& src1, const Mat& src2, Mat& dst)
{
    typedef Vec<T, 4> VT;
    const float alpha_scale = (float)std::numeric_limits<T>::max(),
                inv_scale = 1.f/alpha_scale;

    CV_Assert( src1.type() == src2.type() &&
               src1.type() == traits::Type<VT>::value &&
               src1.size() == src2.size());

    Size size = src1.size();

    dst.create(size, src1.type());

    MatConstIterator_<VT> it1 = src1.begin<VT>(), it1_end = src1.end<VT>();
    MatConstIterator_<VT> it2 = src2.begin<VT>();
    MatIterator_<VT> dst_it = dst.begin<VT>();
    
    for( ; it1 != it1_end; ++it1, ++it2, ++dst_it )
    {
        VT pix1 = *it1, pix2 = *it2;
        float alpha = pix1[3]*inv_scale, beta = pix2[3]*inv_scale;
        *dst_it = VT(saturate_cast<T>(pix1[0]*alpha + pix2[0]*beta),
                     saturate_cast<T>(pix1[1]*alpha + pix2[1]*beta),
                     saturate_cast<T>(pix1[2]*alpha + pix2[2]*beta),
                     saturate_cast<T>((1 - (1-alpha)*(1-beta))*alpha_scale));
    }
}

    