#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Question_1 {
	/*
	* It actually means somehow breaking down the array into two halves. This would imply needing to find the center
	* element (or median element which is actually better, because we can literally divide an array in half). 
	* But then the cost of finding the median can overshadow other costs
	*/
};

class One {
	/*
	* E A S Y Q U E S T I O N.
	* 
	* run I: E A E Y Q U S S T I O N. It returns i = j = 3.
	* replacement: A E E Y Q U S S T I O N
	*/
};

class Two {
	/*
	*  E A S Y Q U E S T I O N
	* 
	*  Partition I : A E E Y Q U S S T I O N (i2 = 3, i1 = 1)
	*  
	*  (lo= i2 hi = end)
	*  Partition II: A E E Q U S S T I O N Y (i1 = i2 = end)
	* 
	*  (lo = i2, hi = end) 
	*   return
	* 
	*  (lo= 3 hi = end - 1)
	*  Partition II: A E E Q N O I T S S U Y 
	*  ...
	*/
};


class Three {
	/*
	* The later the last element is seen in the pivot operation, the later it goes to its location. The latest would
	* be if it's placed at the element before last. 
	* Now, I think the latest would be something like [1 2 3 ... n, n - 1]. How many calls would this take? n-1.
	* 
	* Some people have said floor(N/2), arguing for something like [2 1 4 3 ... n, n - 1], but evidently, at least
	* with the implementation we have in the book, the answer is n-1.
	* 
	* In fact as a rule of thumb, The maximum number cannot be passed over more times than there are spaces available, 
	* since it should always be approaching its right position.
	*/
};

class Four {
	/**
	* [ 1 2 3 ...]
	* [10 9 8 7 6 ...]
	* [10 9 8 7 6 1 2 3 4 5]
	* [1 2 3 4 5 10 9 8 7 6]
	* [2 1 4 3 6 5 ... 10 9]
	* [1 2 3 4 5 6 ....10 9]
	* 
	* All of these vectors require quadratic number of comparisons
	*/
};

template <typename T>
class Five_1 {
	/*
	* One solution was to find the smallest and largest element, and then go over the array and send the 
	* larger element to the back of the array. 
	* 
	* The other solution is a Dijkstra like solution. We keep track of what elements we have witnessed thus far.
	* If we see an element that is larger, we restart the index to that larger element. Otherwise, if we see an
	* smaller element, we replace it with the first element in the list (the snake!).
	* 
	*/
	static void sort_two_element(T* begin, T* end) {
		int N = end - begin;

		int first = 0; int index = 0; 
		T v = begin[0];
		while (++index < N) {
			T c = begin[index];
			if (c < v) {
				exchange(begin + index, begin + first++);
			}
			else if (v < c) {
				first = index;
				v = begin[index];
			}
			
		}
	}

	static void exchange(T* t1, T* t2) {
		T temp = move(*t1);
		*t1 = move(*t2);
		*t2 = move(temp);
	}

public:
	static void test_Five() {
		int arr[] = { 2, 1, 2, 2, 1 };
		sort_two_element(arr, arr + 5);
		
		for (auto var : arr) {
			cout << var << '\t';
		}
	}
};

