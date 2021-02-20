/**
* The path class defines a path (relative or absolute). Note the very interesting way of adding subfolders
* to current path. The = returns the value of equality from right to left, so we use /= to define the address.
* (Note that path1 = ... means path1{ fs::current_path() /= "Functions_12"}, which in turn means 
* path1{ fs::current_path().operator("Functions_12")}. This is because /= is an operator of this class, so is
* /. Note however that operator/ returns a new object).
* 
* To check whether a path exists (which is fundamental to many of our applications), we can use a method called
* exists, which is not part of this class, but rather an stand-alone method. Similarly, is_directory, is_file,
* is_symlink check for the corresponding elements. See next file for some examples.
* 
* 
* There are several methods for this class, other methods are discussed elsewhere:
* - operator += Don't use it. Same as /=, but does not add separator.
* - clear: Clears the content of the object.
* - empty: Checks whether the object is empty (not whether the path exists, or has files, etc).
* - parent_path: Gives the parent path. This is usually what we seek, and not root_name. or root_folder, which are
*	totally different things. The result is a path whose generic format pathname is the longest prefix of the  
*	generic format pathname of *this that produces one fewer element in its iteration. Naturally, if this is the
*	root folder, returns the root folder.
* -	stem: Returns the filename identified by the generic-format path stripped of its extension, as a file.
* - begin and end: Returns the elements of the path, but not in a human way! The sequence is root, root directory,
* sequence of file-names, omitting any directory separators, If there is a directory separator after the last 
* file-name in the path, the last element before the end iterator is an empty element. So for example:
--- Windows ---
Examining the path "C:\users\abcdef\AppData\Local\Temp\" through iterators gives
"C:" │ "/" │ "users" │ "abcdef" │ "AppData" │ "Local" │ "Temp" │ "" │

--- UNIX ---
Examining the path "/home/user/.config/Cppcheck/Cppcheck-GUI.conf" through iterators gives
"/" │ "home" │ "user" │ ".config" │ "Cppcheck" │ "Cppcheck-GUI.conf" │
*/
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void define_path() {
	fs::path path1 = "Functions_12";
	path1 /= "ArgumentPassing_9";	// Adding more path	
	fs::path path2 = fs::current_path() / "Functions_12";	// Also ok, because there's an operator/.

	std::cout << "Printing individual parts of the path, divided by separators:\n";
	for(auto& path_parts : path2) {
		std::cout << path_parts << '\n';
	}

	std::cout << "Parent folder is " << path1.parent_path();
	
}

//int main() {
//	define_path();
//}