/**
* As the big guy talks about this issue a lot, in C++, we can essentially initialize objects with either
* paranthesis or or braces. The major difference between the two is that braces do not allow narrowing
* conversions to take place. Moreover, when it comes to choose between initializer list and argument based
* initialization, braces give priority to initializer list, whereas parathensis give priority to argument
* constructors.
* 
* As we may recall, the big guy said at one point "I don't see any reason why I should use paranthsis over
* braces.' We follow him in that regard, and use braces, which will save us from many problems!
* 
* We can see these in action in the following example. Notice the case for an empty braces. This must still
* satisfy the notion of default construction. Hence, s3 is not said to be initializing with an empty initializer
* list, but rather default constructing. Of course, if there were no default constructors, it would have been
* considered initialization with empty initializer list.
*/
#include <initializer_list>
#include <iostream>

struct s {
	s(){ std::cout << "Inside default constructor \n"; }
	s(int, int) { std::cout << "Inside argument based constructor \n"; }
	s(std::initializer_list<int>) { std::cout << "Inside initializer list \n"; }
};

void examples_of_initialization() {
	std::cout << "Using initializer list\n";
	s s1{ 1, 2 };

	std::cout << "\nUsing argument initializer\n";
	s s2(1, 1);

	s s3{};
}

//int main() {
//	examples_of_initialization();
//}