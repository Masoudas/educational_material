/**
* 
* The filename compent of a path is the last element in the path (Equivalent to 
* relative_path().empty() ? path() : *--end()). Hence, whatever is after separator is not considered a path. 
* For example:
* "/foo/bar.txt" --> "bar.txt"
* "/foo/.bar" --> ".bar"
* "/foo/bar/" --> "" (nothing)
* "/foo/." --> .
* "//host" --> "host"
* 
* The extension method also returns the extension of the path:
* If the filename() component of the generic-format path contains a period (.), and is not one of the special 
* filesystem elements dot or dot-dot, then the extension is the substring beginning at the rightmost period 
* (including the period) and until the end of the pathname.
* If the first character in the filename is a period, that period is ignored (a filename like ".profile" is not 
* treated as an extension. Me: hidden files in Linux are not returned if they don't have an extension)
* If the pathname is either . or .., or if filename() does not contain the . character, then empty path is 
* returned.
*
*/

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

void check_extension()
{
    std::cout << fs::path("/foo/bar.txt").extension() << '\n'
        << fs::path("/foo/.bar.txt").extension() << '\n' // Hidden files in Linux are returned
        << fs::path("/foo/.hidden").extension() << '\n' // Unless they don't have an exception
        << fs::path("/foo/bar.").extension() << '\n'
        << fs::path("/foo/bar").extension() << '\n'
        << fs::path("/foo/bar.txt/bar.cc").extension() << '\n'  // Escapes .txt
        << fs::path("/foo/bar.txt/bar.").extension() << '\n'    // Escapes .txt
        << fs::path("/foo/bar.txt/bar").extension() << '\n'     // Escapes .txt
        << fs::path("/foo/.").extension() << '\n'
        << fs::path("/foo/..").extension() << '\n'
        << fs::path("/foo/..bar").extension() << '\n';          
}

//int main() {
//    check_extension();
//}