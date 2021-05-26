/**
*	-	template< class RandomIt, class URBG >
*		void shuffle( RandomIt first, RandomIt last, URBG&& g );
* Returns a shuffling of our collection. It requires a random bit generator function as last argument. To 
* generate random numbers, choose a random device, then the mt19937 random number generator.
* 
* std::next_perm and pre_perm return permutations of our collection, covering all possible permutations of
* the collection. 

template< class RandomIt >
void random_shuffle( RandomIt first, RandomIt last )
{
    typename std::iterator_traits<RandomIt>::difference_type i, n;
    n = last - first;
    for (i = n-1; i > 0; --i) {
        using std::swap;
        swap(first[i], first[std::rand() % (i+1)]);
        // rand() % (i+1) isn't actually correct, because the generated number
        // is not uniformly distributed for most values of i. A correct implementation
        // will need to essentially reimplement C++11 std::uniform_int_distribution,
        // which is beyond the scope of this example.
    }
}
*/
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

void shuffle() {
	std::vector<int> v{ 1, 2, 3, 4, 5 };

	std::random_device rd{};	// Chooses a hardware to ready bytes from
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