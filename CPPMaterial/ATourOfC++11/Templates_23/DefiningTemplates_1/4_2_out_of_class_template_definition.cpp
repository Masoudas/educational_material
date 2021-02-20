/** This is me:
* If we supply a default to a template, it must not be repeated outside the class. Also note that with
* single template with default, we still need to supply '<>' of the template upon instantiation, though
* we can omit it as of C++17.
*/
template<typename T = int>
struct MyStruct
{
	void f(T t);
};

//template<typename T = int> // Default cannot be respecified here.
template<typename T>
void MyStruct<T>::f(T t){}

void instantiation_with_single_defualt() {
	MyStruct<> m1{};	// Note that we put <>, even though no template is provided.
	//MyStruct m1{};    // Ok, as of C++17.
} 