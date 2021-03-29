/**
 * In what follows, we have an example of alpha blending from the OpenCV documentation that takes into account
 * the fact if the images to be alpha blended are continuous or not (assuming a 2D image.) The idea is that we
 * want to write one loop to take care of this.
 *
 * Note that if the image is continuous, we just need to go over row * col elements in one loop, and we can get
 * a pointer to the first element just once for that.
 * If the image is not continuous, we need to call the ptr method once for each row, and then iterate over the
 * column, and then repeat.
 *
 * We can now clearly see that the way to do this is to define the number of rows and columns ourselves depending
 * on whether or not the image isContinuous. Let's call it width (col) and height (row) so as not to confuse them
 * with the actual row and column. We can see that:
 *
 * If isContinuous == true:
 *  height = 1; width = rows * cols;
 * else:
 *  height = rows; width = cols
 *
 * Now, considering the above, essentially our loop would look something like this:
 for (height)
    for (width)
        ptr* = image_ptr(height, width);
        f(ptr);

 * Under this new light, we can now easily understand the code below. Note two things:
 *  - T: and accessing each element
 *  - width multiplication by four:
 */

#include <opencv2/core.hpp>
using namespace cv;

template<typename T>
void alphaBlendRGBA(const Mat& src1, const Mat& src2, Mat& dst)
{
    const float alpha_scale = (float)std::numeric_limits<T>::max(),
                inv_scale = 1.f/alpha_scale;
    CV_Assert( src1.type() == src2.type() &&
               src1.type() == CV_MAKETYPE(traits::Depth<T>::value, 4) &&
               src1.size() == src2.size());
    Size size = src1.size();
    dst.create(size, src1.type());

    // here is the idiom: check the arrays for continuity and,
    // if this is the case,
    // treat the arrays as 1D vectors
    if( src1.isContinuous() && src2.isContinuous() && dst.isContinuous() )
    {
        size.width *= size.height;
        size.height = 1;
    }
    size.width *= 4;

    for( int i = 0; i < size.height; i++ )
    {
        // when the arrays are continuous,
        // the outer loop is executed only once
        const T* ptr1 = src1.ptr<T>(i);
        const T* ptr2 = src2.ptr<T>(i);
        T* dptr = dst.ptr<T>(i);
        for( int j = 0; j < size.width; j += 4 )
        {
            float alpha = ptr1[j+3]*inv_scale, beta = ptr2[j+3]*inv_scale;
            dptr[j] = saturate_cast<T>(ptr1[j]*alpha + ptr2[j]*beta);
            dptr[j+1] = saturate_cast<T>(ptr1[j+1]*alpha + ptr2[j+1]*beta);
            dptr[j+2] = saturate_cast<T>(ptr1[j+2]*alpha + ptr2[j+2]*beta);
            dptr[j+3] = saturate_cast<T>((1 - (1-alpha)*(1-beta))*alpha_scale);
        }
    }
}