template <typename T>
class Five_2 {
	/**
	* In this example, we'll try to implement the sorting algorithm, assuming we have three elements in the 
	* cotainer.
	* 
	* For this situation, we can again use Dijkstra's flag problem. The largest element will go to the end of list,
	* and the snake in the middle keeps middle value. The problem again is that we don't know which value is smallest,
	* middle and largest. Hence we do this. The snake will move on at the start, sorting with repect to two values until
	* it sees the third one. If the snake was the third element, rather than the second, we have to move it's elements to
	* the end of the list.
	* 
	* Is this better than the entropy-optimal sort? The good case for this is when less and middle element are seen first.
	* For the entropy-optimal, if middle element is seen first the sort is optimal. I imagine the two would cancel each
	* other out. In any case, I don't think it would have any advantage over the entropy-optimal case.
	* 
	* I didn't debug this, and overall it turned out to be very complicated. Perhaps, and insertion sort is a good choice
	* after all.
	* 
	*/
	void sort(T* begin, T* end) {
		int N = end - begin;

		T v = begin[0];
		T s = begin[0]; T m = s; T l = m;
		int i = 0;
		int lo = 0;
		int hi = 0;
		int j = N - 1;

		bool all_seen = false;
		bool snake_exchanged = false;
		while (i < N)
		{
			T c = begin[i];

			if (!all_seen) {
				if (c <= s) { l = m; m = s; s = c; }	// Could be improved by saying 
				else if (v <= l) { l = m; m = c; }
				else { l = m; }

				if (s < m && m < l) all_seen = true;
			}

			if (!all_seen) {
				if (c < v) {
					exchange(begin + i, begin + lo++);
				}
				else if (v < c) {
					lo = i;
					v = begin[i];
				}
			}
			else {
				if (!snake_exchanged) {
					if (begin[lo] == l) {
						exchange_snake(begin, lo, hi, N); 
						j = N - 1 - (hi - lo + 1);
						hi = lo - 1;
						lo = 0;
						i = hi;	// We must restart looking after exchanging the snake!
					}
					snake_exchanged = true;
				}

				// Swap elements based on their value from now on
				if (begin[i] == s) exchange(begin + i++, begin + lo++);
				else if (begin[i] == l) exchange(begin + i, begin + j--);
				else { hi++; i++; }
			}

		}
	}

	void exchange_snake(T* begin, int lo, int hi, int j) {
		for (int k = hi; k >= lo; k--) {
			exchange(begin[j--], begin[k]);
		}
	}

	static void exchange(T* t1, T* t2) {
		T temp = move(*t1);
		*t1 = move(*t2);
		*t2 = move(temp);
	}
};

class Six {
	/**
	* Well this is easy. What's more interesting is this: Imagine I'm given a number of empirical data points.
	* Say for example for n = 1, 2, 100, etc, I have the running time of an algorithm. How do I determine
	* whether the given algorithm is linear, quadratic, linearithmetic?
	* The problem is that f(x) = cg(x) + d normally, for a given g(x) = x, x^2, ... . So a solution would be to
	* estimate c and d based on two points, and then see which metric g is closest in terms of error.
	*/
};

class Seven {
	/**
	*/
};

class Eight {
	/**
	* Assuming that the comparisons are (a[i++] <= v) and (v <= a[i++]), it will do N-1 comparisons the first step.
	* Then moves straight away to element two, doing N-2 comparisons. Overall, it does N^2/2 it appears.
	* The problem is that the array is not partitioned in half.
	* 
	* Even if we remove the equal sign, the sort will start from top of the array, hence, we still get
	* same number of comparison.
	*/
};

class Nine {

};

class Ten {
	/**
	* As indicated, P(|x-mu| > k*sigma) <= 1/k^2. Let's cover some basics here. We know that no sorting algorithm
	* can do better than NlogN comparisons. When is the best case for quicksort? When C_N = 2C_N/2 + N. In other
	* words, the pivot falls in the center. When the pivot falls in the center, the side arrays each need N/2 comparison.
	* However, in the best case, if every time the pivot falls in the middle for each level, we'd have exactly logn
	* depth. Hence, the total cost would be NlogN. Compare this to the worst case, where the pivot falls in the first or
	* last, in which case we'd need N^2 comparison. 
	* 
	* The point here is that this distribution is not uniform. In fact, the average is 2NlogN, and standard deviation
	* is 0.65N. Anyway, we can see that the probability is <= 1 / 23,655,670,416, which is very small that we in fact
	* go beyond NlogN comparisons. This is why we don't need to actually check for being sorted at the start of the
	* algorithm.
	*/
};

class Eleven {
	/**
	* As pointed out, with an array of equal keys, we'd do NlogN comparisons. If we didn't stop at equal keys,
	* we'd need n^2.
	* 
	* Now, note that at some point, all equal keys will be arranged. Hence, for k<N, we'd have [[1],[2],...,[k]]
	* each subarray indicating array of equal keys. From this point on, we'd require quadratic comparisons, which
	* will be deficient compared with the optimal NlogN for each subarray.
	* 
	*/
};

