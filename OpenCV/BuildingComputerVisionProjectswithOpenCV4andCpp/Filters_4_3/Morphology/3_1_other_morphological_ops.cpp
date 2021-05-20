/**
 * The function MorphologyEx is a function to which we can provide several functions, which then performs 
 * several morphological operations such as Openning, Closing, Morphological gradient, Top hat, Bottom hat.
 * 
 * Note that we can do erosion and dilation with this method as well.
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// Note that we usually define the kernel as a matrix of ones.
// Notice how noisy parts of the image, including the thin lines, are gone after.
void morphological_openning_an_image(){
    using namespace cv;

    auto contours = imread("Images/Contours.jpg", IMREAD_GRAYSCALE);
    contours = 255 - contours;  // Notting the image, so that black lines befome white.

    int iterations = 1;
    Mat kernel = Mat::ones(4, 4, CV_8U);
    Mat openned_img{};    
    morphologyEx(contours, openned_img, MorphTypes::MORPH_OPEN, kernel);

    imshow("Original", contours);
    imshow("Openned-image", openned_img);
    waitKey(0);
}

// Closing can fill the pots inside an image. Although pots should not be that big.
// We see a little bit of it in the part where the thin line intersects itself.
void morphological_closing_an_image(){
    using namespace cv;

    auto contours = imread("Images/Contours.jpg", IMREAD_GRAYSCALE);
    contours = 255 - contours;  // Notting the image, so that black lines befome white.

    int iterations = 1;
    Mat kernel = Mat::ones(4, 4, CV_8U);
    Mat closed_img{};    
    morphologyEx(contours, closed_img, MorphTypes::MORPH_CLOSE, kernel);

    imshow("Original", contours);
    imshow("Closed-image", closed_img);
    waitKey(0);
}

// A nice of detecting edges, using morphological filters
void morphological_gradient(){
    using namespace cv;

    auto contours = imread("Images/Contours.jpg", IMREAD_GRAYSCALE);
    contours = 255 - contours;  // Notting the image, so that black lines befome white.

    int iterations = 1;
    Mat kernel = Mat::ones(4, 4, CV_8U);
    Mat openned_img{};    
    morphologyEx(contours, openned_img, MorphTypes::MORPH_GRADIENT, kernel);

    imshow("Original", contours);
    imshow("Openned-image", openned_img);
    waitKey(0);
}

int main(){
    morphological_closing_an_image();
}