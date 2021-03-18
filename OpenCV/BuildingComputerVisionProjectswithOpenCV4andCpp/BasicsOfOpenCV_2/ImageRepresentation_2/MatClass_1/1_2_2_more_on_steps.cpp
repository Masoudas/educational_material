/** This is me:
 * 
 * More accurately, step should have been called the number of bytes we need to move forward to get to the next
 * element (pixel in 2D images, element in higher dim images.)
 * 
 * The definition of step is in terms of number of bytes required to go to the next element, sort of an equivalent
 * to sizeof. Conseuqently, if the image depth (int terms of bytes) doubles, so will the size of step.
 * 
 * Also, note that step is independent of the number of channels, because:
 *  -   For a 2D image, we have two steps, even if it has multiple channels (number of dimensions)
 *  -   For higher dim images, the step dim equals the number of dimensions.
 * 
 * 
 */
#include <opencv2/core.hpp>
#include <iostream>

void print_step(const cv::Mat& m)
{
    cv::MatStep step = m.step;
    std::cout << "And the step vector is: ";
    for (int i = 0; i < m.dims; i++) std::cout << step[i] << '\t';
    std::cout << "\n\n";
}

void step_size(){
    std::cout << "Starting with a one byte depth: \n";
    cv::Mat m1(1, 2, CV_8SC1);
    print_step(m1);

    std::cout << "Changing the sign does not affect step size: \n";
    cv::Mat m5(1, 2, CV_8UC1);
    print_step(m5);

    std::cout << "Increasing the number of channels: \n";
    cv::Mat m3(1, 2, CV_8SC2);
    print_step(m3);

    std::cout << "Doubling the depth: \n";
    cv::Mat m2(1, 2, CV_16SC1);
    print_step(m2);

    std::cout << "Four times the depth: \n";
    cv::Mat m4(1, 2, CV_32SC2);
    print_step(m4);
}

// int main(){
//     step_size();
// }