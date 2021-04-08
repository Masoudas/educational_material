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
 *      unchanged still changes the depth to 8 bits, but reads the image as BGRA.)
 * 
 *      -   IMREAD_GRAYSCALE 
 *      If set, always convert image to the single channel grayscale image (codec internal conversion). 
 * 
 *      -   IMREAD_COLOR 
 *      If set, always convert image to the 3 channel BGR color image. 
 * 
 *      -   IMREAD_ANYDEPTH
 *      If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 
 *      8-bit.
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
#include <iostream>

void unchanged_changes_depth(){
    auto mat = cv::imread("Images/Rpse-alpha-16bit.png", cv::IMREAD_UNCHANGED);

    if (mat.depth() == CV_8U)
    std::cout << "Unchanged mode has changed the depth to 8 bits\n";
}

int main(){
    unchanged_changes_depth();
}