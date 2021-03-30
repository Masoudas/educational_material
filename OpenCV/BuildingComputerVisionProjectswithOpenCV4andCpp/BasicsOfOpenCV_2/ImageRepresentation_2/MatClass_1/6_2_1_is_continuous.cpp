/**
 * The OpenCV documentations states:
 *
 *      -    bool cv::Mat::isContinuous() const
 *  Reports whether the matrix is continuous or not. The method returns true if the matrix elements are stored 
 *  continuously without gaps at the end of each row. Otherwise, it returns false. Obviously, 1x1 or 1xN matrices 
 * are always continuous. Matrices created with Mat::create are always continuous. But if you extract a part of the 
 * matrix using Mat::col, Mat::diag, and so on, or constructed a matrix header for externally allocated data, such 
 * matrices may no longer have this property.
 *
 * The continuity flag is stored as a bit in the Mat::flags field and is computed automatically when you construct 
 * a matrix header. Thus, the continuity check is a very fast operation, though theoretically it could be done as 
 * follows (by checking the first step equals the total number of elements): 

// alternative implementation of Mat::isContinuous()
bool myCheckMatContinuity(const Mat& m)
{
    //return (m.flags & Mat::CONTINUOUS_FLAG) != 0;
    return m.rows == 1 || m.step == m.cols*m.elemSize();
}

 * First, note that this test is merely useful for 2D images. What the test does is to check whether the step size
 * of the first dimension equals then number of bytes from the first column. To do so, it uses elemSize, and cols.
 * Note that in m.step = m.cols * m.elemSize, there's actualy a defined cast from step to size_t, and this cast
 * value would be the step size for the first dimension. But why is this the test? Note that if the first step
 * were anything but this, it would have implied we couldn't jump to the next row (as we show below for a non-con
 * tinuous image.) In other word, when a new matrix is created, the step vector is inherited from the original
 * matrix.
 * 
 * Me: The most important take away is this:
 *      "Unless we use a custom allocator, or we have an excerpt from an original image, the image is continuous."
 */
#include <opencv2/core.hpp>
#include <iostream>

void check_continuity(){
    cv::Mat m{4, 4, CV_8UC1, cv::Scalar::all(0)};

    if (m.isContinuous()){
        std::cout << "A newly generated image is continuos\n";
    }

    cv::Mat m2{m, cv::Rect2d{1, 1, 2, 2}};

    if (!m2.isContinuous()){
        std::cout << "An excerpted image is generally not continuos\n";
        std::cout << "The step for this excerpted matrix is 4, which is not equivalent to cols*size " << m2.cols << '\n';
    }    
}

// int main(){
//     check_continuity();
// }
