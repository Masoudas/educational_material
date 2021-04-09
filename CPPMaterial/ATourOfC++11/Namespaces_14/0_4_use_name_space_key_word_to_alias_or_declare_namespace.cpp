/**
* If you want to use a namespace, or want to alias it, don't forget to use the namespace keyword behind it
*/
#include <filesystem>
#include <thread>

using namespace std::chrono_literals;	// Using declarative
namespace fs = std::filesystem;	// Creates a new space for filesystem, hence, we don't have to scope to std::filesystem
								// every time.