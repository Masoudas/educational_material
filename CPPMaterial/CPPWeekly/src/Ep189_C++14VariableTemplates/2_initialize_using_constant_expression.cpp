/**
* Things get a bit more interesting when we note that we can wrap the result of a constexpr function
* in a variable template as follows:
*/
constexpr int get_value() {
	return 42;
}

template<typename T>
constexpr T value = T{ get_value() };