class Twelve {
	/**
	*  B A B A B A B A C A D A B R A
	* 
	* We chose B as the pivot. Then we have:
	* B A A A A A A A B B B B R D C -> Then putting the pivot in place yields: A A A A A A A B B B B B R D C
	* lo = 6 hi = 12
	* 
	* And we move forward.
	* 
	*/
};

class Thirteen {
	/**
	* In the best case scenario, everytime we divide the array in half. Hence, the total number of class equals
	* the number of nodes in a tree of the same size, which would be N/2 (leaf calls), N/4 + ..., and the sum
	* equals N. This is the total number of calls. However, a call stack does not have a length greater than logN.
	* 
	* In the worst case, like [1, 2, 3], we call the pivot on each element twice (once forward and once backward),
	* making the the total number 2N. A stack has a depth of N in this case.
	* 
	* For average, I don't know. We can reason that it must be close to logN, otherwise the algorithm would
	* normally take quadratic time. Especially, if we randomize, that probability increases.
	*/
};

class Fourteen {
	/**
	* Suppose i < j. If i< k <j is before i, then i and j are separated by k. Therefore i is NOT compared with
	* j. 
	* 
	* What is the probability that one of i+1 to j-1 elements is before i? 
	*/
};

template<typename T, typename COMP = greater<T>>
class Fifteen_1 {
	/**
	* This problem is equivalent to this: Imagine we have two vectors, such as a=[3 1 2 4 5] and b=[2 1 4 3 5]. Now,
	* we want both vectors to have the same order as one another. It's assume that there are no repeated keys in
	* both vectors.
	* 
	* Consider the quick-sort algorithm, and imagine the pivot element. Imagine instead of choosing the first element
	* as pivot, we just rearrange the vector with respect to pivot (like [2 1 ...] is compared with 2. Now, consider
	* the pivot element as the ith largest element of vector (call it a_i), and consider the ith position after 
	* arrangement. If a[i] > a_i, then we have at most i-1 elements less than a_i, which is a contradiction. Similarly, we
	* can also argue that a[i] < a_i is impossible. Consequently, after arrangement, a[i] = a_i.
	* 
	* So now the algorithm becomes clear, we start by arranging b, choosing a[0] as pivot. When finished, we use the 
	* same pivot element to rearrange a, and we continue until both vectors are arranged.
	*/
	using _Tp = typename T*;

public:
	static void sort(_Tp v1, _Tp v2, int N) {
		COMP comp{};
		sort_interchangeably(v1, v2, 0, N, comp);
	}

private:
	static void sort_interchangeably(_Tp v1, _Tp v2, int i, int j, COMP& comp) {
		if (i >= j) return;

		int loc_p = pivot(v2, i, j, v1[i], comp);
		pivot(v1, i, j, v2[loc_p], comp);

		sort_interchangeably(v1, v2, i, loc_p, comp);
		sort_interchangeably(v1, v2, loc_p + 1, j, comp);
	}


	static int pivot(_Tp v, int lo, int hi, T p_e, COMP& comp) {		// The pivot element is copied!
		int j = hi; int i = lo-1;
		while (true) {
			while (comp(v[--j], p_e)) { if (j <= lo) break; };
			while (comp(p_e, v[++i])) { if (i >= hi) break; };

			if (i >= j) break;

			swap(v[i], v[j]);
		}

		return j;
	}

	static void test() {
		array<int, 5> knots{ 5, 4, 3, 2, 1 };
		array<int, 5> bolts{ 2, 3, 1, 4, 5 };

		Fifteen_1<int>::sort(&knots[0], &bolts[0], knots.size());

		for (int i = 0; i < knots.size(); i++)
		{
			cout << "(" << knots[i] << "," << bolts[i] << ")\n";
		}
	}
};

