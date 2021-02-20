/**
* A compiler may reorder different sections of a class (public, private, protected). Hence, we should be cautios,
* especially if we're trying to initialize classes or struct with all public fields without constructor.
* 
* Consequently, don't define new sections in the class unless it's necessary.
*/
#include <string>
using namespace std;

struct S {
public:
	int w;
	std::string s;

public:
	std::string s1;
};

void creating_an_instance_of_S() {
	S s{ 1, "my God", "I've been shot" };	// Seems to be fine here, but is not in all compilers at least!
}