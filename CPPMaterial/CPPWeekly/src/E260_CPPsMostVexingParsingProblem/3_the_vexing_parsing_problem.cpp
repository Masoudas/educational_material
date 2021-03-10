/**
* Now, we go back to the vexing problem. This is actually what the big guy talked a lot about in his book. If
* we empty initialize a class with paranthesis, it's construed as function definition. Hence, we get a bizzare
* error saying that we're using function when we try and access the fields of that initialized object. 
* 
* The exact error we get is "left of '.member' must have class/struct/union", which again happens because we
* are using member operator with function!
* 
* Hence, in the worlds of the big guy "I see no reason to prefer parathesis over braces."
*/

struct d_ctor {
	int member;
};

void using_d_ctor() {
	d_ctor oops_function_header();	// This is a function header.

	// int x = oops_function_header.member; uncomment this line to see the effect.
}

//int main() {
//	using_d_ctor();
//}