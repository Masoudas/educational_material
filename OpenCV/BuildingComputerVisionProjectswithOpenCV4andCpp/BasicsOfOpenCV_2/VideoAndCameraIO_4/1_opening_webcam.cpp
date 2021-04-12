/**
 * Note: Apparently, we can do very crazy things like openning youtube videos with VideoCapture as well.
 * 
 * Note II: On my current Linux machine, my Laptop Webcam is video0 for
 */

#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

void read_webcam(){
    cv::VideoCapture cap{"Images/AVI-Video.avi", cv::CAP_FFMPEG};
    cap.setExceptionMode(true);
    
    
    cv::Mat frame{};
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