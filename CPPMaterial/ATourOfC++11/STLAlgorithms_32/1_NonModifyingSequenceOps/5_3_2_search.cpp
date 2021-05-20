/**
* As opposed to find_first_of, which stops as soon as the first element of the set is found in the search set,
* the search method ensures that all elements are present in the other container (in that order). Hence, search
* for {1,2} inside {2,3,1,2,3} returns the iterator to 1, because {1,2} exists in this set.
* 
*	-	constexpr ForwardIt1 search( ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, 
*		ForwardIt2 s_last );
*	-	constexpr ForwardIt1 search( ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last, 
*		BinaryPredicate p );
*	-	constexpr ForwardIt search( ForwardIt first, ForwardIt last, const Searcher& searcher );
* Searches for the first occurrence of the sequence of elements [s_first, s_last) in the range [first, last)
* 
* The overload with searcher, lets us provide search methods, which are (in the functional namespace:)
*	(1)	default_searcher
*	(2)	boyer_moore_searcher
*	(3)	boyer_moore_horspool_searcher
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// Notice the use of cbegin and cend for a container which may or may not have a cbegin and cend function!
template<typename Container>
bool in_quote(const Container& cont, const std::string& s) {
	return std::search(cbegin(cont), cend(cont), s.cbegin(), s.cend()) != cend(cont);
}

void instances_of_search()
{
    std::string str = "why waste time learning, when ignorance is instantaneous?";
    // str.find() can be used as well
    std::cout << std::boolalpha << in_quote(str, "learning") << '\n'
                                << in_quote(str, "lemming")  << '\n';
 
    std::vector<char> vec(str.begin(), str.end());
    std::cout << std::boolalpha << in_quote(vec, "learning") << '\n'
                                << in_quote(vec, "lemming")  << '\n';
 
    // The C++17 overload demo:
    std::string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
                     " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
    std::string needle = "pisci";
    auto it = std::search(in.begin(), in.end(),
                   std::boyer_moore_searcher(
                      needle.begin(), needle.end()));
    if(it != in.end())
        std::cout << "The string " << needle << " found at offset "
                  << it - in.begin() << '\n';
    else
        std::cout << "The string " << needle << " not found\n";
}

//int main() {
//    instances_of_search();
//}
