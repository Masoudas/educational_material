/**
* Reviewing what we know so far, the compiler can deduce the template type only for functions, and not
* for classes. We also know that for example, template type can't be deduced from just the return type,
* but only from the function arguments.
* 
* So what sort of arguments can deduce type? We know that for example for template type T, T, T*, T&, T&&
* const T, volatile T, T[constant_expression] can deduce types. 
* 
* Now, imagine TT is a templated type, and l is a non type template argument (like when we pass an int
* as template type). Then for example TT<l> in function argument means the type is TT, so will TT<T>. 
* We can also deduce from T[l].
* 
* We can also deduce types from class_template_name<T> and class_template_name<I>.
* 
* The most complicated version is when we use function pointers. So imagine T(*)(args), where args is a list
* of parameters that does not allow deduction. Because we know the return type however, we're fine.
* 
* I copy and paste the following situations where type can be deduced as well:
* T type::*, T T::*, type T::*, type (T::*)(args), T (type::*)(args), type (type::*)(args_TI),
* T (T::*)(args_TI), type (T::*)(args_TI), T (type::*)(args_TI), type (*)(args_TI).
* 
* 
* If a function template can be deduced from more than one argument, it should be the same, otherwise
* an error is raised.
template<typename T>
void f(T i, T* p);
void g(int i){
	f(i,&i); // OK
	f(i,"Remember!"); // error, ambiguous: T is int or T is const char?
}
*/
template<typename T>
struct temp{};

template<typename T>
void deduction_from_template(T t){
	deduction_from_template(temp<int>{});	// Ok. deducted as temp<int>
	deduction_from_template(temp<T>{});	// Again. Type is deduced as temp<T>.
}

