/** This is me:
* 
* So imagine a function has a particular signature in the base class, and we introduce a new argument
* for it in the derived class. Of course, we know that this would NOT be an override of the base method.
* Question is, will the two methods be available in the interface of the derived class?
* No. The derived class method hides the base class method. Why is the question?
* 
* Note that overload resolution does not occur between two scopes. Hence, the derived class method will
* nor resolve with base class method. (I know that we tend to think that base class method is copied in
* derived class, but I should stop thinking about it like this. But I should rather think about the relation
* between scopes).
* 
*/
#include <iostream>
using namespace std;

struct printer {
	void print(int i) {
		cout << "base_printer" << endl;
	}
};

struct advanced_printer : printer{
	void print(float i) {
		cout << "advanced_printer" << endl;
	}

	// void print(int i){printer::print();} Need to explicitly call int method to be able to use it.
};

//int main() {
//	advanced_printer p{};
//	p.print(float{});
//	p.print(int{});
//
//}