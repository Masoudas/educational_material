/** This is me:
* We mustn't confuse typ aliasing with declaration. The major difference among the two is that aliasing has an
* '='. The point of confusion may perhaps come when trying to include enum class (as of CPP20).
*/

namespace ns_1 {
	enum class my_e { e1 = 1 };
}


template<typename T>
void using_my_e() {
	using type = typename T::Type;	// Aliasing.

	using ns_1::my_e;	// using declarative
	using enum ns_1::my_e;

	my_e e = e1;

}