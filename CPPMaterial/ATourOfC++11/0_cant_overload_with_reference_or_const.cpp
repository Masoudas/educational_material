/*
* We should not forget that we can't overload with const. Note that if the const is followed by reference, pointer
* and other things, we can overload.
* 
* We can overload with references. The problem however is that there might be ambiguity when trying
* to resolve overload (should we make a copy or should we pass by reference). If that can be resolved,
* then we can overload. However, as a general rule of thumb, we should not overload like this.
*/
void cant_overload_with_const_of_ref(int x) {

}

//void cant_overload_with_const_of_ref(const int x) {
//
//}

void cant_overload_with_const_of_ref(int& x) {

}

// void cant_overload_with_const_of_ref(const int& x) {} This would be fine.


void calling_overloaded_functions() {
	int x = 5;
	
	cant_overload_with_const_of_ref(5);	// rvalue reference, calls int function
	//cant_overload_with_const_of_ref(x);	ambiguous call.
}
