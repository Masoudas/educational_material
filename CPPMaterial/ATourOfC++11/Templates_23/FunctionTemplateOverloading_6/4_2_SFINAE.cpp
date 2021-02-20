/**
* To solve the problem with the previous declaration, we can add a new overload that does not require
* the value type.
* 
* This solution works, because when compiler uses the first version, it sees a non-sensical type (int*::value_type)
* and then just ignores it and moves to the other possiblities.
* 
* There is a language rule (§iso.14.8.2) that says that such a substitution failure is not an error.
* It simply causes the template to be ignored. Without it, compiler would've returned an error.
* 
* The rule is known under the unpronounceable acronym SFINAE (Substitution Failure Is Not An Error).
* Hence for example, we say constructor was eliminated by substitution failure (it was SFINAEd).
*/

#include <vector>
using namespace std;

template<typename Iter>
typename Iter::value_type mean_2(Iter first, Iter last) { return {}; };

template<typename Iter>
typename Iter mean_2(Iter* first, Iter* last) { return Iter{}; };


void making_a_sensical_template(vector<int>& v, int* p, int n) {
	auto x = mean_2(v.begin(), v.end()); // OK
	auto y = mean_2(p, p + n); // error.
}