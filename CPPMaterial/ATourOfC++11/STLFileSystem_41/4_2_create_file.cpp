/**
* Creating files was a trick question! Files are actually created using ofstream for example. Notice however
* how we create a file inside a folder. We create the folder using a separate path, then write another path
*/

#include <filesystem>
#include <iostream>
#include <fstream>
#include <cmath>

namespace fs = std::filesystem;

void create_folder_and_file() {
	fs::path dir{ "./dir" };
	fs::create_directories(dir);
	
	fs::path file_path = dir / "file.txt";

	std::ofstream f{ file_path };	// I suppose!
	f.close();	// Never forget! Never! Never!

	if (fs::exists(file_path) && fs::remove_all(dir)) {
		std::cout << "The file and parent directory have been removed!\n";
	}
}

//int main() {
//	create_folder_and_file();
//}