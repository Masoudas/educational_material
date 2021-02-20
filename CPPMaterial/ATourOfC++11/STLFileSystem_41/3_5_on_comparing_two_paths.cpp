/**
* How does one compare two paths for equivalence?
* 
* As it turns out, this is not an straight forward problem, as seen in the literature. But two equivalent points 
* help:
* 1- Always resolve paths, and remove dots, etc.
* 2- Never compare relative paths, and I mean NEVER!
* 
* To resolve paths, we can use fs::canonicale or fs::absolute, depending on whether the paths exists or not. Now,
* if the paths exists, the method equivalent does this for us, otherwise, we need to do this by hand.
* In other words, there are two ways of comparing paths:
* 1- Compare methods of path, using <=> or compare: These are not very reliable if the paths are not absolute, as
* comparing_relative_paths_is_dangerous shows. However, once the paths are absolute, they're fine.
* 2- fs::equivalent: This one checks whether the paths p1 and p2 resolve to the same file system entity.
*	If either p1 or p2 does not exist, an error is reported. (Me: Because we're talking about path resolution, then
*	dots and stuff are removed). equivalent also resolves the symbolic links.
*/
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
void comparing_relative_paths_is_dangerous() {
	fs::path p1{"dir/d1"};
	fs::path p2{ "dir/d1/../" };

	if (p2 > p1) {
		std::cout << "dir/d1/.. is greater than dir/d1, which is WRONG!  \n";
	}

	try {
		if (fs::equivalent(p1, p2));
	}
	catch (fs::filesystem_error &e) {
		std::cout << "An exception is caught for equivalent method, because paths don't exist!\n";
	}

	fs::path resolved_p1 = fs::absolute(p1);
	fs::path resolved_p2 = fs::absolute(p2);
	if (resolved_p2 < resolved_p1) {
		std::cout << "After resolving the paths, we finally see that p1 is greater than p2\n";
	}
	
}

//int main() {
//	comparing_relative_paths_is_dangerous();
//}

