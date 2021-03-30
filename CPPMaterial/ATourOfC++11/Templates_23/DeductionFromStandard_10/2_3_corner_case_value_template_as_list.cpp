/**
* There's a corner case, that's probably going to be extinct, but I bring it from the standard as a reminder:
* 
* " If removing references and cv-qualifiers from P gives P'[N], and A is a non-empty braced-init-list, then 
* deduction is performed as above (me: like init list), except if N is a non-type template parameter, it is 
* deduced from the length of the initializer list:"
*/

template<class T, int N> void array_of_constant(T const(&)[N]) {};
void using_arr_of_const() {
	array_of_constant({ 1, 2, 3 }); // deduced T = int, deduced N = 3
}

template<class T> void arr_of_three(T const(&)[3]) {};
void using_arr_of_three() {
	arr_of_three({ 42 }); // deduced T = int, array bound is not a parameter, not considered.

}

struct Aggr { int i; int j; };

template<int N> void arr_of_custom(Aggr const(&)[N]) {};
void using_arr_of_custom() {
	//arr_of_custom({ 1, 2, 3 });       // error: deduction fails, no conversion from int to Aggr
	arr_of_custom({ {1}, {2}, {3} }); // OK: deduced N = 3

}

template<int M, int N> void double_arr(int const(&)[M][N]) {};
void using_double_arr() {
	double_arr({ {1, 2}, {3, 4} }); // deduced M = 2, deduced N = 2

}

template<class T, int N> void arr_and_type(T const(&)[N], T) {};
void using_arr_and_type() {
	arr_and_type({ {1}, {2}, {3} }, Aggr()); // deduced T = Aggr, deduced N = 3
}
