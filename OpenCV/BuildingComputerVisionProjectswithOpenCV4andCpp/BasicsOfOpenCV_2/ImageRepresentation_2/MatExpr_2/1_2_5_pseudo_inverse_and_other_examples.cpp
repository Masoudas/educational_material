/**
 * The following examples are taken from the OpenCV documentation, where we try to compute the pseudo inverse or
 * the levenberg-marquardt step in Gaussian optimization, among other things.
 * 
 * Note that the inverse enumeration flags are in the opencv2/core/base.hpp header.
 * 
 */

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

// Note that psuede inverse can only be computed for floats
void pseude_inverse_for_non_rectangular_mat(){
    cv::Mat m{2, 3, CV_32F, cv::Scalar{2}};

    // Method I
    cv::MatExpr direct_svd = m.inv(cv::DECOMP_SVD); // Nice to know
    std::cout << direct_svd;

    // Method II
    cv::SVD svd{m};  // Ok!
    cv::Mat pinvA = svd.vt.t()*cv::Mat::diag(1./svd.w)*svd.u.t();   // This is the formula for SVD, and we have
                                                                    // the u and v matrices, and in the middle the
                                                                    // mat of eigenvalues. Printing the result 
                                                                    // shows that it actually does not work, because
                                                                    // it can't compute one of the eignevals.
    std::cout << "\n\n" << pinvA << "\n\n";
}

// Suppose that A is the derivate, and x is the current value, and err is the error vector.
void levenberg_marquardt_update_step(const cv::Mat& A, const cv::Mat& err, cv::Mat& x, float lambda){
    x -= (A.t()*A + lambda*cv::Mat::eye(A.cols,A.cols,A.type())).inv(cv::DECOMP_CHOLESKY)*(A.t()*err);
}

// Sharpening image using "unsharp mask" algorithm. It really does sharpen the image to an extent.
cv::Mat sharpen_using_unsharp_mask(cv::Mat& img){
    cv::Mat blurred; double sigma = 1, threshold = 5, amount = 1;
    
    cv::GaussianBlur(img, blurred, cv::Size{}, sigma, sigma);

    cv::Mat lowContrastMask = abs(img - blurred) < threshold;
    cv::Mat sharpened = img*(1+amount) + blurred*(-amount);
    img.copyTo(sharpened, lowContrastMask);

    return sharpened;
}

//int main(){
////    pseude_inverse_for_non_rectangular_mat();
//
//    // Sharpenning algorithm in action
//    auto img = cv::imread("./Images/Rose.jpg");
//    auto sharpend = sharpen_using_unsharp_mask(img);
//
//    cv::imshow("Original", img);
//    cv::imshow("Sharpended image", sharpend);
//    cv::waitKey(0);
//
//}
