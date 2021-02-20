/**
* Apparently, a more standard solution (than the one I suggested in 7_1) is to make a conditional inheritance
* from a base that is either trivially destructible or not. Then, we can destruct the type in base
* accordingly!
* 
* For the trivial branch, the way we inherit and make the condition is trivial. For the non-trivial path
* however, we use the curiously recurring template pattern and delete the element that way.
* 
* It's interesting that we have to define the optional_c destructor explicitly! In the video of this
* episode, this was not done!
* 
*/

#include <type_traits>
#include <string>
#include <iostream>

// Keep the trivial destructor for this case.
struct trivially_destructible {

};

template <typename U>
struct non_trivially_destructible {
	~non_trivially_destructible() {
		using type = typename U::Type;
			static_cast<U*>(this)->t.~type();	// What if t were private?!!
	}
};

template<typename T>
struct optional_c : std::conditional_t<std::is_trivially_destructible_v<T>,
					trivially_destructible,
					non_trivially_destructible<optional_c<T>>>{
	union {
		char dummy;
		T t;
	};

	bool has_value = false;

public:
	using Type = T;
	optional_c() : dummy{ 1 }, has_value{ false } {}

	optional_c& operator=(T&& t) {
		t = std::move(t);
		has_value = true;
		return *this;
	}

	T get() {
		if (!has_value) throw "exception";

		return t;
	}

	~optional_c() {

	}

};

void using_conditional_optional() {
	optional_c<std::string> op{}; //I don't understand why this is not working!

	op = "My God, I've been shot!"; // Yeah. This still does not work!
}


//int main() {
//	using_conditional_optional();
//}