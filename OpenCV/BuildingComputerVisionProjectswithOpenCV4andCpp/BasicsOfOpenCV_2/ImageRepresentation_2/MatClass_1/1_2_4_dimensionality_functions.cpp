/**
 * Here, we shall take a look at the functions in Mat that are responsible for determining various dimensionality
 * properties of the Mat class. Note that except for dims, none of the other functions work properly for higher
 * dimension matrices!
 * 
 *  -   int cv::Mat::channels() 	const
 *      Returns the number of channels associated with the image (only for 2D images)
 * 
 *  -   int cv::Mat::dims   (member)
 *      The matrix dimensionality, >= 2 (unless trivial empty image)
 * 
 *  -   int cv::Mat::rows; int cv::Mat::rows (member)
 *      The number of rows and columns (number of pixels, not number of underlying matrix elements.) It returns
 *      (-1,-1) when the matrix has MORE than two dimensions. (me: For more than 2 dims, all associations are 
 *      left to the user.)
 * 
 *  -   cv::MatSize cv::Mat::size
 *      The size of image dimensions as a structure. Note that this a field of the cv::Mat class.
 * 
 *  
 * 
 */