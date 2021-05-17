/**
 * Canny Edge Detection is a popular edge detection algorithm. It was developed by John F. Canny.
 * It is a multi-stage algorithm:
 *      -    Noise Reduction
 *      Since edge detection is susceptible to noise in the image, first step is to remove the noise in the 
 *      image with a 5x5 Gaussian filter.
 * 
 *      -    Finding Intensity Gradient of the Image
 *      Smoothened image is then filtered with a Sobel kernel in both horizontal and vertical direction to get 
 *      first derivative in horizontal direction (Gx) and vertical direction (Gy). From these two images, we 
 *      can find edge gradient and direction for each pixel as follows:
 *                                        Edge_Gradient(G)=sqrt(Gx^2+Gy^2)
 *                                           Angle(θ)=tan^(-1)(Gy/Gx)
 *      
 *      -   Non-maximum Suppression
 *      After getting gradient magnitude and direction, a full scan of image is done to remove any unwanted 
 *      pixels which may not constitute the edge. For this, at every pixel, pixel is checked if it is a local 
 *      maximum in its neighborhood in the direction of gradient. Points that are not local extermums are 
 *      suppressed as such. In short, the result you get is a binary image with "thin edges".
 * 
 *      -   Hysteresis Thresholding
 *      This stage decides which points are really edges and which are not. For this, we need two threshold 
 *      values, minVal and maxVal. Any edges with intensity gradient more than maxVal are sure to be edges and 
 *      those below minVal are sure to be non-edges, so discarded. Those who lie between these two thresholds 
 *      are classified edges or non-edges based on their connectivity. If they are connected to "sure-edge" 
 *      pixels, they are considered to be part of edges. Otherwise, they are also discarded.
 * 
 * Below is an example of how we detect edges. Note that the thresholds are not actually dependent on the
 * intensity of the pixels as the above example demonstrates, hence, it's a heuristic algorithm in that sense.
 */
