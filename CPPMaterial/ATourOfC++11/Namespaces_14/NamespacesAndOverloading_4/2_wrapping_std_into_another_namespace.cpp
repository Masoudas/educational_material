/**
* So consider an std method like sort(v.begin(), v.end()). Many std methods don't work directly with containers,
* for granularity reasons (see chapter 32.2). However, let's say we want to provide our own wrapper around
* sort method so that it directly accepts a container. We'll do it as shown below. But here's the point.
* Say we want to use our methods, and we provide a using Estd directive as shown below. Wouldn't there
* be a class between our methods and those of stl? Nope. First of all, note that we don't have a using
* declarative for std in the following code. But let's say we had. Then std has no method that takes a container
* directly. Therefore, we never would have gotten into trouble.
* 
* 
* Here's the more interesting part. If we had removed 'using namespace std' from the definition of Estd,
* this example still would have still worked in using_estd. Especially we wonder, how would the sort(begin, end)
* work, because we didn't declare std. It works, because container is part of std, and naturally, 
* compiler searches for it there! ADL to the rescue.
*/

#include <algorithm>
#include <vector>
#include <iostream>

namespace Estd {
	using namespace std;
	template<class C>
	void sort(C& c) { std::sort(c.begin(), c.end()); }	// Perhaps const C& would be a better choice?
	template<class C, class P>
	void sort(C& c, P p) { std::sort(c.begin(), c.end(), p); }
}

// %%%%%%%%% Imagine the following is in a new file.
using namespace Estd;
template<class T>
void print(const vector<T>& v)
{
	for (auto& x : v)
		std::cout << x << ' ';
	std::cout << '\n';
}

void using_estd()
{
	std::vector<int> v{ 7, 3, 9, 4, 0, 1 };
	sort(v);
	print(v);
	sort(v, [](int x, int y) { return x > y; });
	print(v);
	sort(v.begin(), v.end());
	print(v);
	sort(v.begin(), v.end(), [](int x, int y) { return x > y; });
	print(v);
}