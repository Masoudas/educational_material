/**
 *  -   void cv::Canny(InputArray image, OutputArray edges, double threshold1, double threshold2, 
 *          int apertureSize=3, bool L2gradient=false)
 *       -   apertureSize	aperture size for the Sobel operator.
 *       -   L2gradient	a flag, indicating whether a more accurate L2  should be used to calculate 
 *           the image gradient magnitude ( L2gradient=true ), or whether the default L1 norm
 *           is enough ( L2gradient=false ). 
 * 
 * -    void cv::Canny(InputArray dx, InputArray dy, OutputArray edges, double threshold1, double threshold2, 
 *      bool L2gradient=false)
 *      Supply the result of sobel algorithm directly.
 *      -   dx:	16-bit x derivative of input image (CV_16SC1 or CV_16SC3).
 *      -   dy:	16-bit y derivative of input image (same type as dx). 
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

void detect_edge_using_canny(Mat img){
    Mat edges{};

    while(true){
        std::string str1{};
        std::getline(std::cin, str1, '\n');
        
        std::string str2{};
        std::getline(std::cin, str2, '\n');
        double tr1 = std::atof(str1.c_str()), tr2 = std::atof(str2.c_str());
        
        Canny(img, edges, tr1, tr2);

        imshow("Original image", img);
        imshow("edges", edges);
        waitKey(0);
    }
}

//int main(){
//    auto lena = imread(samples::findFile("lena.jpg"));
//
//    detect_edge_using_canny(lena);
//}