/**
* Inspired by the example I saw in the beginning of section 28.4, a question that may arise is that how can I check for 
* built-in types?
* 
* The answer is you can't! Instead what you can do is to check whether the type is user defined, using the is_class_t
* type function!
* 
* The problem however as I suspected is that for pointers, references, etc, this function may return false. Then, is an
* array of custom types a built in type or not? Perhaps whatever decay returns is true, because a pointer to a custom
* type is afterall a built-in type. I also couldn't find any answers to this question for now.
*/
#include <type_traits>

struct S{};

void is_built_in() {
	bool is_s_built_in = !std::is_class_v<S>;
	bool is_const_char_ptr_built_in = std::is_class_v<const char*>;

	// bool is_s_reference_built_in = !std::is_class_v<S&>; Error, returns false!

}