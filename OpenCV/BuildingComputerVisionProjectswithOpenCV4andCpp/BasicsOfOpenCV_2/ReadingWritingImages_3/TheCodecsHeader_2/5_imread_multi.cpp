/**
 *  -   bool cv::imreadmulti(const String& filename, std::vector<Mat>& mats, int flags = IMREAD_ANYCOLOR) 	
 *  (me: Note the striking difference between the multi method and the imread method, in that this method 
 *   returns a bool and we have to supply it with a vector of image.)
 *  Loads a multi-page image from a file. The function imreadmulti loads a multi-page image from the specified 
 *  file into a vector of Mat objects. 
 *  
 *  Parameters:         
 *      -   filename:	Name of file to be loaded.    
 *      -   flags:	Flag that can take values of cv::ImreadModes, default with cv::IMREAD_ANYCOLOR.
 *      -   mats:	A vector of Mat objects holding each page, if more than one. 
 * 
 * How the images are read is unclear to me at this point, especially with respect to axis orders.
 */