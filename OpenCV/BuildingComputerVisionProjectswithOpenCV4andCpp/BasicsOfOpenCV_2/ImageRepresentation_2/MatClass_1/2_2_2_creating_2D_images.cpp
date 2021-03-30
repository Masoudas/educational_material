/**
 * Now that we know how to define the pixel resolution and the number of channels, it's time to build a
 * matrix.
 * 
 * The constructors of the Mat class that we use here are these:
 *      - 	Mat (int rows, int cols, int type)
 *  	-   Mat (Size size, int type)
 *      -   Mat (int rows, int cols, int type, const Scalar &s)
 *      -   Mat (Size size, int type, const Scalar &s)
 * 
 * Note that mat can be effortlessly streamed (it has a operator<<.) We can use it to print the content of the image
 * we've created.
 * 
 * Very important note: Mat has an initializer_list constructor, which as we know through the overload resolution
 * rules of constructors takes precedence over argumentative constructors. Now, consider the following initialization:
 
 cv::Mat m{1,2,CV_8UC1}
  
 * In this initialization, we were hoping to create an image with one row, two columns, of type 8UC1. However, this
 * is interpreted as an initializer list constructor, resulting in an int image with elements 1, 2 and 3!!!
 * Therefore, we should be cautious about our choice of constructor.
 */
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


void create_sample_matrix(){
    cv::Mat m1{1, 3, CV_8UC3, cv::Scalar{0,0,255}};
    std::cout << "Created matrix is:" << m1;

    cv::Mat m2{1, 2, CV_8UC3}; // Caution: A matrix with three elements! Not what we expected. Uses init_list
                               // constructor. 
    std::cout << "\nCreated matrix is:"; std::cout << m2;
}

void create_image_with_size_vector(){
    int sz[] = {1, 2};
    cv::Mat m1{2, sz, CV_16UC3, cv::Scalar{0,0,255}};    // Create a 2 dim image, with 1 row and 2 columns and 
                                                         // three channels

    std::cout << "Image has (row, column)=(" << m1.rows << "," << m1.cols << ")\n";
}

void trivial_image(){
    // Note that this image has dim zero, but every non-trivial image has dim >= 2
    cv::Mat m{};

    std::cout << "\nTrivially constructed image has dimension " << m.dims << '\n';
}

//int main(){
    //trivial_image();
    //create_image_with_size_vector();
//}