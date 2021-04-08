/**
 * The following two functions can be used to determine whether a certain file has readers and writers associated 
 * with it. Note the path must point to an existing image file! Otherwise, false is returned (hence, it does
 * actually read some header information from the file, to say the least.)
 * 
 *      -   bool cv::haveImageReader(const String& filename) 	   
 *      Returns true if the specified image can be decoded by OpenCV.
 * 
 *      -   bool cv::haveImageWriter(const String& filename) 	
 *      Returns true if an image with the specified filename can be encoded by OpenCV. 
 *      
 */
#include <opencv2/imgcodecs.hpp>
#include <iostream>

void check_has_reader_writer(){
    if (cv::haveImageReader("i.jpeg")){ // Has none, because file does not exist.
        std::cout << "This image has a reader.\n";
    } else {
        std::cout << "This image does not have a reader.\n";
    }

    if (cv::haveImageReader("Images/Horse-Movie.gif")){ // Has none, because gif files have no reader!
        std::cout << "This image has a reader.\n";
    } else {
        std::cout << "This image does not have a reader.\n";
    }
}

//int main(){
//    check_has_reader_writer();
//}
