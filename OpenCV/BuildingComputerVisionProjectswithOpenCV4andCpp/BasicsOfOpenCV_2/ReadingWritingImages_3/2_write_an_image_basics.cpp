/**
 * To write an image, we can use the imwrite method, which accepts a path and an instance of cv::Mat. 
 * 
 * Note that we can't save arbitrary pixel depths with this method, which we shall discuss later on.
 * 
 * Here's something interesting regarding this code. Note that the waitKey function returns an int, which is the
 * key pressed by the user. We can use this key value (given in int) to for example save the image with the char
 * 's'.
 */

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

void img_write_sample(const cv::Mat& m){
    cv::imshow("window one", m);
    int key = cv::waitKey(0);

    if (key == 's'){
        cv::imwrite("image.jpeg", m);
    }
}