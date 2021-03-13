/**
 * Consider the following example, in which we generate a sub-image of the original image using a new ROI. We note
 * that even in these two cases, the nely generated image still points to the original image:
 * 
 * 
 */

#include <opencv2/core.hpp>

void creating_sub_images(cv::Mat o){
    cv::Mat sub1{o, cv::Rect{10, 10, 100, 100}};    // Still points to the original image
                                                    // Note that rect as always is {x,y, width, height}

    cv::Mat sub2 = o(cv::Range::all(), cv::Range(1,3));         
                                // First, note that this the operator() of cv::Mat, so don't be baffled by it!
                                // Second, note that we're using the initializer_list constructor to create a
                                // range vector.
                                // Third, Range::all() is a static method that creates a range object from INT_MIN
                                // to INT_MAX, meaning all possible int values. The second one creates 1 to 3
                                // inclusive. So I'm guess this means copy all pixels and all three RGB channels.

}