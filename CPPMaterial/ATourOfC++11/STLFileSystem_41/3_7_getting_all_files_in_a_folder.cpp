/**
* In this exercise, we get all the files in current directory, and store them (name and extension) as a vector.
* 
* First of all, note that fs::status is used for checking whether we have a file or not. This works fine with
* relative paths as you may recall from 3_6_on_checking_whether ...
* 
* Notice how we get the file name from iterator. It should be noted that even if the path ends in '/', the --end
* would be fine, because the dash does not appear as an address element. That being said, another method of getting
* the file and its name is to use file_name and file_extension. The problem however is that we'd have to create
* two additional path and two additional strings for that.
*/

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void get_all_files_in_current_dir() {
	fs::path p1{ "." };

	std::vector<std::string> files{};

	// Could have used recursive_directory_iterator to go inside folders as well.
	for (fs::directory_entry entr : fs::recursive_directory_iterator(p1)) {
		if (entr.is_regular_file()) {
			auto end = --entr.path().end();
			files.push_back(end->string());
		}
	}

	std::copy(files.cbegin(), files.cend(), std::ostream_iterator<std::string>{std::cout, "\n"});
}

//int main() {
//	get_all_files_in_current_dir();
//}