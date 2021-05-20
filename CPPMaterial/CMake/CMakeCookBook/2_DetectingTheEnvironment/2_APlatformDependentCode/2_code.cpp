/**
 * Consider the following example, where the source code we've provided is actually platform dependent.
 * 
 * As we discussed in the previous file, the IS_WINDOWS, IS_LINUX or IS_MACOS are definitions we provide. Note that EXIT_SUCCESS
 * is part of cstdlib.
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