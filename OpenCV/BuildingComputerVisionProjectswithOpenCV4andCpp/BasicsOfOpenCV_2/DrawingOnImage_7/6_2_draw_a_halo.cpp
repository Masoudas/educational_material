/**
 * Imagine we want to draw a halo on a particular region of an image. That is, we want to accentuate a certain
 * region of an image, and then at the same time, make the region outside that point less transparent.
 * 
 * If we're talking about a gray image, we know that we can simply create an image that has values close to
 * 1 in the region we want, and close to 0 in the region we don't want, and then multiply the original image
 * with that. The point is that the image has to be float, so that the scaling is correct.
 * 
 * We can do the same thing with color images as well, making a GBR image with the same values.
 * 
 * The point to recall is that multiplication should be done in float and not in integer. Hence, we should apply
 * this technique by first converting the images to float, as we've done in the following example.
 */

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
void create_a_circle_halo(Mat img){
   // Create image for halo dark 
    Mat halo(img.rows, img.cols, CV_32FC3, Scalar(0.3, 0.3, 0.3)); 
    
    // Create circle  
    circle(halo, Point(img.cols/2, img.rows/2), img.cols/3, Scalar(1,1,1), -1);  
    blur(halo, halo, Size(img.cols/3, img.cols/3)); // Just a big blur to mix everything
    
    img.convertTo(img, CV_32FC3);
    img = img.mul(halo);    // Element-wise multiplication
  
    img.convertTo(img, CV_8UC3);

    imshow("haloed lena", img);
    waitKey(0);
}

//int main(){
//    auto lena = samples::findFile("lena.jpg");
//    auto img = imread(lena);

//    create_a_circle_halo(img);

//}