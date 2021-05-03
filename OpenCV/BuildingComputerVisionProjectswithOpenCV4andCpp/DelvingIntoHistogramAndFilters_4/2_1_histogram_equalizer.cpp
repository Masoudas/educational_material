/**
 * Using this command line app, we can equalize the histogram of colored or grayscale images.
 */

#include <opencv2/core/utility.hpp>
#include <regex>
#include <opencv2/imgcodecs.hpp>
#include <filesystem>
#include <iostream>
#include <opencv2/imgproc.hpp>

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

namespace fs = std::filesystem;

const char* keys = "{h help ? |  ""  |   print help messages }"
                   "{src      |  ""  |   source folder. Default is pwd}"
                   "{dst      |  ""  |   destination folder. Default is src.}"
                   "{argc     |<none>|  images to equalize. Must be non-empty.}";

std::vector<std::string> parse_argc(const std::string& argc){
    std::regex words_regex("[^\\s]+");    // Beginning of string or one or more white space

    std::sregex_iterator begin{argc.begin(), argc.end(), words_regex};
    std::sregex_iterator end{};
    
    std::vector<std::string> result{};
    std::for_each(begin, end, [&result](const auto& name){ 
        result.emplace_back(name.str());
    });
    
    return result;
}

// Set the path from which execution takes place (not the path of executable)
fs::path get_resolved_path(const std::string& src){
    char cCurrentPath[FILENAME_MAX];

    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
         return {};
    }

    if (fs::path{src}.is_relative()){
        auto fullPath = fs::path{cCurrentPath};
        fullPath.append(src);
        return fs::canonical(fullPath);    // Doesn't need to be canonicalized, but ...    
    }

    return cCurrentPath;
}

fs::path generate_write_path(fs::path dst_resolved, const std::string& img){
    auto img_file = fs::path{img};
    auto img_name = img_file.stem().string();
    auto img_extention = img_file.extension().string();
        
    fs::path p_write{dst_resolved};
    p_write.append(img_name + "-equalized." + img_extention);

    return p_write;
}

// Equalize color images.
cv::Mat equalize_color(cv::Mat img){
    std::vector<cv::Mat> bgr{};
    cv::split(img, bgr);

    cv::equalizeHist(bgr[0], bgr[0]);
    cv::equalizeHist(bgr[1], bgr[1]);
    cv::equalizeHist(bgr[2], bgr[2]);

    cv::merge(bgr, img);
    return img;
}

// Equalize gray images
cv::Mat equalize_gray(cv::Mat src){
    cv::Mat dst{};
    cv::equalizeHist(src, dst);

    return dst;
}

void equalize_histogram(int argc, const char** argv){
    using cv::CommandLineParser;
    using std::string;
    
    CommandLineParser parser{argc, argv, keys};
    parser.about("Equalizes the histogram of grayscale or color images."
                 "\nNote: Don't forget to put \'=\' after each option."
                 "\nExample: histogram_equalizer --src=source --dst=dist --argc=\"img1.jpg Img2.jpg\"");

    if (parser.has("h")){
        parser.printMessage();
        return;
    }    

    auto src = parser.get<string>("src");

    auto dst = parser.get<string>("dst");
    if (!parser.has("dst")){
        dst = src;
    }

    auto args = parser.get<string>("argc");
    
    if (!parser.check()){
        parser.printErrors();
        return;
    }

    // Get images as separate strings
    auto imgs = parse_argc(args);

    // Resolve paths based on the path the program has been executed.
    auto src_resolved = get_resolved_path(src);
    auto dst_resolved = get_resolved_path(dst);

    for (const auto& img : imgs){
        fs::path p_read{src_resolved};  // Resolve path
        p_read.append(img);
        
        auto image_original = cv::imread(p_read, cv::IMREAD_UNCHANGED);    // Read the image unchanged, color or gray.

        if (image_original.empty()){
            std::cout << img << " does not exist!\n";
            continue;
        }

        // Perform equalization
        cv::Mat equalized{};
        if (image_original.channels() > 1){
            equalized = equalize_color(image_original);
        }else{
            equalized = equalize_gray(image_original);
        }

        auto p_write = generate_write_path(dst_resolved, img);
        cv::imwrite(p_write, equalized);
    }
}

//int main(int argc, char** argv){
//    equalize_histogram(argc, argv);
//}