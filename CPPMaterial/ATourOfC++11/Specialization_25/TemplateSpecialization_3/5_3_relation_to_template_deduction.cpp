/** This from me:
* Imagine I specialize a template with init list, as shown below for int. Now, based on the deduction rules, the template
* is deduced as int, which is exactly the same as the specialization. Now, which version would take precedence?
* 
* The point is that even if template type deduction succeeds, because the specialization closely matches the given type,
* it will ALWAYS supercede template deduction. Therefore, this should cause no ambiguity.
* 
* Notice that the init_list specialization is with int, and not initializer_list<int> :D. C++ is quircky!
*
*/
#include <initializer_list>

template <typename T>
void specialized_with_init_list(std::initializer_list<T>) {	
}

//template <typename T>
//void specialized_with_init_list<int>(std::initializer_list<int>) {
//	specialized_with_init_list({ 1, 2, 3, 4 }); // Uses this specialization
//}
