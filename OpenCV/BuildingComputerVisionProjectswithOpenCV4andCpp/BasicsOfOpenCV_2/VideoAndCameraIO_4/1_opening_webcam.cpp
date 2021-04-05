/**
 * Apparently, we can do very crazy things like openning youtube videos with VideoCapture as well, which we 
 * discuss next.
 */

#include <opencv2/highgui.hpp>
#include <iostream>

void read_webcam(){
    //std::string videoFile= cv::parser.get<std::string>(0);
    cv::VideoCapture cap{};
    

    if (!cap.open(0) || !cap.isOpened()){ // Redundant checks
        return;
    }

    cv::Mat frame;
    const char* window_name = "Webcam live feed";
    cv::namedWindow(window_name, cv::WINDOW_FULLSCREEN);

    for (;;){
        cap >> frame;

        std::cout << frame;
        if (!frame.empty()){
            cv::imshow(window_name, frame);
            if (cv::waitKey(30) >= 0) break;
        }
    }
}

int main(){
    read_webcam();
}