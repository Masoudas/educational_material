/**
 * Me: When writing text on an image, the font size may not mean much. In fact, we need to convert the pixel
 * height we seek for our text into a size, and then feed it to the putText function. The getFontScale does
 * this for us. Another interesting function here calculates the dimension of the text we have. Also, don't
 * forget that highgui has an addText method for adding text to images.
 * 
 * Later on, we shall implement a test, in which we write text in an image using the putText function on a
 * click on the image. We shall use the text size function to ensure that the text can be put properly at
 * the boundary of the image, and if not, we don't put it.
 * 
 *  -   double cv::getFontScaleFromHeight(const int fontFace, const int pixelHeight, const int thickness = 1)
 *      Calculates the font-specific size to use to achieve a given height in pixels.  	
 * 
 *  -   Size cv::getTextSize(const String& text, int fontFace, double fontScale, int thickness, int* baseLine) 	
 *      Calculates the width and height of a text string. 
 *      Me: Notice that this gets the font scale.
 * 
 *  -   void cv::putText(InputOutputArray img, const String& text, Point org, int fontFace, double fontScale,
 *		Scalar color, int thickness = 1, int lineType = LINE_8, bool bottomLeftOrigin = false)
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

const double scale = cv::getFontScaleFromHeight(cv::HersheyFonts::FONT_HERSHEY_COMPLEX, 30, 8);
int base_line = 0;
const cv::Size text_bd = cv::getTextSize(
    "Click!", cv::HersheyFonts::FONT_HERSHEY_COMPLEX, scale, 8, &base_line);


void mouse_click_event(int event, int x, int y, int flag, void* data){
    if (event != cv::MouseEventTypes::EVENT_LBUTTONDBLCLK) return;

    if ((text_bd.width > cv::abs(512 - x)) || (text_bd.height > cv::abs(512 - y))) return;

    auto img = static_cast<cv::Mat*>(data);
    cv::putText(*img, "Click!", {x,y}, cv::HersheyFonts::FONT_HERSHEY_COMPLEX, scale, {0,0,255}, 8);
    cv::imshow("Click", *img);
}

void main_window_program(){
    cv::namedWindow("Click", cv::WINDOW_KEEPRATIO);

    cv::Mat img{512, 512, CV_8UC3, {0, 0, 0} };   // Make a white image.

    cv::setMouseCallback("Click", mouse_click_event, &img);
    cv::imshow("Click", img);
    cv::waitKey(0);
}

int main(){
    main_window_program();
}

