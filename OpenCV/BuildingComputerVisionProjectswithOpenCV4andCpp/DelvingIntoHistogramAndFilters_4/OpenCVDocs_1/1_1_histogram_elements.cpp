/**
 * A histogram has the following elements according to OpenCV docs:
 * 
 *  -   dims: The number of parameters you want to collect data of. In a grayscale 2D image, dims = 1 
 *      because we are only counting the intensity values of each pixel (in a greyscale image).
 *  -   bins: It is the number of subdivisions in each dim.
 *  -   range: The limits for the values to be measured. In the case of an 8 bit grayscale image, 
 *      range = [0,255]
 * 
 * If we want to count two features, the resulting histogram would be a 3D plot (in which x and y would be 
 * binx and biny for each feature and z would be the number of counts for each combination of (binx,biny). 
 * The same would apply for more features (of course it gets trickier). 
 * 
 * Me: An example of the latter would be if we wanted to histogram a complex image. In this case, the dims
 * would be 2, rather 1. It will histogram pixels that are for example in the range [0-16]U[0-16]
 * We should thus make a distinction here. If we set dim=1, then a complex image can be histogrammed in one
 * dimension accross two channels. If dim=2, a two dimensional hist is formed. On the other hand, if we 
 * wanted to calculate the hist of each channel SEPARATELY, we NEED TO split the two channels.
 * 
 * Me: There's also the concept of uniform and non-uniform bins. Non-uniform bins have to be explicitly
 * provided for the calcHis function as we discuss later.
 * 
 */
