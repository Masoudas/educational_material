/**
* A compiler can deduce type and non-type arguments from a call, provided the function argument list 
* uniquely identifies the set of template arguments. 
* 
* This is contrary to classes, where type can't be deduced.
* 
*/

#include <string>
using namespace std;

template<typename T, int max>
struct Buffer {
	T buf[max];
public:
	// ...
};



template<typename T, int max>
T& lookup(Buffer<T, max>& b, const char* p) { return b.buf[0]; };

string& f(Buffer<string, 128>& buf, const char* p)	// Bjarne here returns a type called Record! But it seems wrong.
{
	return lookup(buf, p); // use the lookup() where T is string and i is 128
}