/**
 * These the auxiliary functions used inside the read and write methods.
 * 
 *      -   Mat cv::imdecode(InputArray buf, int flags)
 *      Reads an image from a buffer in memory. The function imdecode reads an image from the specified buffer in 
 *      the memory. If the buffer is too short or contains invalid data, the function returns an empty matrix 
 *      (Mat::data==NULL.) (Me: Which buffer is that? I've no idea.)
 *      See cv::imread for the list of supported formats and flags description. In the case of color images, the 
 *      decoded images will have the channels stored in B G R order. 
 * 
 *      -	bool cv::imencode(const String& ext, InputArray img, std::vector< uchar >& buf, 
 * 							  const std::vector<int>& params = std::vector<int>())
 * 		Encodes an image into a memory buffer. The function imencode compresses the image and stores it in the
 * 		memory buffer that is resized to fit the result. See cv::imwrite for the list of supported formats and 
 * 		flags description.
 * 		
 * 		Parameters    
 * 		-	ext		:		File extension that defines the output format.
 * 		-   img		:		Image to be written.
 * 		-   buf		:		Output buffer resized to fit the compressed image.
 * 		-   params	:		Format-specific parameters. See cv::imwrite and cv::ImwriteFlags. 
 * 
 */

 	