/**
 * OpenCV comes with a whole host of sample images. The utility header provides a way to access these sample
 * images. All things related to sample images can be found at the sample namespace. There's also a method
 * to add more paths to the search path, which I'm not going to discuss here.
 * 
 * A note: I had to manually copy the sample images folder from the data path in the opencv git to the 
 * include folder (for fun) and then added the data variable discussed below to my bachrc.
 *      -   cv::String cv::samples::findFile(const cv::String & relative_path, bool required = true,
 *          bool silentMode = false)
 *          Search directories:
 *          -      Directories passed via addSamplesDataSearchPath()
 *          -      OPENCV_SAMPLES_DATA_PATH_HINT environment variable
 *          -      OPENCV_SAMPLES_DATA_PATH environment variable If parameter value is not empty and nothing 
 *                 is found then stop searching. 
 *          -      Detects build/install path based on: a. current working directory (CWD) b. and/or binary 
 *                 module location (opencv_core/opencv_world, doesn't work with static linkage)
 *          -      Scan <source>/{,data,samples/data} directories if build directory is detected or the 
 *                 current directory is in source tree.
 *          -      Scan <install>/share/OpenCV directory if install directory is detected.
 	
 * 
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

void working_with_sample_images(){
    std::string lena_path = cv::samples::findFile("lena.jpg");

    auto im_lena = cv::imread(lena_path, cv::IMREAD_COLOR);
    
    cv::imshow("Lena", im_lena);
    cv::waitKey(0);
}

int main(){
    working_with_sample_images();
}