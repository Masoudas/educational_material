/*
* This is not recommended, and should not be implemented in production code.
* But we can create a reference, that refers to nothing (a nullptr).
* 
* To do so, we need *nullptr to work, so that we can say int& val = *nullptr;  
* but it doesn't under normal conditions. Hence, we can do the following:
* (Note again however that we can't reassing to a ref, so this reference is pointless
* 
*/
#include <iostream>
using namespace std;

char* iden(char* p) { return p; }
char& null_ref{ *iden(nullptr) };

void more_direct_approach_to_what_Bjrane_suggestion() {
	int* p = nullptr;

	int& ref = *p;	
}

//int main() {
//	cout << (&null_ref == nullptr;
//}