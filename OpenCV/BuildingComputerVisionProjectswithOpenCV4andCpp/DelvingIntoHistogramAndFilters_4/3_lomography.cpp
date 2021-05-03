/**
 * In the following example, we first apply a LUT to the green plane of the image for some nicer effect. Then,
 * we create a halo around the center of the image, allowing LenaReal to have focus around her beautiful face.
 * 
 * The look up table we use here is nothing but 1 / (1 + e-[(x - 0.5)/s]). What this LUT does is that it makes
 * darker values darker and ligher values ligher. Of course, we use an LUT to apply this function to the image,
 * which would save us CPU cycles.
 * 
 * For the halo, we can create a circle, and the blur it. Then, all we need to do is to apply this effect to an
 * RGB image is to just multiply it (in float format of course) to the image. Why? Because darker values (closer)
 * to 0 would mask BGR values.
 * 
 */
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;

void lomoGraphy(Mat img) 
{ 
    Mat result; 
 
    const double exponential_e = std::exp(1.0); 
    // Create Look-up table for color curve effect 
    Mat lut(1, 256, CV_8UC1); 
    for (int i=0; i<256; i++) 
    { 
        float x= (float)i/256.0;  
        lut.at<uchar>(i)= cvRound( 256 * (1/(1 + pow(exponential_e, -((x-0.5)/0.1)) )) ); 
    } 
    
    // Split the image channels and apply curve transform only to red channel 
    std::vector<Mat> bgr; 
    split(img, bgr); 
    LUT(bgr[2], lut, bgr[2]); 
    // merge result 
    merge(bgr, result); 
    
    // Create image for halo dark 
    Mat halo(img.rows, img.cols, CV_32FC3, Scalar(0.3,0.3,0.3) ); 
    // Create circle  
    circle(halo, Point(img.cols/2, img.rows/2), img.cols/3, Scalar(1,1,1), -1);  
    blur(halo, halo, Size(img.cols/3, img.cols/3)); 
     
    // Convert the result to float to allow multiply by 1 factor 
    Mat resultf; 
    result.convertTo(resultf, CV_32FC3); 
     
    // Multiply our result with halo 
    multiply(resultf, halo, resultf); 
     
    // convert to 8 bits 
    resultf.convertTo(result, CV_8UC3); 
 
    // show result 
    imshow("Lomography", result); 
    waitKey(0);
} 

int main(){
    auto lena = samples::findFile("lena.jpg");
    auto img = imread(lena);

    imshow("lena", img);
    lomoGraphy(img);
}