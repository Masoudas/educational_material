/**
 * The first thing to notice about imread is that all the functions associated with imread are in imgcodecs header,
 * but they can be accessed with the highgui header as well.
 * 
 * Second, note how we check for the presence of data in the image, that is, we check that the data pointer is
 * not empty. In other words, the imread function does not throw an exception in case of failure to open the
 * image. Hence, checking the data pointer is a very cheeky way of checking whether the image is loaded properly.
 * Some say we can accomplish the same task using empty method as well!
 * 
 * Third point is on the modes, which we shall investigate in depth later too:
 *      -   cv::IMREAD_UNCHANGED: If set, this returns a 16-bit/32-bit image when the input has the 
 *          corresponding depth, otherwise it converts it to 8-bit
 *      -   cv::IMREAD_COLOR: If set, this always converts an image to a color one (BGR, 8-bit unsigned)
 *      -   cv::IMREAD_GRAYSCALE: If set, this always converts an image to a grayscale one (8-bit unsigned)
 * 
 * So imread fascilities provide the opportunity to change image color scheme to what we desire.
 */

#include <string>
#include <opencv2/imgcodecs.hpp>


void reading_image_sample(std::string path){
    auto im_as_is = cv::imread(path, cv::ImreadModes::IMREAD_UNCHANGED);   // Don't change the depth of the image

    if (!im_as_is.data && im_as_is.empty()){    // Redundant test on my part!
        throw "Couldn't read the image";
    }
}
