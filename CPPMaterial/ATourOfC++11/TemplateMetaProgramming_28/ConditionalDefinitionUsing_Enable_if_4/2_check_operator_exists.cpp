/**
* Now, supposing we somehow got has_f up and running, then we can check for existence of any function on class
* X, including for example operators such as !=, ==, etc, as the following example shows, in conjunction with
* enable_if:

template<typename Iter, typename Val>
Enable_if<Has_not_equals<Iter>(),Iter> find(Iter first, Iter last, Val v)
{
	while (first!=last && !(*first==v))
		++first;
	return first;
}

template<typename Iter, typename Val>
Enable_if<!Has_not_equals<Iter>(),Iter> find(Iter first, Iter last, Val v)
{
	while (!(first==last) && !(*first==v))
		++first;
	return first;
}

* Such ad hoc overloading easily gets messy and unmanageable. For example, try adding versions that use != 
* for the value comparison (that is, *first!=v, rather than !(*first==v)), when possible. Consequently, the
* big guy recommends relying on the more structured standard overloading rules and specialization rules,
* when there is a choice. For example, see the definition of operator!= below. The rules ensure that if a 
* specific != has already been defined for a type T (as a template or as a nontemplate function), this 
* definition will not be instantiated. He uses decltype() partly to show how in general to derive the return 
* type from a previously defined operator, and partly to handle the rare cases where != returns something 
* different from bool. Similarly, we can conditionally define >, <=, >=, etc., given a <. 
* 
*/

template<typename T>
auto operator!=(const T& lhs, const T& rhs) -> decltype(!(lhs == rhs)){
	return !(lhs == rhs)
}