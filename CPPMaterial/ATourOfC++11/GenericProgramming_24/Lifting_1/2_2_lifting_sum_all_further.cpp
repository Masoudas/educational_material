/**
* The previous code on sum all can be further generalized. In particular, we have to specify the type of the sum
* variable and a rigid zero initial value. We can remedy this by accepting the initial value as an argument in the
* function.
* 
* Moreover, why restrict ourselves to just plus operation, when we can supply other operations as well. We can do
* so by accepting an operation argument as well. (Note that the operations plus and multiply supplied by to the
* method are not instantiated, and are wrong.)
* 
* The big guy says "Lifting is a skill that requires knowledge of an application domain and some experience. The
* most important single guide for designing algorithms is to lift them from concrete examples without adding 
* features (notation or run-time cost) that would impair their use. The standard-library algorithms are the results 
* of lifting done with great attention to performance issues."
*/
#include <algorithm>

template<typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val s)
{
	while (first != last) {
		s = s + *first;
		++first;
	}
	return s;
}

template<typename Iter, typename Val, typename Op>
Val accumulate(Iter first, Iter last, Val s, Op op)
{
	while (first != last) {
		s = op(s, *first);
		++first;
	}
	return s;
}
