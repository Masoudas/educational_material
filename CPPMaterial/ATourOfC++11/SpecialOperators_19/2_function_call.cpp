/**
* As we're already aware, the functional operator of a class is overridden using the syntax
* void operator()().
* 
* An operator()() must be a non-static member function. Function call operators are often templates.
* 
* Now consider the following example. Note that for_each accesses the iterator's value by dereferencing it (*itr). In other
* words for (auto x : collection) is actually 'auto x = reference to collection', depending on whether iterator returns a
* reference or not.
* 
* Keeping this point in mind, take a look at the following function, where we pass our complex as the operator to for each.
* As must be clear now, the function uses the operator(), then that one accepts by reference, and adds the current
* value to the given position. Neat!
* 
* FYI, in case you missed it, for each returns the functional. In fact, note that none of the arguments of for_each are
* taken by reference.
* 
*/

#include <complex>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;
class Add {
	std::complex<double> val;
public:
	Add(std::complex<double> c) :val{ c } { } // save a value
	Add(double r, double i) :val{ r,i } { }
	void operator()(std::complex<double>& c) const { c += val; } // add a value to argument
};

void addition_using_for_each(vector<complex<double>>& vec, list<complex<double>>& lst, complex<double> z)
{
	auto result = for_each(vec.begin(), vec.end(), Add{ 2,3 });
	for_each(lst.begin(), lst.end(), Add{ z });
}

void more_standard_method_of_addition(vector<complex<double>>& vec, complex<double> z) {
	// This method creates an extra class when adding to the current element.
	std::transform(vec.cbegin(), vec.cend(), vec.begin(), [&](const complex<double>& val) {
		return val + z;
		});

	// This method does not create an extra class, hence, it's actually better when it comes to transforming the elements!
	std::for_each(vec.begin(), vec.end(), [&](auto& val) { val += z; });
}