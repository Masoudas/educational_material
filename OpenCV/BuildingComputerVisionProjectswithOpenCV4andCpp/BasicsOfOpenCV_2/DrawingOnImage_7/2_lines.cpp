/**
 * OpenCV provides several line drawing functions. Don't forget that an image read is BGR, which we should 
 * pay attention to when choosing color:
 * 
 *  - void cv::arrowedLine(InputOutputArray img, Point pt1, Point pt2, const Scalar& color,
 *		int thickness = 1, int line_type = 8, int shift = 0, double tipLength = 0.1) 	
 *
 *      Parameters:
 *          -   shift	Number of fractional bits in the point coordinates.
 * 
 *  - bool cv::clipLine(Size imgSize, Point& pt1, Point& pt2)
 *      calculates a part of the line segment that is entirely within the specified rectangle. it returns 
 *      false if the line segment is completely outside the rectangle. Otherwise, it returns true. 
 *      Me: Hence, useful to ensure that the line is at least partially inside the image.
 * 
 *  - void cv::drawMarker(InputOutputArray img, Point position, const Scalar& color, 
 *      int markerType = MARKER_CROSS, int markerSize = 20, int thickness = 1, int line_type = 8)
 *      Draws a marker on a predefined position in an image.  	
 * 
 *  - void cv::line(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, int thickness = 1,
 *		int lineType = LINE_8, int shift = 0) 		
 *      Draws a line between the given points.
 * 
 *  - void cv::polylines(InputOutputArray img, InputArrayOfArrays pts, bool isClosed, const Scalar& color,
 *		int thickness = 1, int lineType = LINE_8, int shift = 0) 	
 *      Draws several polygonal curves.
 *      
 *      Parameters:
 *          -   isClosed	Flag indicating whether the drawn polylines are closed or not. If they are closed, 
 *              the function draws a line from the last vertex of each curve to its first vertex.
 * 
 */ 	 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void draw_various_lines(){
    auto rose = cv::imread("Images/Rose.jpg", cv::IMREAD_UNCHANGED);

    // Draw a blue line.
    cv::line(rose, {10, 10}, {300, 300}, {255, 0, 0}, 8, cv::LineTypes::LINE_AA);

    // Draw a red arrowed line.
    cv::arrowedLine(rose, {670, 70}, {840, 340}, {0,0, 255}, 8, cv::LineTypes::FILLED);

    // Draw a green poly line between the given coordinates.
    cv::polylines(rose, std::vector{cv::Point2i{300, 300}, cv::Point2i{300, 400}, cv::Point2i{550, 400}}, 
        true, {0, 255, 0}, 8, cv::LineTypes::LINE_8);

    cv::namedWindow("Rose with line", cv::WINDOW_GUI_EXPANDED);
    cv::imshow("Rose with line", rose);

    cv::waitKey(0);
}

void clip_line_example(){
    cv::Size s{512, 512};
    cv::Point2i p1{10, 10}, p2{20,20};

    if (cv::clipLine(s, p1, p2))
        std::cout << "The line between " << p1 << " and " << p2 << " is in an image of size " << s << '\n';
}

//int main(){
//    clip_line_example();
//    draw_various_lines();
//}