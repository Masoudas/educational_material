/**
* When we talk about checking for existence of a path, we need to resolve relative paths. Hence, we must not
* be worried about checking the existence of relative paths. For completeness, however, we have the following
* discussion.
* 
* Before discussing this, there's a class called file_status, which stores information about the type and 
* permissions of a file. We can get the file status of a path using fs::status() method. status can determine:
* If p is a regular file, a directory, is a socket, pip or pipe file, If p does not exist,
* If p exists but file attributes cannot be determined, e.g. due to lack of permissions, and many other things,
* and otherwise, returns file_status(file_type::unknown, prms).
* 
* The method exists of file system checks for existence of a path. The path can be a file, or folder (which as
* we always say, is considered another file). In other words,  checks that: 
* status_known(s) && s.type() != file_type::not_found is true.
* 
* When creating an status object, the relative path is resolved naturally, to check for existence of the file.
* What do we do with relative paths? Well, they're resolved by the function, so no need to worry, though from
* now on, I'd always prefer to absolutize relative paths.
*/

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void solving_relative_paths() {
	fs::path p1{ ".././" };

	std::cout << fs::exists(p1);	// Path has to be resolved! Returns true.
}

//int main() {
//	solving_relative_paths();
//}