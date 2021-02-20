/**
* Because unordered sets are, well, unordered, we can't compare them with the methods of std::algorithm. This
* particularly pertains to std::equal, because this method requires an iterator. But as we already know, the
* iterators of set are unstable.
* 
* We can, however, use == operator of the set to compare for equality between two sets. Of course, without that,
* we could have simply used the contains method of the set.
* 
* Note that if one set is subset of another, then they're still unequal;
*/

#include <unordered_set>
#include <iostream>

void sets_equal() {
	std::unordered_set<int> s1{ 1, 2, 3, 4 };
	std::unordered_set<int> s2{ 1, 2, 3 };

	if (s1 != s2) std::cout << "Set1 is not equal to set2\n";
	
	if (s1 == std::unordered_set<int>{1, 2, 3, 4}) std::cout << "Set1 is equal to lvalue set2\n";

}

//int main() {
//	sets_equal();
//}