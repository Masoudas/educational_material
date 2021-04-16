/**
* We can use Enable_if for a wide variety of predicates, including many tests of type properties. Concepts are 
* among the most general and useful predicates we have. Ideally, we would like to overload based on concepts, 
* but lacking language support for concepts, the best we can do is to use enable_if to select based on 
* constraints.
* 
* Me: Assume that Ordered is a concept, meaning Order can be defined for the type, see chapter 23.
* Me: Well, the big guy is using enable if with its negate, which people say we shouldn't do!
* 
* These calls are resolved as described in using_fct because we can use < for an int but not for a 
* complex<int>. enable_if resolves to void if we don’t provide a type argument.
* 
* Note: The following example does not compile in MSVC, because MSVC does not allow us to use enable_if
* with its negate. So I commented it.
*/
#include <type_traits>
#include <vector>
#include <complex>

template<typename T>
constexpr bool Ordered() {
	// Look, this should be ordered, but I couldn't find anything, so I just wrote abstract.
	return std::is_abstract_v<T>;
}

//template<typename T>
//std::enable_if<Ordered<T>()> fct(T*, T*) {}; // optimized implementation

//template<typename T>
//std::enable_if<!Ordered<T>()> fct(T*, T*) {}; // nonoptimized implementation

using namespace std;
void using_fct(vector<int>& vi, vector<complex<int>>& vc)
{
	if (vi.size()==0 || vc.size()==0) throw runtime_error("bad fct arg");
//	fct(&vi.front(),&vi.back()); // call optimized
//	fct(&vc.front(),&vc.back()); // call nonoptimized
}