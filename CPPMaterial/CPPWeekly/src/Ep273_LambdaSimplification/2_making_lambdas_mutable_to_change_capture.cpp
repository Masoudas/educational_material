/**
* Now, when we pass non-reference parameters to lambda, they become consts as we already know. To make the
* parameters mutable, well, we use the mutable keyword right after the arguments.
*/
#include <algorithm>
#include <iostream>
#include <iomanip>

void making_lambda_mutable() {
	int j = 1;
	auto l = [i = 0, j](){
		//i = std::exchange(i, j);	// Error! Exchanging const variables
		return i;
	};

	auto l1 = [i = 0, j]() mutable {
		i = std::exchange(i, i+j);
		return i;
	};

	for (int i = 0; i < 10; i++) {
		std::cout << std::setbase(16) << l();
	}

}