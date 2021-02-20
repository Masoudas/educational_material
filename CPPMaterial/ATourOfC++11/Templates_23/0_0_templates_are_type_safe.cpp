/**
* As we know, an important feature we expect from templates is that a class with template of one kind
* must not be assigned to template of another type. Otherwise, we may wrongfully assign templates of one
* type to another (especially if one type is the base of another). This is guaranteed in C++ as well.
* 
* In conclusion, compile time checks are strongly enforced when using templates.
*/
template <typename T>
struct MyStruct
{

};

void cant_assign_templates_of_different_kind() {
	MyStruct<int> d1{};
	MyStruct<float> d2{};

	// d1 = d2; This is impossible
	
	// MyStruct<int> d3 = new MyStruct<float>{}; Again, the move constructor does not exist for such conversion.
}