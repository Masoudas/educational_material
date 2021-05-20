/**
 * Not that we normally tend to do this, but there's a function called filter2D intended to filter an image
 * with a filter of any size.
 * 
 * With the filter2D function, we CAN'T filter a color image all together, and we need to split merge it! The
 * assertion error "cn == 1 in function 'countNonZero" indicates this error for us.
 * 
 * Of importance is the concept of anchor, which determines which entry of the kernel is set on the point for
 * calculating the result. Normally, we want the central point to be there.
 * 
 *  -   void cv::filter2D(InputArray src, OutputArray dst, int ddepth, InputArray kernel, 
 *          Point anchor = Point(-1,-1), double delta = 0, int borderType = BORDER_DEFAULT)
 *  	The function applies an arbitrary linear filter to an image. In-place operation is supported. When 
 *      the aperture is partially outside the image, the function interpolates outlier pixel values according 
 *      to the specified border mode.
 * 
 *      The function uses the DFT-based algorithm in case of sufficiently large kernels (~11 x 11 or larger) 
 *      and the direct algorithm for small kernels.
 * 
 *      -   Parameters
 *          -    src	input image.
 *          -    dst	output image of the same size and the same number of channels as src.
 *          -    ddepth	desired depth of the destination image, see combinations
 *          -    kernel	convolution kernel (or rather a correlation kernel), a single-channel floating point 
 *               matrix; if you want to apply different kernels to different channels, split the image into 
 *               separate color planes using split and process them individually. (me: -1 usually means keep.)
 *          -    anchor	anchor of the kernel that indicates the relative position of a filtered point within 
 *               the kernel; the anchor should lie within the kernel; default value (-1,-1) means that the 
 *               anchor is at the kernel center.
 *          -    delta	optional value added to the filtered pixels before storing them in dst.
 *          -    borderType	pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.      
 * 
 * In the following example, we apply an averaging filter of 25 elements. Notice that for the filter to 
 * function properly, the filter type is chosen as 32 bit float, so that 1/25 makes sense. The resulting image
 * is however 8U. Again, notice the split and merge process we need.
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

cv::Mat averaging_with_custom_filter(cv::Mat img){
    using namespace cv;
    Mat bgr[3] = { {}, {}, {}};
    split(img, bgr);

    Mat filter = Mat::ones(Size2i{5, 5}, CV_32F) / 25;

    filter2D(bgr[0], bgr[0], -1, filter);
    filter2D(bgr[1], bgr[1], -1, filter);
    filter2D(bgr[2], bgr[2], -1, filter);

    merge(bgr, sizeof(bgr) / sizeof(bgr[0]), img);
    return img;
}

//int main(){
//    using namespace cv;
//    auto rose = imread("Images/Rose.jpg", IMREAD_COLOR);
//    
//    if (rose.empty()){
//        return EXIT_FAILURE;
//    }
//
//    auto rose_filtered = averaging_with_custom_filter(rose);
//
//    imshow("Averaged rose", rose_filtered);
//    waitKey(0);
//}