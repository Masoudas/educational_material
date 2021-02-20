/**
* This is an easy one. Separate a file name from its extension, among a vector of file names.
* 
* Solution: For this one, we simply need to use regex_match. I also want to say we can use char and space
* and some other special chars as the possible name. Notice how matching the dot outside a group is
* much more important than matching the dot inside the group!
*/
#include <vector>
#include <regex>
#include <string>
#include <iostream>

void separate_file_name_and_extension() {
	std::vector<std::string> files{"image.jpg", "view 1.txt", "#q!.mama.bmp"};

	std::regex pattern{R"(([-\.\w!@#\$%\^&;,=\+\s]+)\.([\w]+))"};

	std::smatch match{};
	for (auto& file : files) {
		if (std::regex_match(file, match, pattern)) {
			std::cout << "\nFile name is: " << match[1] << " and extension is: " << match[2];
		}
	}
}

//int main() {
//	separate_file_name_and_extension();
//}