struct Sixteen {
	/**
	* First, note that at each level of divide and conquer tree, if the nodes of level k have N and M elements,
	* (M = N or M = N-1), then, the node that is the combination of these nodes at level k-1 has N+M+1. The +1
	* comes from the fact that one element has been reduced in the previous stage! This is important.
	* 
	* Now, consider two arrays of size N, which are optimal for the quicksort algorithm. Let a=[a1, ..., aN] 
	* b=[b1,...,bN] be those two vectors, and let c be pivot element that caused this partition (i.e, the mid value
	* of a and b). We prove that the combination [c a2 ... aN a1 b1 ... bN] is an optimal vector.
	* To prove this, note that for any N, j=i=N in the quicksort partioning algorithm, because bi>c and ai<c.
	* Therefore, pivoting results in [a1 a2 ... aN c b1 ... bN]. Concequently, the vector is broken optimally.
	* 
	* In conclusion, if we want to create an optimal vector for the quicksort proposed here, we can do as follows.
	* Start from the bottom of the divide and conquer tree, going up each level, exchange the first element of the
	* arrays about to be combined with that of the top level mid conquer element. For this to happen, we need to
	* start with an array that is already sorted.
	* 
	* Note that the vector we arrive at is unique with this approach. However, to arrive at different vectors that
	* are optimal, we can randomly exchange elements that are not the pivot elements.
	* 
	*/
	static vector<int> find_optimal(const int N) {
		vector<int> opt(N);
		
		for (int i = 0; i < N; i++)
		{
			opt[i] = i + 1;
		}
		
		divide(&opt[0], 0, N - 1);

		return opt;	// Move!
	}

	static void divide(int* const begin, const int lo, const int hi){
		if (lo >= hi) return;
		int mid = lo + (hi - lo) / 2;

		divide(begin, lo, mid - 1);
		divide(begin, mid + 1, hi);
		swap(begin[lo], begin[mid]);
	}

	static void test() {
		auto vec = find_optimal(10);

		for_each(vec.begin(), vec.end(), [](int p) { cout << p << ",\t"; });	// Because you love for each 
																				// so very much!
	}
};

template <typename T, typename COMP = less<T>>
class Seventeen {
	/**
	* Translation: The check if(j==lo) is redundant, because at j=lo, the second loop is broken and we
	* don't check for j-1.
	* 
	* Now consider this. For the test i == hi, note that the element hi + 1 is always greater than our
	* pivot. So, even if we go to that element, the algorithm works fine. There's however one exception 
	* to this rule. For the very first iteration of the algorithm, the last element is not the greatest,
	* and hence, we may fall over. So how can we remedy this, we need to find the greatest element of the
	* vector, and put it at the top. Therefore, we can remove this condition too.
	* 
	*/
	using _Tp = T*;

	static void put_greatest_element_on_top(_Tp p, int N, const COMP& cp) {
		/*T max = p[0]; int index = 0;	// Usual verbose way.
		for (int i = 1; i < N; i++) {
			if (!cp(a[i], max)) { max = a[i]; index = i; }
		}*/
		
		_Tp p_max = max_element(p, p + N);	// Returns pointer to max. Use that to get index with ptrdiff_t
		ptrdiff_t index = p_max - p;
		swap(p[N - 1], p[index]);
	}

	static int partition(_Tp p, int lo, int hi, const COMP& cp) {
		int i = lo; int j = hi+1;
		while (true) {
			while (cp(p[++i], p[lo]));
			while (cp(p[lo], p[--j]));

			if (i >= j) break;

			swap(p[i], p[j]);
		}

		swap(p[lo], p[j]);

		return j;
	}

	static void divide_and_conquer(_Tp p, int lo, int hi, const COMP& cp) {
		if (lo >= hi) return;
		int pivot = partition(p, lo, hi, cp);

		divide_and_conquer(p, lo, pivot - 1, cp);
		divide_and_conquer(p, pivot + 1, hi, cp);
	}

public:
	static void sort(_Tp begin, _Tp end, const COMP& cp) {
		ptrdiff_t N = end - begin;

		put_greatest_element_on_top(begin, N, cp);
		divide_and_conquer(begin, 0, N-1, cp);
	}

	static void test() {
		array<int, 10> arr = { 1, 4, 2, 3, 7, 8, 9, 5, 10, 6 };
		
		sort(&arr[0], &arr[0] + 10, less<int>{});
		for_each(arr.begin(), arr.end(), [](int p) { cout << p << ",\t"; });

	}

};

