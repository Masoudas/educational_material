/**
* We consider only a declaration; template function definitions and the definition of class members 
* are not considered (or generated) unless they are actually used.
* For example, the declaration of mean() #1 is fine for mean(p,p+n). The compiler does not start to instantiate the
* body of that mean() and eliminate it because of the type error.
* 
* Here, the result is an ambiguity error. Had mean() #2 not been present, declaration #1 would 
* have been chosen and we would have suffered an instantiation-time error. Thus, a function may be 
* chosen as the best match yet still fail to compile (me: due to run-time error?)
* 
* A point on overload resolution below: In the following, mean_3 is resolved as int* mean_3<int*>(int*, int*)
* for the first one and int* mean_3<int>(int*, int*) for the second one. So technically, there should
* have been an error. But VS does not throw an error. It chooses the second mean!!!
*/
#include <iostream>
#include <vector>
using namespace std;

template<typename Iter>
Iter mean_3(Iter first, Iter last) // #1
{
	// typename Iter::value_type = *first;	// This is just a line that was supposed to	
											// return a (compile or run?)-time error
	cout << "no pointer version\n";
	using w = typename Iter::value_type;	
	// ...

	return Iter{};
}
template<typename T>
T* mean_3(T*, T*) { cout << "pointer version\n";  return new T{}; }; // #2

void what_is_this(vector<int>& v, int* p, int n)
{
	auto x = mean_3(v.begin(), v.end()); // OK: call #1
	auto y = mean_3(p, p + n); // error : ambiguous 
}

//int main() {
//	vector<int> x{};
//	what_is_this(x, {}, {});
//}