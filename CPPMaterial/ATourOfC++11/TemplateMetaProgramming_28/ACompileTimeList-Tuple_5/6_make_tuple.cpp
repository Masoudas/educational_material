/**
* To allow for construction tuples without having to explicitly define the class templates, we create a 
* make_tuple function as follows:

template<typename T1, typename T2, typename T3, typename T4>
Tuple<T1, T2, T3, T4> make_tuple(const T1& t1, const T2& t2, const T3& t3, const T4& t4){
	return Tuple<T1, T2, T3, T4>{t1, t2, t3, t4};
}

* Other useful functions, such as head() and tail(), are easily implemented.
*/