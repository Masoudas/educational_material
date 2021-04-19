/**
 * Before we continue discussing how to handle various events on the OpenCV GUI, we should recall three things:
 * 
 *  -   An event:   An entity that's generated upon an interaction of the user with the GUI.
 *  -   Event handler:  A function written by the programmer, saying what should be done in case of that event.
 *      This entity is sometimes called a callback_handler.
 *  -   Event setting: The act of defining an operation to take place in the program. This is called set call
 *      back handler of something in OpenCV, like setMouseCallback.
 * 
 * Hence for example, we set the event "Right click on the image", which generates the event "Right click",
 * for which we define an action called "handle_right_click."
 * 
 * As we may recall, events had a name, and a flag. The flag for example refers to whether another key was held
 * during the event or not.
 * 
 * In what follows, we have a bare bone example of handling events. A couple of points are crucial here to 
 * mention:
 *  -   make namedWindows first: If we don't make a named window, and then just set an event, the compiler would
 *      throw an error in our face, because it doesn't know to which window it should assign this event.
 *  -   Each event set comes with a call_back method that's just a function pointer. For example, the signature
 *      for the mouseCallback call back handler is as follows:
 *              typedef void (*MouseCallback)(int event, int x, int y, int flags, void* userdata);
 *  -   Events and their flags are enumerations as we can see. Hence, to check whether a particular even has 
 *      occured, we need to check on the event number and flag. So, they're not classes.
 *  -   The event setter allows us to pass data as void pointer. Hence for example in this case, we passed a
 *      structure that contains our image.
 * 
 * Note: An important note when dealing with events is that events don't update the image automatically. Hence,
 * we need to always update the image inside the event function by EXPLICITLY calling the imshow function.
 * 
 */


#include <opencv2/highgui.hpp>
#include <iostream>

struct image{
    cv::Mat m;
};

// Event call back.
void mouse_call_back(int event, int x, int y, int flags, void* userdata){
    std::cout << "(x=" << x << ", y=" << y << ")\n";

    // Accessing callback data
    auto data = static_cast<image*>(userdata);
}

int main(){
    image im{{512, 512, CV_8UC3, cv::Scalar{127, 64, 186}}};   // interpreted as BGR.

    cv::namedWindow("My", cv::WINDOW_GUI_EXPANDED);
    cv::setMouseCallback("My", mouse_call_back, &im);    // Set on event.

    cv::imshow("My", im.m);
    cv::waitKey(0);
}