template<typename T, typename COMP = less<T>>
class Eighteen {
	/**
	* We can calculate the median three elements in two ways, either sort the array directly, or find
	* the median using three condition checks.
	* 
	* The good thing about actually sorting the three elements is that now we have a sentinel. Why?
	* Note that the last element is always less than the first element, hence, there'll never be an
	* overflow from the right side. We also know that the left side check is unnecessary, because the pivot
	* is always less than equal itself.
	*/
	using _Tp = T*;

	static void compute_three_way_median(_Tp p, int low, int mid, int hi, const COMP& cp) {
		if (cp(p[mid], p[low])) swap(p[mid], p[low]);
		if (cp(p[hi], p[mid])) swap(p[mid], p[hi]);
		if (cp(p[mid], p[low])) swap(p[mid], p[hi]);
		
	}

	static int partition(_Tp p, int lo, int hi, const COMP& cp) {
		int mid = (lo + hi) / 2;
		compute_three_way_median(p, lo, mid, hi, cp);

		int i = lo; int j = hi + 1;
		while (true) {
			while (cp(p[++i], p[lo]));
			while (cp(p[lo], p[--j]));

			if (i >= j) break;

			swap(p[i], p[j]);
		}

		swap(p[lo], p[j]);

		return j;
	}

	static void divide_and_conquer(_Tp p, int lo, int hi, const COMP& cp) {
		if (lo >= hi) return;
		int pivot = partition(p, lo, hi, cp);

		divide_and_conquer(p, lo, pivot - 1, cp);
		divide_and_conquer(p, pivot + 1, hi, cp);
	}

public:
	static void sort(_Tp begin, _Tp end, const COMP& cp) {
		ptrdiff_t N = end - begin;

		divide_and_conquer(begin, 0, N - 1, cp);
	}

	static void test() {
		array<int, 10> arr = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };  //{ 10, 4, 2, 3, 7, 8, 9, 5, 1, 6 };

		sort(&arr[0], &arr[0] + 10, less<int>{});
		for_each(arr.begin(), arr.end(), [](int p) { cout << p << ",\t"; });

	}
};

