/**
* Question: What happens when I reassign a reference? Meaning I have a reference, and I assign
* it to another one.
* 
* Answer: As expected, because reference is an alias to an object, reassign it to another reference
* keeps a reference to the original object. So changing it would change the original object.
* 
* What is implied here is that a reference can be passed on as many times as needed, however it cannot be
* reassigned to point to another object. 
*/
#include <iostream>
using namespace std;

void reassigning_reference(int& ref) {
	int& ref_1 = ref;

	ref_1++;

}

//int main() {
//	int y = 10;
//	reassigning_reference(y);
//	cout << y;
//}