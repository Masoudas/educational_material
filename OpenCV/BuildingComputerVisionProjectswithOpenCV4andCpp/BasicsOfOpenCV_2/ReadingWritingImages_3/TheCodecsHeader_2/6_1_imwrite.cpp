/**
 * Me: The first notice as always is that this function does not throw an exception, but rather returns a bool.
 * 
 *   -   bool cv::imwrite(const String & filename, InputArray img, 
 *                       const std::vector< int >& params = std::vector< int >()) 	
 * 
 *       Saves an image to a specified file.
 *       The function imwrite saves the image to the specified file. The image format is chosen based on the 
 *       filename extension (me: extensions are those mentioned in imread). In general, only 8-bit single-channel 
 *       or 3-channel (with 'BGR' channel order) images can be saved using this function, with these exceptions:
 * 
 *       -  16-bit unsigned (CV_16U) images can be saved in the case of PNG, JPEG 2000, and TIFF formats
 *       -  32-bit float (CV_32F) images can be saved in PFM, TIFF, OpenEXR, and Radiance HDR formats; 3-channel 
 *          (CV_32FC3) TIFF images will be saved using the LogLuv high dynamic range encoding (4 bytes per pixel)
 *       -  PNG images with an alpha channel can be saved using this function. To do this, create 8-bit (or 
 *          16-bit) 4-channel image BGRA, where the alpha channel goes last. Fully transparent pixels should have
 *          alpha set to 0, fully opaque pixels should have alpha set to 255/65535.
 *       -  Multiple images (vector of Mat) can be saved in TIFF format
 */