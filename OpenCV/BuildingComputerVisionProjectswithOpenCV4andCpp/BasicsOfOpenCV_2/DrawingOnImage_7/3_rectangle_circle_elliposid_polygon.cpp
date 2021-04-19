/**
 * In the same manner, we can draw circles and lines. The polygon function is the most interesting one, as
 * it fills inside a shape of arbitrary vertices. Below, we also answer how to fill inside these shapes:
 * 
 *  -   void cv::circle(InputOutputArray img, Point center, int	radius, const Scalar& color, 
 *      int thickness = 1, int lineType = LINE_8, int shift = 0)
 *      
 *  -   void cv::rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, int	thickness = 1,
 *		int  	lineType = LINE_8, int shift = 0) 	 	
 *
 *  -   void cv::ellipse(InputOutputArray img, Point center, Size axes, double angle, double startAngle,
 *		double endAngle, const Scalar& color, int thickness = 1, int lineType = LINE_8, int shift = 0) 	
 *      Me: The doc on this one is long and complicated. Read as needed.
 *  
 *  -   void cv::ellipse2Poly(Point center, Size axes, int angle, int arcStart, int arcEnd, int delta,
 *		std::vector<Point>& pts) 	
 *      Approximates an ellipsoid with a polynomial and returns the points.
 * 
 *  -   void cv::fillConvexPoly(InputOutputArray img, const Point* pts, int npts, const Scalar& color,
 *		int lineType = LINE_8, int shift = 0) 	
 *      The function cv::fillConvexPoly draws a filled convex polygon. This function is much faster than the 
 *      function fillPoly . It can fill not only convex polygons but any monotonic polygon without 
 *      self-intersections, that is, a polygon whose contour intersects every horizontal line (scan line) 
 *      twice at the most (though, its top-most and/or the bottom edge could be horizontal).
 * 
 *  -   void cv::fillPoly(InputOutputArray img, InputArrayOfArrays pts, const Scalar& color, 
 *      int lineType = LINE_8, int shift = 0, Point offset = Point()) 	
 * 
 * Question: How do we fill inside the circle? This is where the ellipse2Poly function becomes handy. We
 * get the polynomial points we seek, and then feed them to the fill convex poly.
 *
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void draw_various_shapes(){
    cv::Mat img{1024, 1024, CV_8UC3, {255, 255, 255}};

    // Draw a circle and fill it as well.
    cv::circle(img, {512, 512}, 100, {0, 0, 255}, 12);

    /// Getting area of circle points.
    std::vector<cv::Point> pts{};
    cv::ellipse2Poly({512, 512}, {100, 100}, 0, 0, 360, 10, pts);
    cv::fillConvexPoly(img, pts, {0, 255, 0});

    // And a rectangle, which can be filled with fill convex poly very easily, because we know the vertices.
    cv::rectangle(img, cv::Rect2i{10, 10, 300, 300}, {255, 0, 128}, 12);

    cv::namedWindow("Shapes", cv::WINDOW_KEEPRATIO);
    cv::imshow("Shapes", img);    
    cv::waitKey(0);
}

int main(){
    draw_various_shapes();
}