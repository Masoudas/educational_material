/**
* It is on the other hand possible to reduce the dependency on templated types by wrapping the types or methods in
* non-templated types. Say for example we always use a vector of doubles. We can wrap this class in a non-templated
* d_vec as shown below. Or for example we wrap the accumulate method of numeric in a accumulate method for vectors
* of double. By doing so, the dependence on vector or accumulate has disappeard in a totaly separate translation
* unit, which is good news. 
* 
* However, such techniques are not necessarily needed to be used with standard library templates, because they're
* stable, and have not changed over the years. We should do such techniques only with non-stable templated types in
* thrid party libraries. (Me: Note that this is equivalent to the technique always discussed by Babak and the giants
* as well, which is to define our own interfaces for all actions, and provide implementations based on third party
* libraries.)
*/
#include <vector>
#include <numeric>

class d_vec : public std::vector<double>{};

double accumulate(const std::vector<double>& e) {
	return std::accumulate(e.cbegin(), e.cend(), 0.0);
}