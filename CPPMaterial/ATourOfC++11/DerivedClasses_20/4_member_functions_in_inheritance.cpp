/**
* As we already know, a derived class can use the public and protected members of the base class (and they 
* don't tell you in school, but we can indirectly use the private memebers as well).
* 
* As we already know, because a class is also a namespace, redefining a method in the derived class covers the  
* base class method. Note that to use the base class method, we need to use the scope operator. This is done  
* regardless of whether or not the method is static of course! 
* 
* For example, if we had written in the print function below
void print(){
	print();
}
* it would have been very unfortunate, and the result was a recursive call to print!
*/
#include <iostream>

struct base 
{
	void print() {
		std::cout << "Inside base class method";
	}
};

struct derived : base
{
	void print() {
		std::cout << "Calling the derived class print from base:\n";
		base::print();	// Note that print is not a static method!
	}
};

//int main() {
//	derived d{};
//	d.print();
//}