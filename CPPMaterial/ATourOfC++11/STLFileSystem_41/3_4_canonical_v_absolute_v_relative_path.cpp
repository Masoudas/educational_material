/**
* We have three different kinds of path:
* 
* 	--	An absolute path is a path that identifies a file.
*	--  A canonical path is a path that includes neither a symbolic link nor the relative paths "." 
*		(current directory) or ".."(parent directory).
*	--	A relative path specifies a path relative to a location in the file system. Paths such as "." 
*		(current directory), ".."(parent directory) or "home/rainer" are relative paths. On Unix, 
*		 they do not start at the root-directory "/" (note that '/home/rainer' is not a relative path in
*		linux, because it starts from the root dir, which is /).
* 
* When we say file, dirs are ok as well. Afterall, a dir is a file too, so is for example "C:/dir/", or
* "C:/dir/."

* Note that canonical paths are all subsets of absolute paths, and absolute paths are the largest group here.
* For example, 'C:\temp\myapp\bin\..\..\file.txt' is an absolute path, as it clearly specifies the path to a
* file. However, it's not a canonical path, because it contains .. (FYI, the address is C:\temp\file.txt).
* 
* Question is, should we make our paths canonical or absolute when needed? As it appears, making them canonical
* removes all the dots, etc. Therefore. it's superior to making it absolute. The problem however is that a canonical
* path must exist! In fact, there are two functions, absolute and canonical for this end. Note that absolute also 
* removes the dots as well:
* - absolute: Creates a path for which is_absolute returns true. is_absolute returns true of the given path is not
* relative (it does remove dots and other stuff as it appears)
* - canonical: Converts path p to a canonical absolute path, i.e. an absolute path that has no dot, dot-dot 
* elements or symbolic links in its generic format representation. If p is not an absolute path, the function 
* behaves as if it is first made absolute by std::filesystem::absolute(p). The path p MUST exist.
* 
* Defining relative path for unit tests: So when trying to access resources for unit tests, I used to write
* the path without the first dot, like dir/file. While this is Ok, and the path resolution is done properly, I
* always better start my relative paths with ./, like ./dir
*/

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void making_path_absolute() {
    auto current_dir = fs::absolute("");   // Gives Absolute path to current dir, without any dots.

    auto dir = fs::absolute("C:/dir/dir1/../");   // Again, gives back C:/dir

    std::cout << current_dir;
}

void making_path_canonical() {
    try {
        auto current_dir = fs::canonical(".");  // Ok! Because the current path exists. Returns correct path.
        std::cout << "Canonicalized path is: " << current_dir;
    }
    catch (std::error_code &e) {
        // If the path does not exist.
    }

    try {
        auto current_dir = fs::canonical("./nonexistent_dir");  // Ok! Because the current path exists.
    }
    catch (fs::filesystem_error& e) {
        std::cout << "\nThe given path cannot be canonicalized, because it does not exist!\n";
    }
}

void weird_relative_path() {
    // The following is a relative path, because it does not specify the full path to a file. 
    fs::path p = "c:/dir/";
    
    std::cout << "Absolute path for " << p << " is " << p.is_absolute() << '\n';



}
//int main()
//{
//    making_path_absolute();
//}