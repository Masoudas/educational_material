/**
 * I don't understand the use of this function, but whatever documented below is correct.
 * 
 * Sometimes, when one dimension in a 2D or 3D matrix has only one element, some algorithms run into problems. The
 * checkVector.
 * 
 * int cv::Mat::checkVector(
 *      int	elemChannels,
 *      int	depth = -1,
 *		bool requireContinuous = true) const
 * 
 *  -   elemChannels	
 *    Number of channels or number of columns the matrix should have. For a 2-D matrix, when the matrix has only
 *    1 column, then it should have elemChannels channels; When the matrix has only 1 channel, then it should have 
 *    elemChannels columns. For a 3-D matrix, it should have only one channel. Furthermore, if the number of planes 
 *    is not one, then the number of rows within every plane has to be 1; if the number of rows within every plane 
 *    is not 1, then the number of planes has to be 1.
 * 
 *  -   depth	
 *    The depth the matrix should have. Set it to -1 when any depth is fine.
 * 
 *  -   requireContinuous	
 *    Set it to true to require the matrix to be continuous.
 * 
 *  - retruns
 *    -1 if the requirement is not satisfied. Otherwise, it returns the number of elements in the matrix. Note that 
 *    an element may have multiple channels.
 * 
 * Note: The implementation of this method on the opencv github is as follows (note that data is the data pointer):
 * return data && (depth() == _depth || _depth <= 0) && (isContinuous() || !_requireContinuous) &&
 *      (
 *        (dims == 2 && (   // If dimension is two
 *                        ((rows == 1 || cols == 1) && channels() == _elemChannels) || // Either row or col is one, 
 *                                                                                 // and we have _elemChannel channels  
 *                        (cols == _elemChannels && channels() == 1) // Or we have _elemChannels columns and one channel.
 *                       )
 *         ) || // Or if the matrix is 3D:
 *          (dims == 3 && channels() == 1 && size.p[2] == _elemChannels && (size.p[0] == 1 || size.p[1] == 1) &&
 *           (isContinuous() || step.p[1] == step.p[2]*size.p[2])) // Number of channels is 1, third step equals
 *                                                                 // _elemchannels and either first or second
 *                                                                 // step is one, and either the matrix is continuous
 *                                                                 // or we have that the second step is the third step
 *                                                                 // times size of third dim.  
 *      )
 *  ? (int)(total()*channels()/_elemChannels) : -1; // If either of the previous conditions is satisifed, return 
 *                                                  // total number of elements times n_channels divided by 
 *                                                  // _numChannels, otherwise -1, where total is row*column for
 *                                                  // 2D images, or multiplication of all dimensions. In other 
 *                                                  // words, number of pixels for 2D images or number of elements
 *                                                  // over all dimensions.
 * 
 *      
 */
#include <opencv2/core.hpp>
#include <iostream>

void two_dim_image_example(){
    cv::Mat m(20, 1, CV_32FC1);   // Twenty rows, one column, two channels.
    CV_Assert(m.checkVector(2) == 20); // (20 * 1) * 2 / 2 = 20 

    m.create(20, 20, CV_32FC1);   // Twenty rows, twenty column, one channels.
    CV_Assert(m.checkVector(20) == 20);  // 20 * 20 * 1 * 1 / 20 = 20
}

void three_dim_image_example(){
    int dims[] = {1, 3, 5}; // 1 plane, every plane has 3 rows and 5 columns
    cv::Mat mat(3, dims, CV_32FC1); // for 3-d mat, it MUST have only 1 channel
    auto n = mat.checkVector(5); // the 5 columns are considered as 1 element
    std::cout << mat.step[2] << '\n';
    CV_Assert(n == 3);
    
    int dims2[] = {3, 1, 5}; // 3 planes, every plane has 1 row and 5 columns. 
    mat.create(3, dims2, CV_32FC1);
    n = mat.checkVector(5); // the 5 columns are considered as 1 element
    CV_Assert(n == 3); // (5 * 3) / 5 = 3
}

 int main(){
     three_dim_image_example();
 }