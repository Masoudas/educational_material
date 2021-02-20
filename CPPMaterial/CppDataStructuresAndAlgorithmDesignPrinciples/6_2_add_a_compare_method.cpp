/** This is me:
* In the following exercise, we create a new namespace stda, which has a comparison method augmented for
* containers that checks for less.
* 
* What's wrong with this implementation? First, note that we implicitly assume that the type of container
* implements < operator. Moreover, it's assumed that left and right have equal number of elements. This is
* for example not the case for array.
* 
* There's another subtle problem. Because std has an overload for operator < with array for example, ADL
* will prefer the method of std over the method of stda. Hence, if I import std into my namespace, I've 
* dragged the method of std, hence, it's prefered over my overload!
* 
* Now, if I try this method with a vector and an array, once again ADL fails. This one is due to template
* in operator defintion. Of course, one solution to this and the previous problem is to just have a using declarative.
* (unless it's ambiguous and we're not sure which version of operator< is dragged. Although we can be certain
* it's the last declared version, because declaration takes precedence it appears)
* 
*/
#include <array>
#include <iostream>
#include <vector>

namespace stda {
	using namespace std;

	template <typename Cont1, typename Cont2>
	bool operator<(const Cont1& left, const Cont2& right) {
		using _Itr_l = typename Cont1::const_iterator;
		using _Itr_r = typename Cont2::const_iterator;

		_Itr_l begin1 = left.cbegin();
		_Itr_r begin2 = right.cbegin();

		_Itr_l end1 = left.cend();
		_Itr_r end2 = right.cend();

		bool less = true;
		for (; begin1 != end1 && less; ++begin1)
		{
			less = (*begin1 < *begin2);
			++begin2;
		}

		return less;
	}
}

//int main() {
//	using stda::array;
//	using stda::cout;
//	using stda::vector;
//	using stda::operator<;
//
//	array<int, 3> arr{ 1, 2, 3 };
//	array<int, 3> arr1{ 4, 2, 6 };
//
//	bool isLess = stda::operator<(arr , arr1);	// Except I specifically call for operator from stda, this
//												 will prefer the operator of std in this case!
//	if (!isLess) cout << "arr is not less than arr1\n";
//	else cout << "arr is less than arr1\n";
//
//	vector<int> vec{ 4, 5, 6 };
//	isLess = arr < vec;
//
//	if (!isLess) cout << "arr is not less than vec\n";
//	else cout << "arr is less than vec\n";
//}