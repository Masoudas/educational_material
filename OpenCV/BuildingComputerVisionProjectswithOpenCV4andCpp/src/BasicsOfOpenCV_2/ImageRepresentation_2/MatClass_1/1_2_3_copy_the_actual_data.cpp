/**
 * The question that may arise at this point is, how can we copy the data if we really wanted to? The answer is that
 * we need to use the copyTo or clone method of the matrix, as shown below.
 * 
 */

#include <opencv2/core.hpp>

void copy_entire_image(cv::Mat o){  // Again, note that this is still a thin wrapper around the data, despite the
                                    // fact that a copy takes place.
    cv::Mat cp1 = o.clone();

    cv::Mat cp2{};
    o.copyTo(cp2);

    // There's also a constructor for this end 'cv::Mat(cv::Mat m, bool copyData)'
    cv::Mat cp3{o, true};
}

void copy_sub_image(cv::Mat o){
    cv::Mat sub1 = cv::Mat{o, cv::Rect{10,10,100,100}}.clone(); // Makes a submatrix, but requires an intermediary
                                                                // step.

}