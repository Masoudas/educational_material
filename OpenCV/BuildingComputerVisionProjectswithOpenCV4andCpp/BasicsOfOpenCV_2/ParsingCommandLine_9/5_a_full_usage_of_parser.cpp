/**
 * To summarize the discussion so far, here we have an example from the OpenCV docs that uses the command line
 * parser.
 */

#include <opencv2/core/utility.hpp>

int using_parser_properly(int argc, const char** argv){
    const char* keys =
        "{help h usage ? |      | print this message   }"
        "{@image1        |      | image1 for compare   }"
        "{@image2        |<none>| image2 for compare   }"
        "{@repeat        |1     | number               }"
        "{path           |.     | path to file         }"
        "{fps            | -1.0 | fps for output video }"
        "{N count        |100   | count of objects     }"
        "{ts timestamp   |      | use time stamp       }";
    
    cv::CommandLineParser parser{argc, argv, keys};
    parser.about("This is my first proper command line application");

    // User passed an h option
    if (parser.has("h")){
        parser.printMessage();
        return 0;
    }

    auto path = parser.get<std::string>("path");
    auto N = parser.get<int>("N");
    auto img1 = parser.get<std::string>("@image1");

    // Hypothetically, we need to check existence of image2
    if (parser.has("@image2")){
        // do something
    }

    if (!parser.check()){
        parser.printErrors();
        return 0;
    }
}