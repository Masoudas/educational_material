/**
 * Consider the following example, where the source code we've provided is actually platform dependent.
 * 
 * Notice that IS_WINODWS and IS_LINUX macros, ... are in the cstdlib header.
 */

#include <cstdlib>
#include <string>
#include <iostream>

std::string platform(){
#ifdef IS_WINDOWS
    return "Hello from Windows";
#elif IS_LINUX
    return "Hello from Linux";
#elif IS_MACOS
    return "Hello from MAC OS";
#endif
}

int main(){
    std::cout << platform();
    return EXIT_SUCCESS;
}