/*
* So normally, we pass an array with pointer and it's fine. We can write and read.
* If we wanted to only read, we could say  const T* arr, which is a pointer to T constants.
* 
* But how about if we decided to send an array by reference? First of, what does it mean?
* It means that we want to access the elements of arr directly, not using the pointer. Hence, what
* we need is an array of references, or T& arr[]. However, an array of references is not allowed in CPP.
* 
* A personal note: Recently, I was wondering why we can't have for example a vector of references, such as
* std::vector<int&>. The answer is clear now. C++ does not allow an array of reference. The most important reason
* why they don't allow an array of references is because referces have no operators such as increment or decrement  
* defined form them.
*/

/*
* So to undersand how we pass a reference to an array, recall that for a normal int, saying int& x = y means that 
* it's equal to say x = 10 or y = 10. With that in mind, if we define a reference to an array, then if that ref
* is called arr_ref, then like we say arr[10], we'd be able to say arr_ref[10]. 
* 
* Now what is arr in the above example? It's a constant pointer to an array of 10 integer pointers. Now, the fact
* that we define a reference removes the constant pointer part (because a reference is a constant pointer inherently). 
* Therefore, we have 'to an array of integer pointers), which is equivalent to saying:
* 
* T (&arr_ref)[n] = arr;
* 
*/
#include <iostream>

using namespace std;

template <typename T>
void passing_array_by_reference(T (&ref)[5]) {
	for (int i = 0; i < 5; i++)
	{
		cout << *(ref + i) << endl;
		// Or equivalently
		cout << ref[i] << endl;

	}

	// This would now be an access by reference
	for (T& var : ref)
	{
		var = 10;
	}

	

	
}

//int main() {
//	int arr[] = { 1, 2, 3, 4, 5 };
//
//	passing_array_by_reference<int>(arr);
//
//	cout << "After passing this array by reference to the function and changing its content: " << endl;
//	for (auto var : arr)
//	{
//		cout << var << endl;
//	}
//}