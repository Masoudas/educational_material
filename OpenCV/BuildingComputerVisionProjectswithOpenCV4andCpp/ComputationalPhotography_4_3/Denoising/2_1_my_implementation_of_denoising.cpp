/**
 * In the following example, I implement a denoising filter that averages the given images. 
 * 
 * The point to remember like always is that the summation must be done in a floating point. If we simply
 * add all the images together, we saturate many pixels.
 * 
 * Also for fun, we calculate the PSNR value of a noisy image and denoised image.
 */

#include <opencv2/core.hpp>
#include <numeric>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

// For simplicity, I assumed that we supply an array of images here.
template <typename T>   // Type indicates the underlying image type.
void a_simple_denoising(cv::InputArrayOfArrays arr, cv::Mat& denoised){
    using namespace cv;
    using namespace std;

    int n_images = arr.size().area();   // Total number of images.
    auto first = arr.getMat(0); // First image in the array of supplied images.

    size_t rows = first.rows; size_t cols = first.cols * first.channels();
    if (first.isContinuous()){
        cols = rows * cols;
        rows = 1;
    }

    denoised.create(first.rows, first.cols, first.type());
    for (size_t i = 0; i < rows; i++){
        // Get pointers for all images
        vector<T*> ptrs{};
        for (size_t k = 0; k < n_images; k++){
            ptrs.push_back(arr.getMat(k).ptr<T>(i));
        }

        // Get pointer of destination matrix
        T* dptr = denoised.ptr<T>(i);

        double sum = 0;
        for (size_t j = 0; j < cols; j++){
            sum = std::accumulate(ptrs.begin(), ptrs.end(), 0., 
                [&](double v, const T* ptr)->double{ 
                        return v + ptr[j];
                    }
            );

            dptr[j] = sum / n_images; 
        }
    }
}

int main(){
    using namespace cv;
    using namespace std;
    
    auto rose = imread("Images/Rose.jpg", IMREAD_UNCHANGED);
    auto rose_n1 = rose.clone();
    auto rose_n2 = rose.clone();
    auto rose_n3 = rose.clone();

    RNG noise_gen{};
    Mat noise(rose.rows, rose.cols, rose.type());

    noise_gen.fill(noise, RNG::NORMAL, 0, 20);    
    rose_n1 = rose_n1 + noise;

    noise_gen.fill(noise, RNG::NORMAL, 0, 20);    
    rose_n2 = rose_n2 + noise;

    noise_gen.fill(noise, RNG::NORMAL, 0, 20);    
    rose_n3 = rose_n3 + noise;

    vector<Mat> roses{rose_n1, rose_n2, rose_n3};
    cv::Mat denoised_rose{};
    a_simple_denoising<uchar>(roses, denoised_rose);    

    std::cout << "PSNR of noisy images is:" << PSNR(rose, rose_n1) << " and PSNR of denoised image is: "
        << PSNR(rose, denoised_rose);

    imshow("Denoised Rose", denoised_rose);
    imshow("Rose noise 1", rose_n1);
    imshow("Rose noise 2", rose_n2);
    imshow("Rose noise 3", rose_n3);
    waitKey(0);

}