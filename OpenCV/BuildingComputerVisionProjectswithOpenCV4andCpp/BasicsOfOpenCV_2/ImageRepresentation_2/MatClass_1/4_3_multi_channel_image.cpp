 /**
 * While documenting the at method, the openCV website never mentions how we can access the pixels of a multi
 * channel image. Question is, how can we access the pixels of a multi-channel image?
 * 
 * The answer is that for such images, we need to use Point3_ structure. Essentially, as the following example 
 * shows, we need to define a type with the correct templated Point_ (for two channels) or Point3_ (for three
 * channels.) Once that's done, we just have to iterate through the image.
 * 
 * Note: We maybe tempted to use Point3i (integer 3D point) for all images. Note however that this is WRONG, because
 * of the way the pixel object is created (through pointer conversion.) Hence, if we were to read a uchar image
 * with an int point, we in fact read four bytes from the image for each channel, which is wrong. Hence, the Point_
 * template needs to be templated with the right template parameter.
 * 
 * As a reminder, note that we can't directly print the uchar 3D point, because as we may recall, a char is printed
 * as ASCII when used with cout, and not its literal number.
 * 
 * Note that for four channel images, we can't use Point, and we need to use vector, because each point has exactly
 * four dimensions that need attending.
 */

#include <opencv2/core.hpp>
#include <iostream>

void reading_RGB_image(){
    using Pixel = cv::Point3_<uchar>;
    cv::Mat m{2, 2, CV_8UC3, cv::Scalar(128, 0, 255)};  // Set (R,G,B)=(128,0,255)
    
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++ ){
           auto& pixel = m.at<Pixel>(i,j);  // Using the same reference.

           std::cout << "Channel values at pixel (" << i << "," << j <<") is ";
           std::cout << "[" << (int)pixel.x << ", " << (int)pixel.y << ", " << (int)pixel.z << "]\n";
        }
    }
}

void reading_complex_image(){
    using Pixel = cv::Point2f;
    cv::Mat m{2, 2, CV_32FC2, cv::Scalar{1, 7}}; // A complex image with 1+7j

    for (int i = 0; i < m.rows; i++){
        for (int j = 0; j < m.cols; j++){
           auto& pixel = m.at<Pixel>(i,j);  // Using the same reference.

           std::cout << "Channel values at pixel (" << i << "," << j <<") is ";
           std::cout << "[" << (int)pixel.x << ", " << (int)pixel.y << "]\n";

        }
    }
}

void reading_four_channel_images(cv::Mat& m){
    CV_Assert(m.size.dims() == 2);  // Ensure that we're dealing with a 2D image.
    CV_Assert( m.type() == CV_8U);
    using Pixel = cv::Vec4b;    // Our pixel type is a vector of four uchars.

    for (int row = 0; row < m.rows; row++){
        for (int col = 0; col < m.cols; col++){
            m.at<Pixel>(row, col) = {0, 0, 0, 0};   // Setting each pixel to zero.
        }
    }

}

// int main(){
//     reading_RGB_image();
//     reading_complex_image();
// }