/**
* C++ does not have a way of expressing axioms, but we can put certain checks to ensure that they're held, as in
* constraints.
* 
*/

#include <type_traits>

template <typename T>
constexpr bool Copy_equal(const T& t) {
	return T{ t } == t;
}

template<typename T>
constexpr bool Copy_assign_equality(T x, T& y) // semantics of assignment
{
	return (y = x, y == x); // the result of an assignment compares equal to the source of the assignment
}

template<typename T>
constexpr bool Move_effect(T x, T& y) // semantics of move
{
	return (x == y ? T{ std::move(x) } == y : true) && std::is_destructible_v<T>;
}

template<typename T>
constexpr bool Move_assign_effect(T x, T& y, T& z) // semantics of move assignment
{
	return (y == z ? (x = std::move(y), x == z) : true) && std::is_destructible_v<T>;
}