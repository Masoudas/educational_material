/**
* Well, we really should avoid this question, and I personally have never created an array of base objects
* in my life to point to derived ones. But what can we do, should the need for such an array arise in practice?
* 
* Note that the problem is that the indexing does not work. So, we can't even access the location of the memory
* where the object resides. 
* 
* Perhaps, one solution here is to use a list, so that the pointers are not contiguous, and then use dynamic 
* cast. 
* 
* A better solution pointed out correctly is to use an aggregate of smart pointers and a structure like vector.
* So note that with smart pointers, we can assign a single derived to base pointer (like a normal pointer). Put
* that with the fact that when destroying the array, the destructor is called on the array, and we're good to go.
* Note also that type checking has no probem saying vec[n] = unique_ptr<derived>, because there's an implict
* conversion here. The dynamic case however is always needed
*/
#include <list>
#include <vector>
#include <memory>

struct shape { virtual void m() {} };
struct circle : shape {};

void create_an_aggregate_of_shapes() {
	std::list<shape*> shapes{};

	shapes.push_back(new shape{});
	shapes.push_back(new circle{});

	if (auto x = dynamic_cast<circle*>(shapes.front())) {
		// Fine!
	}
}

void create_an_aggregate_with_smart_pointers_and_vector() {
	std::vector<std::unique_ptr<shape>> shapes{};
	shapes.emplace_back(new shape{});
	shapes.emplace_back(new circle{});

	if (auto x = dynamic_cast<circle*>(shapes[0].get())) {
		// Fine!
	}
}