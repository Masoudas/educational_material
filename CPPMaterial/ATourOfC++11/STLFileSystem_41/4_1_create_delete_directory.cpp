/**
* create_directory: Creates the directory p as if by POSIX mkdir() with a second argument of 
* static_cast<int>(std::filesystem::perms::all) (the parent directory must already exist). 
* If the function fails because p resolves to an existing directory, no error is reported. 
* Otherwise on failure an error is reported (by this we mean other issues like permission for example.
* 
* The overload  create_directory( const std::filesystem::path& p, const std::filesystem::path& existing_p ) makes
* a directory, except that the attributes of the new directory are copied from existing_p (which must be a 
* directory that exists) 
* 
* create_directories: Executes (1) for every element of p that does not already exist. If p already exists, the 
* function does nothing (this condition is not treated as an error).
* 
* remove: removes the file, or the directory (if the directory is empty).
* remove_all: and the contents of all its subdirectories, recursively, then deletes p itself as if by repeatedly 
* applying the POSIX remove. symlinks are removed, but not the path they refer to.
* 
* To throw a little curve ball, take a look at std::system below, for executing system commands.
* 
* As a little warning, if we say 'dir/file.txt', then what create_directory(ies) does is that it creates
* file.txt (more precisely, it throws exception ffor create_directory, because dir does not exist). So, we
* must create a folder by making sure that it does not contain a folder at the end.
* 
* As a bonus point, is_empty method checks whether the given directory is empty or not.
*/

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void examples_of_create_delete_dir() {
	fs::path p1{"./dir"};

	fs::create_directory(p1, ".");	// It's best to always use this overload, to ensure that the properties
									// are created properly.

	if (fs::exists(p1) && fs::is_empty(p1)) {
		std::cout << "The directory has been created and is empty\n";
	}

	if (fs::remove(p1)) {
		std::cout << "The directory has been removed\n";
	}

	std::system("tree .");
}

//int main() {
//	examples_of_create_delete_dir();
//}