template<typename T, typename COMP = less<T>>
class Nineteen {
	/**
	* Actually, we can find both the maximum and the max element, so that we can have a sentinel as well.
	* We show that this requires only eight compares max. Yes. This is two greater what Robert asks for,
	* but it gives us a sentinel. We can using the same reasoning to find only the median, but then we wouldn't
	* have a sentinel,
	* 
	* Before we get into to solve this problem, we should decide on a swap strategy. 
	* 1-	Say we can directly work with the vector and the cost of swapping elements is low. We do in place
	*	swaps.
	* 2-	The cost of moving the elements is high. In that case, we'll have an index vector, pointing to the
	*	elements of that vector. When we swap, we swap the indexes. In this case, we're just swapping
	*	integers. However, this would come at the cost of creating an destroying a vector.
	* 
	* To easily comprehend the solution, I suggest you draw a tree of how the elements are formed.
	* Assume element values are a,b,c,d,e. Compare (a,c), (b,c), (d,e), and without loss of generality, 
	* assume we have a,b,c,d,e. Then:
	* 
	* - if b < d --> order is a,b,c,d,e
	*	--	if c < d --> max = e and med = c.
	*	--	else --> order is a,b,d,c,e
	*		--	if a < d --> order is a,b,d,c,e
	*			--	if c < e --> max = e, med = d
	*			--  else --> max = c, med = d
	*		--	else --> order is b,d,a,c,e
	*			--	if c < e --> max = e, med = a
	*			--  else --> b,d,a,e,c
	*				--	if a < e --> max = c, med = a
	*				--	else --> max = c, med = e
	* - else --> order is a, d, b, c, e
	*	--	if b < e --> order is a,d,b,c,e
	*		-- if c < e --> max = e
	*		-- else --> max = c
	*		-- if a < b --> med = b
	*		-- else --> med = a
	*	--	else --> order is a,d,e,b,c
	*		--	if a < e --> max = c, med = e
	*		--	else --> d,e,a,b,c
	*			--	if a < b --> max = c, med = a
	*			--	else --> max = c, med = b
	*/
	using _Tp = T*;
	static void compute_five_way_median(_Tp p, int lo, int mid, int hi, const COMP& cp) noexcept {
		int mLo = (lo + mid) / 2;
		int mHi = (hi + mid) / 2;

		array<int, 5> i{ lo, mLo, mid, mHi, hi};
		int max = 0; int med = 0;

		if (cp(p[i[2]], p[i[0]])) swap(i[0], i[2]);
		if (cp(p[i[2]], p[i[1]])) swap(i[1], i[2]);
		if (cp(p[i[4]], p[i[3]])) swap(i[3], i[4]);

		if (cp(p[i[1]], p[i[3]])) {
			if (cp(p[i[2]], p[i[3]])) {
				max = i[4];
				med = i[2];
			}
			else {
				swap(i[2], i[3]);
				if (cp(p[i[0]], p[i[2]])) {
					med = i[2];

					if (cp(p[i[3]], p[i[4]])) {
						max = i[4];
					}
					else {
						max = i[3];
					}
				}
				else {
					swap(i[0], i[1]);
					swap(i[1], i[2]);
					if (cp(p[i[3]], p[i[4]])) {
						max = i[4];
						med = i[2];
					}
					else {
						swap(i[3], i[4]);
						if (cp(p[i[2]], p[i[3]])) {
							med = i[2];
							max = i[4];
						}
						else {
							med = i[3];
							max = i[4];
						}
						
					}
				}
			}
		}
		else{
			swap(i[2], i[3]);
			swap(i[1], i[2]);
			if (cp(p[i[2]], p[i[4]])) {
				if (cp(p[i[3]], p[i[4]])) {
					max = i[4];
				}
				else {
					max = i[3];
				}

				if (cp(p[i[0]], p[i[2]])) {
					med = i[2];
				}
				else {
					med = i[0];
				}
			}
			else {
				swap(i[3], i[4]);
				swap(i[2], i[3]);
				if (cp(p[i[0]], p[i[2]])) {
					max = i[4];
					med = i[2];
				}
				else {
					swap(i[0], i[1]);
					swap(i[1], i[2]);
					if (cp(p[i[2]], p[i[3]])) {
						max = i[4];
						med = i[2];
					}
					else {
						max = i[4];
						med = i[3];
					}

				}

			}
		}

		if (max == lo && med == hi) {
			swap(p[med], p[max]);
		}
		else if (max == lo) {
			swap(p[med], p[max]);
			swap(p[med], p[hi]);
		}else {
			swap(p[med], p[lo]);
			swap(p[max], p[hi]);

		}
	}

	static int partition(_Tp p, int lo, int hi, const COMP& cp) {
		int med = (lo + hi) / 2;
		compute_five_way_median(p, lo, med, hi, cp);

		const T& pivot = p[lo];
		int i = lo; int j = hi + 1;
		while (true)
		{
			while (cp(p[++i], pivot));
			while (cp(pivot, p[--j]));

			if (i >= j) break;

			swap(p[i], p[j]);
		}

		swap(p[lo], p[j]);
		
		return j;
	}

	static void divide_and_conquer(_Tp p, int lo, int hi, const COMP& cp) {
		if (lo >= hi) return;

		int pivot = partition(p, lo, hi, cp);
		divide_and_conquer(p, lo, pivot - 1, cp);
		divide_and_conquer(p, pivot + 1, hi, cp);
	}

public:
	static void sort(_Tp begin, _Tp end, const COMP& cp) {
		ptrdiff_t N = end - begin;
		divide_and_conquer(begin, 0, N - 1, cp);
	}

	static void test(int N) {
		vector<int> test_arr(N);

		int fact = 1;
		int i = 0;
		for_each(test_arr.begin(), test_arr.end(), [&](int& x) { x = ++i; fact *= i; });
		
		bool failed = false;
		for (int j = 0; j < fact && !failed; j++)
		{
			next_permutation(test_arr.begin(), test_arr.end());
			vector<int> sort_arr{ test_arr };

			sort(&sort_arr[0], &sort_arr[0] + N, {});
			for (int k = 0; k < N && !failed; k++)
			{
				failed = !(sort_arr[k] == k + 1);
			}
		}

		if (!failed) cout << "test_succeeded\n";

	}
};

