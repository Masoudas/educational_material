/**
* Quite often, we have to override the <, >, <=, >=, ==, !=, operators. Overriding these operators can
* be verbose and lead to errors. Moreover, we may forget to define them as constant functions, or declare
* the rhs as constant, or declare them consexpr when necessary, and many other things.
* 
* Notice in the following example how we override the !=, => and <= operator. We're using the already defined
* == and >= operators of the class. I know that <= and => are less efficient, but just wanted to give an idea of
* how they can be implemented. Also, forget the fact that actually these operators need to be declared as friend
* functions.
* 
*/

struct Wrapper {
	int val;
	constexpr Wrapper(int val): val{val}{}
	constexpr bool operator==(const Wrapper& rhs) const noexcept { return val == rhs.val; }
	constexpr bool operator!=(const Wrapper& rhs) const noexcept { return !(*this == rhs.val); }
	constexpr bool operator<(const Wrapper& rhs) const noexcept { return val < rhs.val; }
	constexpr bool operator<=(const Wrapper& rhs) const noexcept { return *this == rhs.val || *this < rhs.val; }
	constexpr bool operator>(const Wrapper& rhs) const noexcept { return !(*this <= rhs); }
	constexpr bool operator>=(const Wrapper& rhs) const noexcept { return !(*this < rhs); }
};