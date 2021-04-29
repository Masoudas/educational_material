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
* The third useful method in this category is in fact the stem method. This method actually returns the stem of
* the filename. The std documentation says "Returns the filename identified by the generic-format path stripped 
* of its extension. Returns the substring from the beginning of filename() up to and not including the last 
* period (.) character, with the following exceptions:
*   -   If the first character in the filename is a period, that period is ignored (a filename like ".profile" 
*       is not treated as an extension)
*   -   If the filename is one of the special filesystem components dot or dot-dot, or if it has no periods, the 
        function returns the entire filename(). "
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

void check_file_stem(){
     std::cout << fs::path("/foo/bar.txt").stem() << '\n'   // prints bar
              << fs::path("/foo/.bar").stem() << '\n';      // prints .bar
 
    for (fs::path p = "foo.bar.baz.tar"; !p.extension().empty(); p = p.stem())  
        std::cout << p.extension() << '\n'; // Prints .tar first, then .baz, then .bar
                                            
}

//int main() {
//    check_extension();
//}