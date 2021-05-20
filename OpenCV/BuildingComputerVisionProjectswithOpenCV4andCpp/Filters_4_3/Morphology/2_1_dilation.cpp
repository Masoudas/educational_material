/**
 * As we already know, dilation is the opposite operation to erosion. Again, keep in mind that white spaces
 * should be what we want to dilate. Read erosion first.
 * 
 *  -   void cv::dilate(InputArray src,	OutputArray dst, InputArray kernel,	Point anchor = Point(-1,-1),
 *		int	iterations = 1,	int borderType = BORDER_CONSTANT, 
 *      const Scalar& borderValue = morphologyDefaultBorderValue()) 	
 * 
 *  Dilates an image by using a specific structuring element.
 *  The function dilates the source image using the specified structuring element that determines the shape of 
 *  a pixel neighborhood over which the maximum is taken:
 *                              dst(x,y)= max of pixel neighborhood
 *  The function supports the in-place mode. Dilation can be applied several ( iterations ) times. In case of 
 *  multi-channel images, each channel is processed independently.
 */


#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// Note that we usually define the kernel as a matrix of ones.
void dilate_image(){
    using namespace cv;

    auto contours = imread("Images/Contours.jpg", IMREAD_GRAYSCALE);
    contours = 255 - contours;  // Notting the image, so that black lines befome white.

    int iterations = 1;
    Mat kernel = Mat::ones(4, 4, CV_8U);
    Mat eroded_img{};    
    dilate(contours, eroded_img, kernel, {-1, -1}, iterations);

    imshow("Original", contours);
    imshow("Dilated-image", eroded_img);
    waitKey(0);
}

//int main(){
//    dilate_image();
//}