/**
 * The Sobel filter is used for deriving the derivate of an image in x and y directions.
 * 
 *  -   void cv::Sobel(InputArray src, OutputArray dst, int ddepth, int dx, int dy, int ksize = 3, 
 *       double scale = 1, double delta = 0, int borderType = BORDER_DEFAULT) 	
 *      This function calculates dx-order or dy-order derivate (like firs order on x and first order on y,)
 *      The Sobel operators combine Gaussian smoothing and differentiation, so the result is more or less 
 *      resistant to the noise. Most often, the function is called with ( xorder = 1, yorder = 0, ksize = 3) 
 *      or ( xorder = 0, yorder = 1, ksize = 3) to calculate the first x- or y- image derivative. The kernels
 *      applied in both cases is very [ -1 0 1, -2 0 2, -1 0 1] for dx=1 and its transpose for dy=1.
 * 
 *      -   src	input image.
 *      -   dst	output image of the same size and the same number of channels as src.
 *      -   ddepth	output image depth, see combinations; in the case of 8-bit input images it will result in 
 *          truncated derivatives.
 *      -   dx	order of the derivative x.
 *      -   dy	order of the derivative y.
 *      -   ksize	size of the extended Sobel kernel; it must be 1, 3, 5, or 7.
 *      -   scale	optional scale factor for the computed derivative values; by default, no scaling is 
 *          applied (see getDerivKernels for details).
 *      -   delta	optional delta value that is added to the results prior to storing them in dst.
 *      -   borderType	pixel extrapolation method, see BorderTypes. BORDER_WRAP is not supported.
 * 
 * In the example below, we use the Sobel filter to create a simple edge detection filter. Don't forget that
 * the result of Sobel filter can be negative as well, which is why we need to apply an abs function to ensure
 * that the results are positive. Notice that we choose the output matrix format as 16bit signed.
 * Note that I depict the detected edges in color. I can easily convert them however to grayscale image.
 * 
 * 
 */

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

void simple_edge_detector_using_Sobel_filter(Mat img){
    GaussianBlur(img, img, Size{3, 3}, 1, 1);   

    Mat dx{};
    Sobel(img, dx, CV_16S, 1, 0, 3);    // This could easily have been a float matrix as well.

    Mat dy{};
    Sobel(img, dy, CV_16S, 0, 1, 3);


    Mat dx_8bit{};
    convertScaleAbs(dx, dx_8bit);

    Mat dy_8bit{};
    convertScaleAbs(dx, dy_8bit);
   
    imshow("Edge matrix in color", dx_8bit + dy_8bit);

    Mat edge_gray{};
    cvtColor(dx_8bit + dy_8bit, edge_gray, COLOR_BGR2GRAY);

    imshow("Edge matrix in gray", edge_gray);
    waitKey(0);
}

int main(){
    auto lena = imread(samples::findFile("lena.jpg"));

    simple_edge_detector_using_Sobel_filter(lena);
}