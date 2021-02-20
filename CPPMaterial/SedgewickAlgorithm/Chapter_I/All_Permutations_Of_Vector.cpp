/**
* Here's an interesting problem. Generate all permutations of a given vector.
* 
* Solution I: Consider a tree, starting with (0,1), with two branches true and false. If false, we switch
* 0 and 1, if false, then not. Now, each child will be (0, 2). We continue this way until (0, N-1). Now,
* we say (1, 2), then (1, 3) ... . Hence, the entire tree structure (with all nodes of each level indicating
* the same exchange) will construct all possible permutations.
* 
* Solution II: The proposed algorithm is to look for the natural (sort) order of the algorithm in reverse order 
* (last index where array is decreasing). Then choose the element after where the array start increasing
* ( 5 3 1 2 4, choose 2). Call this increase. Then find the greatest index in the reverse natural order 
* st the element st i < increase_value. Then swap these two elements. Then reverse index[0] and index[increase].
* 
* Solution with stl: There's an stl method called next_permutation and previous_permutation in stl.
* Notice how the constructor in this solution asks for both an iterator and a pointer.
*/
#include <array>
#include <type_traits>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

template<typename T, int N>
void print_arr(const T* arr) {
	cout << "[\t";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << "]\n";
}

int factorial(int n) {
	if (n < 0) return 1;
	int fact = 1;
	for (int i = 2; i <= n; i++) { fact *= i; }
	return fact;
};

template <typename T, int SIZE_T, int N>
class all_permutations_I {
	using _Tp = T*;

	array<T, N> seed;
	array<int, N> count{};
	array<int, N> total{};
	queue<T> q{};

public:
	all_permutations_I(_Tp begin) : seed{ array<T, N>{} } {
		memcpy(&seed[0], begin, SIZE_T * N);
		fill(&count[0], &count[N - 1] + 1, 1);

		for (int j = 0; j < N; j++) {
			total[j] = N - j;
		}

		count[N - 1] = 0;
	}

	array<T, N> next(){
		int j = N - 1;
		for (; j >= 0;) {
			if (count[j] == total[j]) {
				count[j] = 1;
				q.push(std::move(seed[j]));

				j--;
			}
			else {
				++count[j];
				q.push(std::move(seed[j]));
				break;
			}
		}


		for (; j < N; j++) {
			seed[j] = q.front();
			q.pop();
		}

		return seed;
	}

	void static test() {
		array<int, 2> arr{ 1, 2 };

		all_permutations_I<int, sizeof(int), arr.size()> perms{ &arr[0] };


		for (int i = 1; i <= factorial(arr.size()); i++)
		{
			cout << "Permutation " << i << ": ";
			print_arr<int, arr.size()>(perms.next());
		}
	}

};

template<typename T>
class all_permutations_with_stl {
	using _Tp = T*;
	vector<T> next_perm{};

public:
	using iterator = typename vector<T>::iterator;

public:
	template<typename iterator>
	all_permutations_with_stl(iterator begin, iterator end) {
		for (; begin != end ; begin++) {
			next_perm.push_back(*begin);	// No move here, to keep the original vector.
		}

	}

	all_permutations_with_stl(_Tp begin, _Tp end) {
		ptrdiff_t N = end - begin;
		for (int i = 0; i < N ; i++) {
			next_perm.push_back(begin[i]);	// No move here, to keep the original vector.
		}

	}

	iterator next() {
		next_permutation(next_perm.begin(), next_perm.end());
		return next_perm.begin();
	}

};

void test_solution_II() {
	array<int, 3> arr{ 1, 2, 3 };

	all_permutations_with_stl<int> perms{ &arr[0], &arr[2] + 1 };

	for (int i = 1; i <= factorial(arr.size()); i++)
	{
		cout << "Permutation " << i << ": ";
		auto next_perm = perms.next();
		print_arr<int, arr.size()>(&next_perm[0]);
	}
}

//int main() {
//	test_solution_II();
//}