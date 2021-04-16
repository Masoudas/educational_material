/**
 * Mouse events and slider control are very useful in computer vision and OpenCV. Using these control users, we 
 * can interact directly with the interface and change the properties of the input images or variables. 
 * 
 * In what follows, we shall provide a simple basic example. In this example:
 *  [1] We draw a circle on the point where the user double clicks
 *  [2] We blur the image with a slidebar. Whenever the user moves the slidebar (with range from 0 to 30,) the
 *      image will be blurred with a filter size corresponding to the position of the slider. The default value
 *      set for the slider will be 12.
 * 
 */
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int default_blur_amount = 12;   // This would be the default slider postition of the blur key on the image.
const char* win_name = "Rose";    

// event indicates the event number. x, y indicate the position, and flags indicate the associated flags.
// userdata points to the matrix associated with this image as a pointer.
void onMouseCallBack(int event, int x, int y, int flags, void* userdata){
    if (cv::MouseEventTypes::EVENT_LBUTTONDBLCLK != event || x <= 0 || y <= 0) return;   // If the given coordinate is less than zero, return.

    auto img = static_cast<cv::Mat*>(userdata); 
    
    // Apply a blur filter of width and height 36.
    cv::circle(*img, {x, y}, 30, {100, 10, 10}, 5);

    // Show the result in the sam window
    cv::imshow(win_name, *img);
}

// Trackbar call back function 
static void onTrackBarChange(int pos, void* userData) { 
    if(pos <= 0) return; 
    // Aux variable for result 
    cv::Mat imgBlur; 

    // Get the pointer input image     
    cv::Mat* img = (cv::Mat*)userData; 
    
    // Apply a blur filter 
    blur(*img, imgBlur, cv::Size(pos, pos)); 

    // Show the result 
    imshow("Rose", imgBlur); 
}

void create_interactive_gui(){
    auto rose = cv::imread("Images/Rose.jpg", cv::IMREAD_COLOR);    // Converts to BGR 8bit unsigned.

    cv::namedWindow(win_name, cv::WINDOW_KEEPRATIO);

    // Set a callback function for the mouse event.
    cv::setMouseCallback(win_name, onMouseCallBack, &rose); 

    // Create a mouse tracker and set a callback function for it.
    cv::createTrackbar("Rose", "Rose", &default_blur_amount, 30, onTrackBarChange, &rose); 
  
    cv::imshow(win_name, rose);
    cv::waitKey(0);
}

//int main(){
//    create_interactive_gui();
//}