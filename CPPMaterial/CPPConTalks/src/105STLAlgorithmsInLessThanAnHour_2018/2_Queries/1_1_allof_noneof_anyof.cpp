/**
* allof: Checks if unary predicate is true for all of the collection. 
* Note: If the collection is empty, the predicate is not violated. Therefore, allof returns true.
* 
* anyof: Checks if unary predicate p returns true for at least one element in the range.
* Note: If the collection is empty, returns false, because no element satisfies the predicate.
* 
* noneof: Checks if unary predicate p returns true for no elements in the range [first, last)
* Note: For an empty collection, returns true, because no element in the range returns true.
* 
* Note on how we pass the predicate with bind:
* bind, binds functions together. So, we need to pass modululs(value, mod), but mode need to be passed
* beforehand, so we give a placeholder_1 for argument (meaning don't put anything there), and then 2
* for the second argument (meaning place_holder_1 is mod 2).)
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <functional>

using std::vector;

void checking_empty_collection() {
	vector<int> v{};

	auto pred = [](int v) {return true; };

	bool allof = std::all_of(v.begin(), v.end(), pred);
	bool anyof = std::any_of(v.begin(), v.end(), pred);
	bool noneof = std::none_of(v.begin(), v.end(), pred);

	std::cout << "all_of returns true: " << allof;
	std::cout << "\nany_of returns false: " << anyof;
	std::cout << "\nnone_of returns true: " << noneof;
}

void checking_various_divisions() {
    std::vector<int> v(10, 2);
    std::partial_sum(v.cbegin(), v.cend(), v.begin());

    std::cout << "Among the numbers: ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    if (std::all_of(v.cbegin(), v.cend(), [](int i) { return i % 2 == 0; })) {
        std::cout << "All numbers are even\n";
    }

    // This was indeed cool!
    if (std::none_of(v.cbegin(), v.cend(), std::bind(std::modulus<int>(), std::placeholders::_1, 2))) {
        std::cout << "None of them are odd\n";
    }

    struct DivisibleBy
    {
        const int d;
        DivisibleBy(int n) : d(n) {}
        bool operator()(int n) const { return n % d == 0; }
    };

    if (std::any_of(v.cbegin(), v.cend(), DivisibleBy{7})) {
        std::cout << "At least one number is divisible by 7\n";
    }
}

//int main() {
//	checking_empty_collection();
//}