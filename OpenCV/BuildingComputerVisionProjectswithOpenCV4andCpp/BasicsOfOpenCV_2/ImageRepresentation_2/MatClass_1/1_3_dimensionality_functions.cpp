/**
 * Here, we shall take a look at the functions in Mat are responsible for determining various dimensionality
 * properties of the Mat class:
 * 
 *  -   int cv::Mat::channels() 	const
 *      Returns the number of channels associated with the image.
 * 
 *  -   int cv::Mat::dims   (member)
 *      The matrix dimensionality, >= 2 
 * 
 *  -   int cv::Mat::rows; int cv::Mat::rows (member)
 *      The number of rows and columns (number of pixels, not number of underlying matrix elements.) It returns
 *      (-1,-1) when the matrix has MORE than two dimensions.
 * 
 *  -   cv::MatSize cv::Mat::size
 *      The size of image dimensions as a structure. 
 *      Note from me: This is the same as the sz array we supply in the constructor!
 * 
 *  -   
 * 
 */