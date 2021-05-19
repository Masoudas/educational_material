/**
* std::shuffle: Returns a shuffling of our collection. It requires a random bit generator function as last
* argument. The process of generating random number always baffles me, and every one uses a different approach!
* 
* I bring your attention to how we generate the output stream in this example. We copy the value of vector
* into our output stream, but for that, we get an iterator over the stream, and we say what type of value
* we want to put inside of it (in this case integer,) together with a delimiter. Cool!
* 
* std::next_perm and pre_perm return permutations of our collection, covering all possible permutations of
* the collection. 
*/
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

void shuffle() {
	std::vector<int> v{ 1, 2, 3, 4, 5 };

	std::random_device rd{};	// I think this chooses a hardware to ready bytes from
	std::mt19937 g{ rd() };		// Generates random number as a functional interface from a given hardware.
	
	std::shuffle(v.begin(), v.end(), g);

	// Generating the output stream, by copying the given vector iterator to an iterator of type int
	// over cout.
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\t")); // This one was nice!
	std::cout << "\n";
}

//int main() {
//	shuffle();
//}