/**
* As the big guy demonstrates, one can use the iterator_traits function to write the search function as shown below.
* 
*/

#include <iterator>

using std::iterator_traits;

template<typename Iter>
void search(Iter begin, Iter end, const typename iterator_traits<Iter>::value_type& val) {	// Jesus!
	typename iterator_traits<Iter>::difference_type m = end - begin; 
	typename iterator_traits<Iter>::difference_type N = std::distance(begin, end);	// Better yet!

}