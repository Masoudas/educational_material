/**
 * In this example, we're going to write an int, then a mat into a single file! Then, we're going to read them
 * from this file.
 * 
 * Because as we said the structure of the FileStorage is a Yaml/XML format, we need only to provide a label
 * when we write the data. Once we read it, we can access this label using the bracker operator, as we show
 * below.
 * 
 * Note critically that we need to release the file handle in the end.
 */

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

// Writing an int and a mat to a file storage.
void write_data_to_file_storage(){
    int norm = 10;
    cv::Mat result{ 2, 2, CV_16U, cv::Scalar(10)};

    // Note that mode also has append, as well as other options. Creates the file too.
    cv::FileStorage fs("information.yaml", cv::FileStorage::Mode::WRITE);    

    // Supply the label first, then the value.
    fs << "norm" << 10;
    fs << "result_mat" << result;

    fs.release();
}

void read_data_from_file_storage(){
    int norm;
    cv::Mat result;

    cv::FileStorage fs("information.yaml", cv::FileStorage::Mode::READ);

    fs["norm"] >> norm;
    fs["result_mat"] >> result;

    std::cout << "Norm was " << norm << '\n';
    std::cout << "\nResult matrix was:\n" << result << "\n\n";

    // Just as a reminder :D
    fs::path p{"information.yaml"};    // Resolved to current folder.
    fs::remove(p);
}

int main(){
    write_data_to_file_storage();
    read_data_from_file_storage();
}