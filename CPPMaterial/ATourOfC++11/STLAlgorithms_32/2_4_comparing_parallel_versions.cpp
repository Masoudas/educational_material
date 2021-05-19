/**
* Note that as some examples over the Internet suggest, we must try and apply maximum optimization with parallel
* execution to see some effect. Moreover, threads are actually costly to create and handle, hence we shouldn't
* use parallelization with small data containers.
* 
* For example, we actually see that the parallel version takes longer!
* 
*/

#include <chrono>
#include <algorithm>
#include <vector>
#include <execution>
#include <iostream>

void comparing_two_counts() {
	std::vector v(10000000, 1);
	v[500] = 0;

	auto begin = std::chrono::steady_clock().now();
	std::count(v.cbegin(), v.cend(), 0);
	auto mid = std::chrono::steady_clock().now();
	std::count(std::execution::par, v.cbegin(), v.cend(), 0);
	auto end = std::chrono::steady_clock().now();

	std::chrono::milliseconds dur1 = std::chrono::duration_cast<std::chrono::milliseconds>(mid - begin);
	std::chrono::milliseconds dur2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - mid);
	
	std::cout << dur1.count() << " and " << dur2.count();
}
