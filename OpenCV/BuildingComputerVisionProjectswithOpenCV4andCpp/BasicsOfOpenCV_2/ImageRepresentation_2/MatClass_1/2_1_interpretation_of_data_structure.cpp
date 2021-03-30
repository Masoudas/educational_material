/**
 * "Let's forget about tiffs for a moment and only consider 2D images of the old times!"
 * 
 * Essentially, the elements we need to create a data matrix are:
 *  -   Color space: Whether the image is grayscale or colored (RGB, BRG, etc.)
 *  -   Size of each color: The resolution of each color.
 * 
 * Hence for example, a grayscale image can have an unsigned char, in which case it has values from 0 to 255, or it
 * can be a float, in which it has normally 4 bytes at its disposal, and saves a continuous range of values. As 
 * another example, if the image is RGB and resolution, it has 3 * 8 = 24 bits for each pixel, and each color ranges
 * from 0 to 255. If it's float, then it has 3 * 4 bytes as at its disposal, each containing a continuous value. 
 * 
 * The famous color spaces are:
 *      - RGB is the most common as our eyes use something similar, however keep in mind that OpenCV standard display 
 *        system composes colors using the BGR color space (red and blue channels are swapped places).
 *      - The HSV and HLS decompose colors into their hue, saturation and value/luminance components, which is a 
 *        more natural way for us to describe colors. You might, for example, dismiss the last component, making 
 *        our algorithm less sensible to the light conditions of the input image.
 *      - YCrCb is used by the popular JPEG image format.
 *      - CIE L*a*b* is a perceptually uniform color space, which comes in handy if you need to measure the distance 
 *        of a given color to another color.
 * 
 * Note: It's my understanding that channel in cv::Mat refers to color space. For example, the macro cv::CV_8UC3 
 * implies an 8 bit unsigned image of three channels.
 * 
 * Note: As we shall show later, the number of channels only indicate how many channels we need. This is independent
 * of the way we translate the channels. These are merely numerical values, and it's up to us to indicate to the
 * algorithms or visualization methods how we want to express them. Consequently, when creating matrices, we only
 * indicate the number of channels, not the colorspace, which is irrelevant information.
 * 
 */