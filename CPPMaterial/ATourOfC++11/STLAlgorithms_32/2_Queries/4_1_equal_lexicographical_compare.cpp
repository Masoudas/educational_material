/**
* std::equal as opposed to equality using ==, checks whether two collections:
* 1-	Have equal size
* 2-	Have same elements.
* 
* If either condition is violated, false is returned. We can supply a predicate for other forms of compare.
* 
* Question: Do we want to check whether two objects have the same memory address, so as to percipitate the process
* of comparing the two vectors? Or any two objects for that matter? Especially when we overload the == operator
* for two classes? Depends I guess, but generally yes, we want to do that I think!
* 
* lexicographical compare compares two vectors for equality.
* 
* We also have the following comparison for comparing element comparisons, but they're useless compared to 
* functional interfaces:
* -	comp_equal
* -	cmp_greater_equal
* -	cpm_less_equal
* -	...
*/

#include <vector>
#include <execution>
#include <iostream>

using std::vector;

void equality_with_equal() {
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 1, 2 };

	bool eq1 = std::equal(std::execution::par, v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend());
	bool eq2 = std::equal(std::execution::par, v1.cbegin(), v1.cend(), v1.cbegin());
	
	std::cout << "v1 is not equal to v2: " << eq1;
	std::cout << "\nv1 is equal to v1: " << eq2;
}

//int main() {
//	equality_with_equal();
//}