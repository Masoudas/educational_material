/**
 * The setTo method is used for setting matrix to a particular value. The OpenCV documenation is as follows:
 * 
 *      -   Mat& cv::Mat::setTo(InputArray value, InputArray mask = noArray()) 	
 *      Sets all or some of the array elements to the specified value.
 *      This is an advanced variant of the Mat::operator=(const Scalar& s) operator.
 *      Parameters
 *      -   value	Assigned scalar converted to the actual array type.
 *      -   mask	Operation mask of the same size as *this. Its non-zero elements indicate which matrix 
 *                  elements need to be copied. The mask has to be of type CV_8U and can have 1 or multiple 
 *                  channels.
 */