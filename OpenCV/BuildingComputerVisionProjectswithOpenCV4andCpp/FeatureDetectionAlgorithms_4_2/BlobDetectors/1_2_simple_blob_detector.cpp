/**
 * SimpleBlobDetector inherits from Feature2D, which inhertis from Algorithm.
 * 
 * In fact, the class SimpleBlobDetector has a static method called create, which we shall discuss next:
 * 
 * static Ptr<SimpleBlobDetector> 	create(
 *      const SimpleBlobDetector::Params &parameters=SimpleBlobDetector::Params())
 * 
 * To create the params, we need to use the Param class, which again, is a static member of this class.
 * Note that we can read properties from a file as well.
 * 
 * As we shall show with the following example, the use of each filter first has to be declared by setting its
 * value to 1 (like filterByColor = 1,) then its range will be specified. If range has to be maximum, must be
 * set to numeric::limit<>.
 * 
 * The detection method is as actually inherited from the Feature2D part of the class as follows:
 *      -   virtual void cv::Feature2D::detect 	(InputArray image, std::vector<KeyPoint>& keypoints,
 *          InputArray mask = noArray())
 *          For detecting a single image
 *      -   virtual void cv::Feature2D::detect(InputArrayOfArrays images, 
 *          std::vector<std::vector<KeyPoint>>& keypoints, InputArrayOfArrays masks = noArray())
 *          For detecting an array of images. Note that we should pass a container (like a vector.) 	 	 
 * 
 * Note interestingly the drawKeyPoints method and how it's used. 
 * 
 * As another side note, see how we add noise to the image.
 */


#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include <random>

using namespace cv;
using std::vector;

SimpleBlobDetector::Params create_blob_detector_params(){
    SimpleBlobDetector::Params params{};
    
    // Filter by color
    params.filterByColor = false; 
    params.blobColor = 255; // Only detect blobs with this particular value.

    // Filter by area
    params.filterByArea = true;
    params.maxArea = 4 * 10 * 10 * M_PI;
    params.minArea = 0.1 * 10 * 10 * M_PI;

    params.thresholdStep = 10;
    params.minThreshold = 0;
    params.maxThreshold = 260;

    params.filterByConvexity = false;
    params.filterByCircularity = false;
    params.filterByInertia = false;

    params.minDistBetweenBlobs = 1;
    params.minRepeatability = 10;

    return params;
}

vector<KeyPoint> detect_blobs(cv::Mat img){
    auto params = create_blob_detector_params();

    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    vector<KeyPoint> pts{};    
    detector->detect(img, pts);

    return pts;
}

int main(){
    auto img = cv::Mat{512, 512, CV_8UC3, Scalar(0,0,0)};
 
    std::random_device rd{};
    std::mt19937 rand{rd()};
    std::uniform_int_distribution<> dis(2, 512);
    for (int i = 0; i < 10; i++){
        auto center_x = dis(rand), center_y = dis(rand);
        circle(img, {center_x, center_y}, 10, Scalar{128, 128, 128}, -1);   // White circles
    }

    // Add noise to the image
    cv::RNG rng{};
    cv::Mat noise{512, 512, CV_8UC3, Scalar(0,0,0)};
    rng.fill(noise, cv::RNG::NORMAL, cv::Scalar(0), cv::Scalar(100));
    img = img + noise;

    // Detecting blobs
    auto pts = detect_blobs(img);    
    
    auto img_cp = cv::Mat{};
    drawKeypoints(img, pts, img_cp, Scalar(0,0,200), DrawMatchesFlags::DEFAULT);
    
    imshow("Original", img);
    imshow("Centers", img_cp);
    waitKey(0);

}