/**
 * Functions and classes described in this section are used to perform various linear or non-linear filtering 
 * operations on 2D images (represented as Mat's). It means that for each pixel location (x,y) in the source 
 * image (normally, rectangular), its neighborhood is considered and used to compute the response. In case of 
 * a linear filter, it is a weighted sum of pixel values. In case of morphological operations, it is the 
 * minimum or maximum values, and so on. The computed response is stored in the destination image at the same 
 * location (x,y). It means that the output image will be of the same size as the input image. Normally, the 
 * functions support multi-channel arrays, in which case every channel is processed independently. Therefore, 
 * the output image will also have the same number of channels as the input one.
 * 
 * Another common feature of the functions and classes described in this section is that, unlike simple 
 * arithmetic functions, they need to extrapolate values of some non-existing pixels. For example, if you want 
 * to smooth an image using a Gaussian 3×3 filter, then, when processing the left-most pixels in each row, you 
 * need pixels to the left of them, that is, outside of the image. You can let these pixels be the same as the 
 * left-most image pixels ("replicated border" extrapolation method), or assume that all the non-existing pixels 
 * are zeros ("constant border" extrapolation method), and so on. OpenCV enables you to specify the extrapolation 
 * method.
 * 
 * Depth combinations
 *  Input depth (src.depth()) 	Output depth (ddepth)
 *           CV_8U 	           -1/CV_16S/CV_32F/CV_64F
 *       CV_16U/CV_16S 	          -1/CV_32F/CV_64F
 *          CV_32F 	              -1/CV_32F/CV_64F
 *          CV_64F 	                  -1/CV_64F
 */