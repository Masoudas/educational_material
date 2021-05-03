
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Calculates the histogram and returns it as a row array. The three rows are merged together.
Mat calculate_histogram(const Mat& img){
    vector<Mat> hist{{}, {}, {}};

    auto arr_of_arrs = vector{img}; // Create an array of arrays, to be passed to hist matrix.
    for (int i = 0; i < 3; i++){
        calcHist(arr_of_arrs, {i}, Mat{}, hist[i], {255}, {0, 256});
    }

    Mat hist_merged{};
    merge(hist, hist_merged);
    
    return hist_merged;
}

// The image size we've chosen is 256*256. Hence, we need to normalize the values to fit into that area,
// using the minimax normalization method.
// Note: The book actually normalizes each channel separately, leading to a max of 255 for each. I normalize all
// channels altogether, leading to a max of 255 overall, allowing me to see the relevant peak of channels as
// well.
void normalize_to_img_size(Mat img){
    normalize(img, img, 0, 255, NormTypes::NORM_MINMAX);
}

// I'm going to take a more modest approach here, and get 3D points from the image.
// Notice the subtraction 255 from each value. If wasn't there, the histogram would have been flipped.
Mat draw_histogram(Mat img){
    Mat hist_graph{255, 255, CV_8UC3, Scalar(0, 0, 0)};

    Scalar blue{255, 0, 0};
    Scalar green{0, 255, 0};
    Scalar red{0, 0, 255};
    for (int i = 0; i < 255; i++){
        auto pt1 = img.at<Point3f>(i);
        auto pt2 = img.at<Point3f>(i+1);

        line(hist_graph, Point2f{i, 255 - pt1.x}, Point2f{i+1, 255 - pt2.x}, blue, 2);
        line(hist_graph, Point2f{i, 255 - pt1.y}, Point2f{i+1, 255 - pt2.y}, green, 2);
        line(hist_graph, Point2f{i, 255 - pt1.z}, Point2f{i+1, 255 - pt2.z}, red, 2);
    }

    return hist_graph;
}

void draw_histogram(){
    auto img_path = samples::findFile("lena.jpg");
    auto img = imread(img_path);    // By default, reads color images as 8 bit.

    if (img.empty()) std::cout << "Lena is not in the samples\n";

    img = calculate_histogram(img);
    normalize_to_img_size(img);

    auto hist_graph = draw_histogram(img);

    namedWindow("Lena histogram", WINDOW_FREERATIO);   
    imshow("Lena histogram", hist_graph);
    waitKey(0);
}

//int main(){
//    draw_histogram();
//}