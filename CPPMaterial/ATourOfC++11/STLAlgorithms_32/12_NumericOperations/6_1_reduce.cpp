/** 
* Me: The point of attention about reduce is the way we pass the binary operation. That is, the first element
* is of type T&&, which is actually init being passed everytime for accumulation. Hence, signature of op is 
* T op(T&&, const T1&), or T op('const' T&, const T1&). Note that if we use the first one, we can possibly
* save one copy as discussed in chapter 7. References_5, 0_1_assigning_rvalue .... Another way is to define
* the signautre as T op(T, const T1&). With this signature, we can still have no copies if we write 

return std::move(a) + T1;	// Uses operator+ if exists.

* 
* Me: Note that this op is possibly not ordered, like accumulate. That is, accumulate may group elements for 
* its purposes.
* 
*	-	constexpr typename std::iterator_traits<InputIt>::value_type reduce(InputIt first, InputIt last) (1)
*	-	constexpr T reduce(InputIt first, InputIt last, T init);	(3)
*	-	constexpr T reduce(InputIt first, InputIt last, T init, BinaryOp binary_op); (5)
*	(1)	same as reduce(first, last, typename std::iterator_traits<InputIt>::value_type{})
*	(3)	same as reduce(first, last, init, std::plus<>())
*	(3)	Reduces the range [first; last), possibly permuted and aggregated in unspecified manner, along with 
*		the initial value init over binary_op. 
* 
*/

#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <execution>
#include <functional>
#include <iomanip>

using std::vector;

void count_collection() {
	vector<int> v{ 1, 2, 3, 4 };

	int c = std::count(v.begin(), v.end(), 2);

	//std::count_if()
}

void accumulate_and_reduce() {
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	auto dash_fold = [](std::string a, int b) {	// Note that no copy takes place when passing init inside.
		return a + '-' + std::to_string(b);		// Now, a string copy has taken place because of operator+()
		//return std::move(a) + '-' + std::to_string(b);	// No copies now, due to 'operator+()&&'
	};

	// This one uses reduce
	std::string s = std::reduce(std::next(v.begin()), v.end(),
		std::to_string(v[0]), // start with first element
		dash_fold);

	// Right fold using reverse iterators, using accumulate
	std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
		std::to_string(v.back()), // start with last element
		dash_fold);

	std::cout << "dash-separated string: " << s << '\n'
		<< "dash-separated string (right-folded): " << rs << '\n';

}

//int main() {
//	accumulate_and_reduce();
//}
