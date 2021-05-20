/**
 * Note that the input and output images must not be the same in the following filter.
 * 
 *  -   void cv::bilateralFilter(InputArray src, OutputArray dst, int d, double sigmaColor, double sigmaSpace,
 *		    int borderType = BORDER_DEFAULT) 	
 *      Applies the bilateral filter to an image.
 *      The function applies bilateral filtering to the input image, as described in 
 *      http://www.dai.ed.ac.uk/CVonline/LOCAL_COPIES/MANDUCHI1/Bilateral_Filtering.html bilateralFilter can 
 *      reduce unwanted noise very well while keeping edges fairly sharp. However, it is very slow compared to 
 *      most filters.
 *      
 *      Sigma values: For simplicity, you can set the 2 sigma values to be the same. If they are small (< 10),
 *      the filter will not have much effect, whereas if they are large (> 150), they will have a very strong 
 *      effect, making the image look "cartoonish".
 * 
 *      Filter size: Large filters (d > 5) are very slow, so it is recommended to use d=5 for real-time 
 *      applications, and perhaps d=9 for offline applications that need heavy noise filtering.
 * 
 *      -   Parameters
 *          -    src    :	Source 8-bit or floating-point, 1-channel or 3-channel image.
 *          -    dst    :	Destination image of the same size and type as src.   
 *          -    d	    :   Diameter of each pixel neighborhood that is used during filtering. If it is 
 *                          non-positive, it is computed from sigmaSpace.
 *          -    sigmaColor :	Filter sigma in the color space. A larger value of the parameter means that 
 *                              farther colors within the pixel neighborhood (see sigmaSpace) will be mixed 
 *                              together, resulting in larger areas of semi-equal color.
 *          -    sigmaSpace	:   Filter sigma in the coordinate space. A larger value of the parameter means 
 *                              that farther pixels will influence each other as long as their colors are 
 *                              close enough (see sigmaColor ). When d>0, it specifies the neighborhood size 
 *                              regardless of sigmaSpace. Otherwise, d is proportional to sigmaSpace.
 *          -    borderType	:   border mode used to extrapolate pixels outside of the image, see BorderTypes
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

cv::Mat typisch_bilateral_filter(cv::Mat img){
    using namespace cv;

    Mat filtered{};
    bilateralFilter(img, filtered, 9, 75, 75);   // These are typical in an offline application.

    return filtered;
}

int main(){
    using namespace cv;

    auto rose = imread("Images/Rose.jpg"); // By default, reads as color!
    auto filtered_rose = typisch_bilateral_filter(rose);
    
    imshow("bilateraled rose", filtered_rose);
    imshow("original", rose);
    waitKey(0);

    return EXIT_SUCCESS;
}