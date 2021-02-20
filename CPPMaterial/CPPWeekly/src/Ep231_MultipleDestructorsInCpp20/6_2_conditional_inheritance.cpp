/**
* We can of course get a little bit more adventurous when using templates
*/
#include <type_traits>

struct S {};
template<typename BASE>
struct derived_c : std::conditional_t<std::is_trivially_destructible_v<BASE>,
	BASE,
	S> {	// How do we say nothing here?!
};

struct copiable_trv{};

struct copiable_non_trv{
	copiable_non_trv(const copiable_non_trv&){}
};


void using_derived_c(){
	derived_c<copiable_trv> s{};
	//derived_c<copiable_non_trv> s{}; //Error! non-trivially copiable.

}