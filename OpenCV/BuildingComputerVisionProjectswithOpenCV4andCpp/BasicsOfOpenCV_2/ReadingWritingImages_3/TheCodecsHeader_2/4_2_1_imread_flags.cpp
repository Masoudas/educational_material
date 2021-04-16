/**
 * Here, we shall discuss the int flags accepted by the imread function. These flags are part of the ImreadModes
 * enum in the imgcodes header.
 * 
 * Pay special attention to COLOR and how it 'converts' to 8 bit 3 channel BGR image. 
 * 
 *      -   IMREAD_UNCHANGED 
 *      If set, return the loaded image as is (with alpha channel, otherwise it gets cropped). Ignore EXIF 
 *      orientation (me: In a particular image format we discussed in the previous section).
 *      (me: I checked, and if we read a BGRA image with IMREAD_COLOR, the alpha channel is dropped. Note that
 *      unchanged does not change the depth to 8 bits) (me: Note that ANYDEPTH converts to grayscale!) 
 * 
 *      -   IMREAD_GRAYSCALE 
 *      If set, always convert image to the single channel grayscale image (codec internal conversion).
 *      (me, and also converts to 8bit unsigned) 
 * 
 *      -   IMREAD_COLOR 
 *      If set, always convert image to the 3 channel BGR color image. 
 * 
 *      -   IMREAD_ANYDEPTH
 *      If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 
 *      8-bit (me: It does seem to convert to grayscale however).
 * 
 *      -   IMREAD_ANYCOLOR 
 *      If set, the image is read in any possible color format. 
 * 
 *      -   IMREAD_REDUCED_GRAYSCALE_n where n = 2, 4, 8
 *      If set, always convert image to the single channel grayscale image and the image size reduced 1/n.
 * 
 *      -   IMREAD_REDUCED_COLOR_n where n = 2, 4, 8
 *      If set, always convert image to the 3 channel BGR color image and the image size reduced 1/2. 
 * 
 *      -   IMREAD_IGNORE_ORIENTATION  
 *      If set, do not rotate the image according to EXIF's orientation flag. 
 */
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

// See for your self that unchanged changes depth to 8 bits, but keeps the alpha channel.
void unchanged_changes_depth(){
    auto mat = cv::imread("Images/Rose-alpha-16bit.png", cv::IMREAD_UNCHANGED);

    // Just always do this check!
    if (mat.empty())
        std::cout << "Couldn't read the image\n"; 

    if (mat.depth() == CV_16U && mat.channels() == 4)
        std::cout << "Unchanged mode has changed the depth to 8 bits, but keeps alpha channel\n";
}

void anydepth_keeps_depth_but_converts_to_gray(){
    auto mat = cv::imread("Images/Rose-alpha-16bit.png", cv::IMREAD_ANYDEPTH);

    if (mat.empty())
        std::cout << "Couldn't read the image\n";

    if (mat.depth() == CV_16U && mat.channels() == 1)
        std::cout << "Any depth keeps depth, but converts to gray\n";
}

void anycolor_changes_depth_and_drops_alpha(){
    auto mat = cv::imread("Images/Rose-alpha-16bit.png", cv::IMREAD_ANYCOLOR);

    if (mat.empty())
        std::cout << "Couldn't read the image\n";
    
    if (mat.depth() == CV_8U && mat.channels() == 3)
        std::cout << "Any color changes depth and number of channels\n";    
}

//int main(){
//    unchanged_changes_depth();
//    anydepth_keeps_depth_but_converts_to_gray();
//    anycolor_changes_depth_and_drops_alpha();
//}