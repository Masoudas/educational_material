/**
 * In this example, we try and compute the maximum and minimum of a matrix. Note that the method only works with
 * single channel images. As we can see the method minMaxIds returns the location and the value of both min and
 * min. We could only get the location with minMaxLoc. Note that this method computes the min and max ONLY for
 * single channel images.
 *
 * To compute the min max for a multi-channel image, we have to either:
 *      - use Mat::reshape to reinterpret the matrix as a single channel image. We can extract the min and max of
 *        the entire image with it.
 *      - use extractChannel method to extract one channel of the image. We can extract the min and max of the
 *        channel we seek.
 *        Note: We can't do this with simply defining an ROI, because that would extract the entire image channels.
 *        As a final exercise, we use this method to compute the min and max of the magnitude of each element of
 *        a complex image. The problem with this exercise is that an uchar value is satured once multiplication
 *        takes place. Hence, large values are satured, and we can't extract min or max properly. To solve this 
 *        problem, when we extract the planes, we need to cast them to float matrices, which we can using the
 *        convertTo methods.
 * 
*/

#include <opencv2/core.hpp>
#include <iostream>

void compute_min_max_single_channel(){
    cv::Mat m1{2,2, CV_16UC1, cv::Scalar(7)}; // A 7 matrix.

    auto ptr = m1.ptr<ushort>();
    *ptr = 12; ptr[1] = 140; ptr[2] = cv::saturate_cast<ushort>(-2);  // Just to remind you what saturate cast is.

    double min, max; int min_loc, max_loc;
    cv::minMaxIdx(m1, &min, &max, &min_loc, &max_loc);

    std::cout << "Minimum of matrix is located at: " << min_loc << " and its values is: " << min; 
    std::cout << "\nMaximum of matrix is located at: " << max_loc << " and its values is: " << max << '\n'; 
}

void min_max_multiChannel_reshape(){
    cv::Mat m1{2,2, CV_32FC2, cv::Scalar(2,7)}; // An imaginary image of 2+7j

    auto ptr = m1.ptr<float>();
    *ptr = 12.2; *++ptr = 22.2; ptr[7] = 0.5;

    auto single_channel = m1.reshape(1);    // We could put this back to m1, but for now, let's create a new
                                            // single channel matrix. That being said, note that the underlying
                                            // data is not copied.

    if (single_channel.ptr<float>() == m1.ptr<float>()){
        std::cout << "\nThe reshaped matrix points to the same data as the original mat\n\n";
    }

    int min_loc, max_loc; double min, max; 
    cv::minMaxIdx(single_channel,  &min, &max, &min_loc, &max_loc);
    
    std::cout << "Minimum of matrix is located at: " << min_loc << " and its values is: " << min; 
    std::cout << "\nMaximum of matrix is located at: " << max_loc << " and its values is: " << max << "\n\n"; 
}

void min_max_multichannel_extract_channel(){
    cv::Mat m1{2, 2, CV_8SC2, cv::Scalar(127, -128)};

    auto ptr = m1.ptr<schar>();     // Note the use of schar instead of char here.
    ptr[0] = 12; ptr[5] = 15; ptr[7] = -1;

    // No need to specify anything for these matrices. They would be uploaded with create method.
    cv::Mat plane1{};
    cv::Mat plane2{};

    cv::extractChannel(m1, plane1, 0); cv::extractChannel(m1, plane2, 1);


    int min_loc_1, max_loc_1; double min_1, max_1; 
    cv::minMaxIdx(plane1,  &min_1, &max_1, &min_loc_1, &max_loc_1);

    
    std::cout << "Minimum of plane 1 is located at: " << min_loc_1 << " and its values is: " << min_1; 
    std::cout << "\nMaximum of plane 1 is located at: " << max_loc_1 << " and its values is: " << max_1 << '\n'; 
}

void min_max_complex_magnitudes(){
    cv::Mat m1{2, 2, CV_8SC2, cv::Scalar(127, -128)};

    auto ptr = m1.ptr<schar>();     // Note the use of schar instead of char here.
    ptr[0] = 0; ptr[1] = 15;        // Hence, min is 15 and max is sqrt(127^2 + 128^2)

    cv::Mat plane1{};
    cv::Mat plane2{};

    cv::extractChannel(m1, plane1, 0); cv::extractChannel(m1, plane2, 1);
    plane1.convertTo(plane1, CV_32F); plane2.convertTo(plane2, CV_32F);

    auto sum = plane1.mul(plane1) + plane2.mul(plane2) ; // This is A^2+B^2, which is good enough to calculate 
    // cv::sqrt() We could calculate sqrt, but that's unnecessary calculation. 

    // The more sophisticated way of calculating the magnitude vectors
    cv::Mat magnitudes{};
    cv::magnitude(plane1, plane2, magnitudes);
    std::cout << magnitudes;
    
    int min_loc, max_loc; double min, max; 
    cv::minMaxIdx(sum,  &min, &max, &min_loc, &max_loc);
    
    std::cout << "Minimum of image magnitude is located at: " << min_loc << " and its values is: " << cv::sqrt(min); 
    std::cout << "\nMaximum of image magnitude is located at: " << max_loc << 
        " and its values is: " << cv::sqrt(max) << '\n'; 
}

int main(){
    min_max_complex_magnitudes();
    //min_max_multiChannel_reshape();
}