/**
* We have two versions:
*	constexpr UnaryFunction for_each( InputIt first, InputIt last, UnaryFunction f );	(1)
*	void for_each( ExecutionPolicy&& policy, ForwardIt first, ForwardIt last, UnaryFunction2 f );	(2)
* 
* Applies the given function object f to the result of dereferencing every iterator in the range [first, last), 
* in order.
* 
* Applies the given function object f to the result of dereferencing every iterator in the range [first, last) 
* (not necessarily in order). The algorithm is executed according to policy. This overload does not 
* participate in overload resolution unless std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> 
* is true.
* 
* For both overloads, if the iterator type is mutable, f may modify the elements of the range through the 
* dereferenced iterator. If f returns a result, the result is ignored.
* 
* Unlike the rest of the parallel algorithms, for_each is not allowed to make copies of the elements in the 
* sequence even if they are trivially copyable.
* 
* Note that the signature of f is mostly f(const Type& a)
* 
* The return value if exists is f.
*/