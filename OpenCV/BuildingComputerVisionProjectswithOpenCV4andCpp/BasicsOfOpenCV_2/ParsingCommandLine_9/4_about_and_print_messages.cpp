/**
 * The about method allows us to write an about message about our command line parser. The printMessage prints
 * that message, meaning the about command content together with the help messages for the options.
 * 
 * Notice when we print the help command. We check whether the user has passed a help or aliases to us right 
 * after having defined the parser. If this is the case, then we print messages.
 */

#include <opencv2/core/utility.hpp>

int when_to_print_parsers_help(int argc, const char* const argv[]){
    const char* keys = "{h help ? | | Prints help}"
                        "{n | | Number of elements }";

    cv::CommandLineParser parser{argc, argv, keys};

    parser.about("This is an application from the command line");

    if (parser.has("h")){
        parser.printMessage();
        return 0;
    }
}

//int main(int argc, const char* const argv[]){
//    return when_to_print_parsers_help(argc, argv);
//}