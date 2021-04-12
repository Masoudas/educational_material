/**
 * Mouse events and slider control are very useful in computer vision and OpenCV. Using these control users, we 
 * can interact directly with the interface and change the properties of the input images or variables. 
 * 
 * In what follows, we shall provide a simple basic example.
 * 
 */
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

const char* win_name = "Rose";    

// event indicates the event number. x, y indicate the position, and flags indicate the associated flags.
// userdata points to the matrix associated with this image as a pointer.
void call_back_action(int event, int x, int y, int flags, void* userdata){
    if (cv::MouseEventTypes::EVENT_LBUTTONDBLCLK != event || x <= 0 || y <= 0) return;   // If the given coordinate is less than zero, return.

    cv::Mat imgBlur; 
    auto img = static_cast<cv::Mat*>(userdata); 
    
    // Apply a blur filter of width and height 36.
    cv::blur(*img, imgBlur, cv::Size{36, 36});

    // Show the result in the sam window
    cv::imshow(win_name, imgBlur);
}

void blur_with_mouse_event(){
    auto rose = cv::imread("Images/Rose.jpg", cv::IMREAD_COLOR);    // Converts to BGR 8bit unsigned.

    cv::namedWindow(win_name, cv::WINDOW_KEEPRATIO);
    cv::setMouseCallback(win_name, call_back_action, &rose);
    
    cv::imshow(win_name, rose);

    cv::waitKey(0);

}

int main(){
    blur_with_mouse_event();
}