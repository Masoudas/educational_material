/**
 * 
 *  -   void cv::drawContours(InputOutputArray image, InputArrayOfArrays contours, int contourIdx,
 *  	const Scalar& color, int thickness = 1, int lineType = LINE_8, InputArray hierarchy = noArray(),
 *		int maxLevel = INT_MAX, Point offset = Point()) 	
 *      The function draws contour outlines in the image if thickness ≥ 0 or fills the area bounded by the 
 *      contours if thickness < 0. 
 * 
 * The example below shows how to retrieve connected components from the binary image and label them. The 
 * function that does the extracting is the findContours. A discussion of the hierarchies is left for later.
 * Suffice it to say, this function actually extracts contours and drawContours draws them, and even if
 * they're filled, they're drawn as filled!!
 * 
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

void extracting_contours_from_binary_image()
{
    // Reading a colored image as 8-bit grayscale.
    Mat src = cv::imread("Images/Contours.jpg", cv::IMREAD_GRAYSCALE);     
    Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC3);

    src = src > 1;  // Creating a binary image

    namedWindow( "Source", 1 );
    imshow( "Source", src );

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours( src, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE );

    // iterate through all the top-level contours,
    // draw each connected component with its own random color
    for(int idx = 4; idx >= 0; idx = hierarchy[idx][0] )
    {
        Scalar color( rand() & 255, rand() & 255, rand() & 255 );
        drawContours( dst, contours, idx, color, FILLED, 8, hierarchy );
    }

    namedWindow( "Components", 1 );
    imshow( "Components", dst );
    waitKey(0);
}

int main(){
    extracting_contours_from_binary_image();
}