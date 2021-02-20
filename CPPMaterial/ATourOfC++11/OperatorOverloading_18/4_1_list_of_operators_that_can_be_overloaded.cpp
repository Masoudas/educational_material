/**
* Here's a list of all operators that we can overload in C++.
+ − ∗ / % ˆ &
| ˜ ! = < > +=
−= ∗= /= %= ˆ= &= |=
<< >> >>= <<= == != <=
>= && || ++ −− −>∗ ,
−> [] () new new[] delete delete[]
""  T() 

* A couple of points should be noted right away:
* 1-	Note that delete and delete[] must be overloaded separately. As we may recall, they require
*	a void pointer as argument. Their form is 'operator delete(void*)' or 'operator new[](int)'.
* 
* 2-	Consider the difference between '-=' and '-'. Each one of these need to be overloaded on its own
*	right. (Note that we still can't say 2 += s though, because and rvalue can't be on the left hand side
	of an expression);
* 
* 3- How do we distinguish between * the pointer operator and * the multiplication operator? Multiplication
*	accepts an argument. 
* 
* 4- Operator"" is also interesting, and is called the literal type operator. It will be discussed further 
*	later on.
* 
* 5- Operator T() is used for casting the object. It shall be discussed further later on. This is for when
*	we say (T)(obj). Note in the following example how we overloaded cast to bool, so that an implicit cast
*   to boolean takes place in the if statement.
* 
* 6- Note that '-' is both a unary and a binary operator. 
*/

struct overloads {
	int x{};
	overloads(int){}

	const overloads& operator+=(const overloads&) {
		return *this;
	}

	operator bool(){ return true;}
	void operator delete[](void* ptr){}
	void operator delete(void* ptr) {}
};

void using_bool_cast_operator() {
	overloads o{1};
	if (o) {}	// An implicit conversion to bool takes place here
}



