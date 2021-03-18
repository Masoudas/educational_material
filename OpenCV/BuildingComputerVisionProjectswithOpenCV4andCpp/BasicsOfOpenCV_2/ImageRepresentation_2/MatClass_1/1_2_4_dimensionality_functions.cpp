/**
 * Here, we shall take a look at the functions in Mat are responsible for determining various dimensionality
 * properties of the Mat class. Note that except for dims, none of the other functions work properly for higher
 * dimension matrices!
 * 
 *  -   int cv::Mat::channels() 	const
 *      Returns the number of channels associated with the image.
 * 
 *  -   int cv::Mat::dims   (member)
 *      The matrix dimensionality, >= 2 
 * 
 *  -   int cv::Mat::rows; int cv::Mat::rows (member)
 *      The number of rows and columns (number of pixels, not number of underlying matrix elements.) It returns
 *      (-1,-1) when the matrix has MORE than two dimensions. (me: For more than 2 dims, all associations are 
 *      left to the user.)
 * 
 *  -   cv::MatSize cv::Mat::size
 *      The size of image dimensions as a structure. 
 *      Note from me: This method does not work properly for higher dimension matrices.
 * 
 *  
 * 
 */