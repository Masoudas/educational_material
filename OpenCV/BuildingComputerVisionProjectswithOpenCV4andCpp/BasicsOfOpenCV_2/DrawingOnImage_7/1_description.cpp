/**
 * The following are taken from the OpenCV docs:
 * 
 * Drawing functions work with matrices/images of arbitrary depth. The boundaries of the shapes can be 
 * rendered with antialiasing (implemented only for 8-bit images for now). All the functions include the 
 * parameter color that uses an RGB value (that may be constructed with the Scalar constructor ) for color 
 * images and brightness for grayscale images. For color images, the channel ordering is normally Blue, Green, 
 * Red. This is what imshow, imread, and imwrite expect. So, if you form a color using the Scalar constructor, 
 * it should look like:
 *              Scalar(blue_component,green_component,red_component[,alpha_component])
 * 
 * If you are using your own image rendering and I/O functions, you can use any channel ordering. The drawing 
 * functions process each channel independently and do not depend on the channel order or even on the used color 
 * space. The whole image can be converted from BGR to RGB or to a different color space using cvtColor .
 * 
 * If a drawn figure is partially or completely outside the image, the drawing functions clip it. Also, many 
 * drawing functions can handle pixel coordinates specified with sub-pixel accuracy. This means that the 
 * coordinates can be passed as fixed-point numbers encoded as integers. The number of fractional bits is 
 * specified by the shift parameter and the real point coordinates are calculated as 
 * Point(x,y)→Point2f(x∗(2^−shift),y∗(2^−shift)). This feature is especially effective when rendering antialiased 
 * shapes.
 *
 * Note: The functions do not support alpha-transparency when the target image is 4-channel. In this case, 
 * the color[3] is simply copied to the repainted pixels. Thus, if you want to paint semi-transparent shapes, 
 * you can paint them in a separate buffer and then blend it with the main image. 
 * 
 * Me: All the methods we shall describle are inside the imgproc folder.
 */