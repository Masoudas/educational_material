/**
* volatile and const are collectively known as cv-modifiers. Where ever we use const, we can use
* volatile and vice versa.
* 
* type conversion for volatile and const is the same.
* 
* Note however that const and constexpr are not the same. There are places where we can use const
* in place of constexpr, but vice versa, but not always.
* 
* If we have "CV_1 T" and "CV_2 T", where:
*	1- CV_1 is either empty, const, volatile or const volatile
*	2- CV_2 is more qualified than CV_1
*		If it has all of CV_1, plus at least one more.
* Assignment to a more qualified type is therefore possible. The other direction is not possible however.
* 
* We should note here that as we discuss in 7, constexpr is not a cv_qualifier, because T constexpr* does not
* read pointer to constant T!!!
*/

void using_cv_modifiers() {
	const int* volatile t;	// t is a volatile pointer to integer constant :D!
	const int* t1;		// t1 is a pointer to integer constant.
	const int const* p;	// p is a pointer to constant integer (one const is reduntant!
	volatile int* volatile p2;	// p is a volatile pointer to volatile integer.
	//int const* const p3 = ;	// p is a constant pointer to constant integer.
}

void more_qualified_cv() {
	volatile int k = 10;
	const volatile int w = k;	// This is more qualified than k.
	
	int l = 10;
	int* i = &l;
	const int* j = i;	// This is more qualified than i
}