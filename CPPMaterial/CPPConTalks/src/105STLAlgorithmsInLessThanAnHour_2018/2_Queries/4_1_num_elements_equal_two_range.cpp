/**
* Exercise: Count at how many locations are two ranges equal? For example, {1, 2, 3, 4} and {1, 3, 4, 2} are 
* equal at one position. It should (?) return 1 for an empty vector (if two empty vectors are not equal at any
* location, then they're not equal!).
* 
* Solution: There's no function that directly does this for us, and the count method of queries only determines
* the number of times an
* 
* One solution is to use mismatch. It returns the first element where two ranges are unequal. We could consider it
* as the complement of how many elements are unequal.
* 
* How would we solve the same problem, but instead counting the number of unequal elements? Well, the implementation
* is almost the same. Point is that for two partially equal ranges like {1, 2} and {1, 2, 3, 4}, we return 0, and 
* depending on the context, I believe this to be correct.
*/

#include <algorithm>
#include <vector>
#include <iostream>

template<typename Itr1, typename Itr2>
int n_elements_equal_two_range(Itr1 begin1, Itr1 end1, Itr2 begin2, Itr2 end2) {
	if (end1 == begin1 && end2 == begin2) {
		return 1;
	}

	int count = 0;
	std::pair<Itr1, Itr2> last{begin1, begin2};
	while (true) {
		auto p_last = last.first;
		last = std::mismatch(last.first, end1, last.second, end2);
		count += std::distance(p_last, last.first);
		
		if (last.first == end1 || last.second == end2) return count;
		last.first++; last.second++;
	}

}

void test_n_elements_equal_two_range() {
	std::vector<int> v{}, v1{ 1 };

	int c1 = n_elements_equal_two_range(v.cbegin(), v.cend(), v1.cbegin(), v1.cend());
	int c2 = n_elements_equal_two_range(v1.cbegin(), v1.cend(), v.cbegin(), v.cend());
	std::cout << "Zero equal elements for empty and non-empty range " << c1 << ", " << c2 << '\n';

	std::vector<int> v2{ 1, 2, 3}, v3{ 1, 3, 3 };
	int c3 = n_elements_equal_two_range(v2.cbegin(), v2.cend(), v3.cbegin(), v3.cend());
	int c4 = n_elements_equal_two_range(v3.cbegin(), v3.cend(), v2.cbegin(), v2.cend());
	std::cout << "Two equal elements for randomly equal ranges " << c3 << ", " << c4 << '\n';

	std::vector<int> v4{ 1, 2, 3, 4, 5 }, v5{ 1, 2, 3 };
	int c5 = n_elements_equal_two_range(v4.cbegin(), v4.cend(), v5.cbegin(), v5.cend());
	int c6 = n_elements_equal_two_range(v5.cbegin(), v5.cend(), v4.cbegin(), v4.cend());
	std::cout << "Two partial equal ranges " << c5 << ", " << c6 << '\n';
}

template<typename Itr1, typename Itr2>
int n_unequal_elements(Itr1 begin1, Itr1 end1, Itr2 begin2, Itr2 end2) {
	if (end1 == begin1 || end2 == begin2) {
		return 1;
	}

	int count = 0;
	std::pair<Itr1, Itr2> last{ begin1, begin2 };
	while (true) {
		last = std::mismatch(last.first, end1, last.second, end2);
		if (last.first == end1 || last.second == end2) return count;
		last.first++; last.second++;
		count++;
	}
}

void test_n_elements_unequal_two_range() {
	std::vector<int> v{}, v1{ 1 };

	int c1 = n_unequal_elements(v.cbegin(), v.cend(), v1.cbegin(), v1.cend());
	int c2 = n_unequal_elements(v1.cbegin(), v1.cend(), v.cbegin(), v.cend());
	std::cout << "One unequal element for empty and non-empty range " << c1 << ", " << c2 << '\n';

	std::vector<int> v2{ 1, 2, 3 }, v3{ 1, 3, 3 };
	int c3 = n_unequal_elements(v2.cbegin(), v2.cend(), v3.cbegin(), v3.cend());
	int c4 = n_unequal_elements(v3.cbegin(), v3.cend(), v2.cbegin(), v2.cend());
	std::cout << "One unequal elements for randomly equivalent ranges " << c3 << ", " << c4 << '\n';

	std::vector<int> v4{ 1, 2, 3, 4, 5 }, v5{ 1, 2, 3 };
	int c5 = n_unequal_elements(v4.cbegin(), v4.cend(), v5.cbegin(), v5.cend());
	int c6 = n_unequal_elements(v5.cbegin(), v5.cend(), v4.cbegin(), v4.cend());
	std::cout << "Two partial equal ranges " << c5 << ", " << c6 << '\n';
}

//int main() {
//}