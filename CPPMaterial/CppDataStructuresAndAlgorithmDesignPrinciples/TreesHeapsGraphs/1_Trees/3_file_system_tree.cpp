/**
* Note that we accept a cwd as well as a root (where the root is always set to '/').
* 
* The cwd can be set by the user, and we need to find the corresponding node each time the user sets it, to make
* search matters easier for example.
* 
* Note the difference between finding just one node in a tree, or the find we implemented here. We are looking
* for a pathway from the root to the final node, so we're in fact traversing on a particular path, rather than
* exhaustively searching all the nodes on the tree.
* 
* Now, when it comes to the add method, we need to check how much of the path has already beed added. Then, 
* we find the last dir that exists in our structure, and then we try and add the new nodes from that point
* on.
* 
* A note on add function: The book assumes that a path to be added only has the last portion of the path not 
* added (for example, to add to /etc, dir/sub_dir is not allowed, but only dir should be there). If we accept
* this proposition, we need to check whether the last portion of the path exists or not, and return true or false
* accordingly. Otherwise, we add this new portion. Note however that we can simply change this strategy by 
* writing a for loop, and adding each remaining portion. The code for doing so looks something like this:
//while (true) {
	// add sub_dir or file to the node, and keep the node
	// if (sub == npos) // add dir or file based on given is_dir flag
	// else // add the next dir.

//if (sub == string_view::npos) return true;
//	auto next_sub = path.find('/', sub + 1);
//	sub_dir = path.substr(sub + 1, next_sub + sub - 1);
//	sub = next_sub;
//}
*/

#include <string_view>
#include <vector>
#include <iostream>
#include <algorithm>

using std::string_view;

struct n_ary_node {
	string_view name;
	bool is_dir;
	std::vector<n_ary_node*> children;
};

struct file_system {
	using node = n_ary_node;
	using node_ptr = node*;

private:
	node_ptr root;
	node_ptr cwd;

public:
	file_system() {
		root = new node{ "/", true, {} };
		cwd = root;
	}

	node_ptr find(const std::string_view& path)
	{
		if (path[0] == '/') {  // Absolute path
			return find_impl(root, path.substr(1));
		}
		else {
			return find_impl(cwd, path);
		}
	}

private:
	node_ptr find_impl(node_ptr directory, const string_view& path) {
		if (path.empty()) return directory;

		auto sep = path.find('/');	// Find the next portion of the path.
		auto dir_name = sep == string_view::npos ? path : path.substr(0, sep);	// extract the name of the dir.

		auto found = std::find_if(directory->children.begin(), directory->children.end(),
			[&](auto child) { return child->name == dir_name; });

		if (found != directory->children.end()) {
			auto path_remainder = sep == string_view::npos ? string_view{ "" } : path.substr(sep + 1);
			return find_impl(*found, path_remainder);
		}
		return nullptr;
	}

public:
	bool add(const std::string_view& path, bool is_dir) {
		if (path[0] == '/') {
			return add_impl(root, path.substr(1), is_dir);
		}
		return add_impl(cwd, path, is_dir);

	}

private:
	bool add_impl(node_ptr directory, const string_view& path, bool is_dir)
	{
		if (!directory->is_dir)
		{
			std::cout << directory->name << " is a file." << std::endl;
			return false;
		}

		auto sub = path.find('/');

		// If this is the last position, ensure that the position does not exist, and if it does, return false.
		if (sub == string_view::npos) {
			auto exists = std::find_if(directory->children.begin(), directory->children.end(),
				[&](const auto node) {
					return node->name == path;
				});
			if (exists == directory->children.end()) {
				directory->children.emplace_back(new node{ path.substr(sub + 1), is_dir, {} });
				return true;
			}
			return false;
		}

		auto sub_dir = path.substr(0, sub);
		auto exists = std::find_if(directory->children.begin(), directory->children.end(),
			[&](const auto node) {
				return node->name == sub_dir && node->is_dir;;
			});

		if (exists == directory->children.end()) { 
			return false;	
		} 
		return add_impl(*exists, path.substr(sub + 1), is_dir);
	}

public:
	bool change_cwd(const string_view& _cwd) {
		auto cwd_node = find(_cwd);

		if (cwd_node && cwd->is_dir) {
			cwd = cwd_node;
			return true;
		}
		return false;
	}

	void show_path(const string_view& path) {
		auto node = find(path);
		if (!node) return;

		if (!node->is_dir) {
			std::cout << "- " << node->name << '\n';
			
		}
		else {
			for (auto child : node->children) {
				std::cout << (child->is_dir ? "d " : "- ") << child->name << "\n";
			}
		}

	}
};

//int main()
//{
//	file_system fs;
//	fs.add("usr", true);  // Add directory usr in "/"
//	fs.add("etc", true);  // Add directory etc in "/"
//	fs.add("var", true);  // Add directory var in "/"
//	fs.add("tmp_file", false);  // Add file tmp_file in "/"
//	
//	std::cout << "Files/Directories under \"/\"" << std::endl;
//	fs.show_path("/");  // List files/directories in "/"
//	std::cout << std::endl;
//
//	fs.change_cwd("usr");
//	fs.add("Packt", true);
//	fs.add("Packt/Downloads", true);
//	fs.add("Packt/Downloads/newFile.cpp", false);
//	
//	std::cout << "Let's see the contents of dir usr: " << std::endl;
//	fs.show_path("usr");  // This will not print the path successfully, since we're already inside the dir usr. 
//						  // And there's no directory named usr inside it.
//
//	std::cout << "Let's see the contents of \"/usr\"" << std::endl;
//	fs.show_path("/usr");
//	std::cout << "Let's see the contents of \"/usr/Packt/Downloads\"" <<
//		std::endl;
//	fs.show_path("/usr/Packt/Downloads");
//
//}