class Twnety {
	/**
	* Already answered in 3_1.
	*/
};

class TwentyOne {

};

template<typename T, typename COMP = less<T>>
class TwentyTwo {
	/**
	* The Dijkstra's national flag implementation seem to be better than this approach, because it works
	* with only one loop.
	* 
	* So let's go over this implementation in a little more detail. Imagine we start with searching
	* from left, from right. Then we check if i and j are equal to pivot and if so, we place them at the
	* top and bottom. Then, we check the indexes and if i passes j, we break the loop. Notice that this
	* approach has a giant problem, namely, if we have 2 2 1 2 3, then j = 3, and we replace 3 with 4,
	* but now if we swap i and j, we have move a large element to the bottom, which is wrong.
	* 
	* A solution that comes to mind then is to first swap the elements, and then check for equality to pivot.
	* 
	* Now finally, consider the vector 2 1 2 3. In this case, i = j = 2. However, because the swap
	* happens after we check for i >= j, this element is never swapped. So, we need to add an aditional
	* constraint ensuring that we bring a smaller element above.
	* 
	* Now, note that after we're done, j would be the place where all elements are less than the pivot.
	* So, we put the bottom of the list starting with the pivot element to j and back, and then the top
	* of the list from j+1 forward. However, when we return the value of j, it will be the value before
	* the pivots, and i would be the value after. Hence, it may happen that j is outside the boundary,
	* for example for 1, 1, 2, we see that j = -1. But this is not a problem, since lo >= 0, and we catch
	* the partition function returns. Same goes for if i > n.
	* 
	*/
	using _Tp = T*;
	static std::pair<int, int> fast_three_way_partition(_Tp begin, int lo, int hi, const COMP& cp) {
		int i = lo; int j = hi + 1; int p = lo; int q = hi + 1;

		const T& pivot = begin[lo];
		while (true)
		{
			while (cp(begin[++i], pivot)) { if (i == hi) break; }
			while (cp(pivot, begin[--j])) { if (j == lo) break; };

			if (i == j && begin[i] == pivot) { swap(begin[i], begin[++p]); }
			if (i >= j) break;
			swap(begin[i], begin[j]);

			if (begin[i] == pivot) { swap(begin[i], begin[++p]); }
			if (begin[j] == pivot) { swap(begin[j], begin[--q]); }	
		}
		i = j + 1;
		for (int k = lo; k <= p; k++) {
			swap(begin[k], begin[j--]);
		}

		for (int k = hi; k >= q; k--) {
			swap(begin[k], begin[i++]);
		}


		return std::pair<int, int>{j, i};
	}

	static void divide_and_conquer(_Tp p, int lo, int hi, const COMP& cp) {
		if (lo >= hi) return;

		std::pair<int, int> pivots = fast_three_way_partition(p, lo, hi, cp);
		divide_and_conquer(p, lo, pivots.first, cp);
		divide_and_conquer(p, pivots.second, hi, cp);
	}

public:
	static void sort(_Tp begin, _Tp end, const COMP& cp) {
		ptrdiff_t N = end - begin;
		divide_and_conquer(begin, 0, N - 1, cp);
	}

	static void test() {
		vector<int> test_arr{1,1,1,2,2,2,3,3,3};

		auto calc_fact = [](int N)->int {
			int fact = 1;  for (int i = 2; i <= N; i++) fact *= i; return fact; };

		bool failed = false;
		for (int j = 0, fact = calc_fact(test_arr.size()); j < fact && !failed; j++)
		{
			next_permutation(test_arr.begin(), test_arr.end());
			vector<int> sort_arr{ test_arr };

			sort(&sort_arr[0], &sort_arr[0] + test_arr.size(), {});
			for (int k = 0; k < test_arr.size() && !failed; k++)
			{
				failed = !(sort_arr[k] == (k/3 + 1));
			}
		}

		if (!failed) cout << "test_succeeded\n";

	}

};


//int main() {
//	Nineteen<int>::test(10);
//}