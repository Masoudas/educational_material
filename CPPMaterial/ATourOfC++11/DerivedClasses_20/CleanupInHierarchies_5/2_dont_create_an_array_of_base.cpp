/**
* This is going to be certainly odd. But, the advice is to never create an array of base pointers to point to 
* derived types.
* 
* Why is this the case? Apparently, when indexing an array, the compiler uses the size of the static-type, rather
* than the dynamic type (for example, a_base in the following example). Consequently, even a simple indexing of
* an array is not corrent, and for example we see below that the m is not called at all.
* 
* This can get more severe when deleting an array and causes slicing, which is discussed next. In conclusion, 
* don't create an array of the base type. Note that smart pointers help us avoid this problem by throwing a 
* compile time error. Vectors also don't allow such an operation to take place.
* 
* An important note: Jeez man! Note that if we run the following code, we see that when constructing the array, a
* destructor is called when creating the array! Why do you think this is? Think deeply, before reading the answer
* :D!
* 
* The answer is, this happens because when we override the default destructor, the move constructor is deleted. So,
* we create the array as new T{T{}, T{}}, and the temporaries are copied rather than moved. So, be careful to 
* always redefine the move and copy assignment and constructors when this happens! Now I ask the compiler, how 
* come you define the copy constructor for me, but not the move! And the compiler probably answers copy is well
* defined, and it's just about replicating memory. Move, however, is a completely different story.
*/
#include <iostream>

struct a_base {
	virtual void m(int) {
		std::cout << "Inside base class method\n";
	}

	virtual ~a_base() {
		std::cout << "Inside base class destructor\n";
	}
};

struct a_derived : a_base
{
	int x = 10;
	void m(int) override {
		std::cout << "Inside derived class method\n";
	}

	~a_derived() override {
		std::cout << "Inside derived class destructor\n";
	}
};

void dont_create_an_array_of_base_to_point_derive() {
	a_base* d1 = new a_base{};
	a_base* d = new a_derived[2]{ a_derived{}, a_derived{} };
	
	d[1].m(2); // Undefined behavior! May even throw a memory violation error!
	int x = 5;
	//delete[] d;
}
