/**
* As we already know, operations can be supplied as as templates too, and this is what we normally do in std 
* containers. For example, consider the following simplified version of map:
* template<typename Key, Class V>
* class map {
* // ...
* };
* 
* Note that we can't hardwire a comparison (using the <), nor can we apply a random ordering of keys, which will
* not be applicable to all keys. Consequently, a sorting criterion is not built into the container type or into
* the element type. In principle, the notion of sorting criteria for a map could be represented as:
*	[1] A template value argument (e.g., a pointer to a comparison function)
*	[2] A template type argument to the map template determining the type of a comparison
* object.
* 
* At first glance, the first solution seems more appropriate (Me: which I thought about for a long time. However,
* this is not the best solution, because we can't pass lambdas for example). The implementation is shown below (Me:
* also notice how the big guy passes the function pointer. cmp is now the type! Also note that in this case, we 
* needn't provide an instance, because this is a function pointer). There are two issues here however:
* 1- It can be hard to provide a default value (Me: but I just did it below!)
* 2- the designer of map will have to decide whether to compare the (unknown) Key type using a pointer to function
*	or a function object of some specific type.
* Consequently, the second alternative (pass the type of the comparison as a template type parameter) is the more 
* common and the one used in the standard library.
* Another advantage of the object function method (like std::less) is that if we decide to supply a compare method
* with state, it will be possible too.
* 
* (Note: As a reminder, the comparison function is provided in the constructor of normal maps, and it's a template
* parameter. If we want to provide a lambda, we have to use the typedecl of lambda as the template of the class.
* If we didn't want to use decltype, we recall that lambdas can be naturally converted to function pointers (recall
* that a lambda is actually a class, so it can be converted to function pointer by C++, but not converse!). So,
* we define the function pointer, then pass a lambda, as we've shown below.)
* 
* We can think of three benefits why passing a function object is a very good alternative:
* 1-	Passing a function object with no data has no run-time cost.
* 2-	Inlining can be easily achieved. With function objects the compiler has to pay extra attention (allegedly).
* 3-	Several operations can be passed simulatenously, compared with a function pointer.
*/

template<typename T>
bool compare(const T& t1, const T t2) {
	return t1 < t2;
}

template<typename Key, typename V, bool(*cmp)(const Key&, const Key&) = compare>
class map {
public:
	map();
	// ...
	// using cmp
	void f(const Key& k1, const Key& k2) {
		cmp(k1, k2);
	}
};

#include <functional>
template<typename Key, typename V, typename Comp = std::less<Key> >
class std_map {
public:
	std_map(Comp cp) {};
	// ...
};

void passing_lambda_as_function_object() {
	using Comp = bool(*)(const int&, const int&);

	auto lambda = [](const int&, const int&) { return false; };

	std_map<int, int, Comp> map{ lambda };

	// Alternatively, we can go a bit deeper in the rabit hole, and define
	int j = 10;
	auto lambda1 = [&j](const int&, const int&) mutable { j++;  return false; };
	std_map<int, int, decltype(lambda)> map1{ lambda };

}