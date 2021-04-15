/**
 * The new GUI provides a statusbar, a toolbar, and a control panel (the panel I see on top of the window once
 * I show an image in Qt by default). The control panel can have trackbars and buttonbars attached to it. If you 
 * cannot see the control panel, press Ctrl+P or right-click any Qt window and select Display properties window.
 *  
 *  -   To attach a trackbar, the window name parameter must be nullptr.
 *      (Me: A track bar is a slide bar, and has a range position.)
 *      (Me: I checked and this is not true it appears. We can pass an empty string, but not null)
 *  -   To attach a buttonbar, a button must be created. If the last bar attached to the control panel is a 
 *      buttonbar, the new button is added to the right of the last button. If the last bar attached to the 
 *      control panel is a trackbar, or the control panel is empty, a new buttonbar is created. Then, a new 
 *      button is attached to it.
 *      (Me: To actually see the buttons, press the brush thingy on the Qt window.)
 *      (Me: Note that the buttons created appear on all windows, which is a very odd feature.)
 * 
 * The following example is taken from OpenCV docs and shows these detail in action.
 */
#include <opencv2/highgui.hpp>
using namespace cv;

void callbackButton(int state, void *userdata){}
void callbackButton1(int state, void *userdata){}
void callbackButton2(int state, void *userdata){}
void on_mouse(int event, int x, int y, int flags, void *userdata){}

void using_qt_capabilites()
{
    int value = 50;
    int value2 = 0;

    namedWindow("main1",WINDOW_GUI_EXPANDED);
    namedWindow("main2",WINDOW_AUTOSIZE | WINDOW_GUI_EXPANDED);
        
    createTrackbar("track1", "main1", &value, 255,  nullptr);   
    createButton("button2",callbackButton, nullptr, QT_CHECKBOX,1);    // Add buttons to track1
    createButton("button3",callbackButton, nullptr, QT_CHECKBOX,0);

    // Create another track bar.
    createTrackbar( "track2", "main2", &value2, 255, nullptr);
    createButton("button4",callbackButton1,nullptr,QT_RADIOBOX,0);
    createButton("button5",callbackButton2,nullptr,QT_RADIOBOX,1);

    setMouseCallback("main2", on_mouse, nullptr );

    Mat img1 = imread("Images/Rose.jpg");
    imshow("main1", img1);

    VideoCapture video;
    video.open(0);  // Reading device 0.

    Mat img2,img3;
    while( waitKey(33) != 27 )
    {
        video >> img2;
        imshow("main2",img2);
    }

    destroyAllWindows();
}

// int main(){ using_qt_capabilites();}