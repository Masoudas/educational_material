/**
 *  -   void cv::Mat::forEach<T>(const Functor& operation)
 *  Runs the given functor over all matrix elements in parallel.
 *  The operation passed as argument has to be a function pointer, a function object or a lambda(C++11).
 *
 *  Note on the signature of the functor: Note that the template we pass to the function determines what sort
 *  of pointer we get from the ptr function. Moreover, the second argumenr of the functor is an int* which
 *  indicates the position. Hence, assuming the type is T, then the signature of the functor should be:
 *                          void f(T& value, const int* position)
 *  Notice that just like a normal for each, the pointer is dereferenced.
 * 
 *  As always, note that for 2D images, sz has only two elements.
 */

#include <opencv2/core.hpp>
#include <iostream>

void set_blue_channel_to_0xFF(cv::Mat m){
    using namespace cv;

    using Pixel = Point3_<uint8_t>;     // Safer than using uchar!
    m.forEach<Pixel>([](Pixel& p, const int* sz){ p.x = 0xFF;});    // Literal is uchar as we know it!

}

void set_pixel_to_position(){
    using namespace cv;
    Mat m = Mat::ones(3, 3, CV_8UC3);

    using Pixel = Point3_<uint8_t>;     // Safer than using uchar!
    m.forEach<Pixel>([](Pixel& p, const int* sz){ p.x = sz[0]; p.y = sz[1]; p.z = sz[0] + sz[1];});    

    std::cout << m;
}

int main(){
    set_pixel_to_position();
}