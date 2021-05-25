/**
 * Note: Erosion can be done in place.
 * Important note: Parts to be eroded MUST BE in white, and not in black.
 * 
 * As we can see blow, the idea behind erosion filter is simple as well. That is, get in a neighbor, chose the
 * minimum or maximum.
 * 
 *  -   void cv::erode(InputArray src, OutputArray dst, InputArray kernel, Point anchor = Point(-1,-1),
 *  		int iterations = 1, int	borderType = BORDER_CONSTANT, 
 *          const Scalar & borderValue = morphologyDefaultBorderValue())
 * 
 * Erodes an image by using a specific structuring element.
 * The function erodes the source image using the specified structuring element that determines the shape of 
 * a pixel neighborhood over which the minimum is taken:
 *                      dst(x,y) = min of values in the surrounding pixel boundary
 * 
 * The function supports the in-place mode. Erosion can be applied several (iterations) times. In case of 
 * multi-channel images, each channel is processed independently. 	
 * 
 *  -   src	    input image; the number of channels can be arbitrary, but the depth should be one of CV_8U, 
 *              CV_16U, CV_16S, CV_32F or CV_64F.
 *  -   dst	    output image of the same size and type as src.
 *  -   kernel	structuring element used for erosion; if element=Mat(), a 3 x 3 rectangular structuring element 
 *              is used. Kernel can be created using getStructuringElement.
 *  -   anchor	position of the anchor within the element; default value (-1, -1) means that the anchor is at 
 *              the element center.
 *  -   iterations	number of times erosion is applied.
 *  -   borderType	pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.
 *  -   borderValue	border value in case of a constant border 
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// Note that we usually define the kernel as a matrix of ones.
void erode_image(){
    using namespace cv;

    auto contours = imread("Images/Contours.jpg", IMREAD_GRAYSCALE);
    contours = 255 - contours;  // Notting the image, so that black lines befome white.

    int iterations = 1;
    Mat kernel = Mat::ones(4, 4, CV_8U);
    Mat eroded_img{};    
    erode(contours, eroded_img, kernel, {-1, -1}, iterations);

    imshow("Original", contours);
    imshow("Eroded", eroded_img);
    waitKey(0);
}

//int main(){
//    erode_image();
//}