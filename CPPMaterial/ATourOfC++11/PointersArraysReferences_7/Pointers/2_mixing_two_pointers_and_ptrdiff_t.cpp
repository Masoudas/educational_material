/** This is me:
* As we already know, we can mix to pointers (particularly subtract them). This would lead to the difference
* among them in terms of the unit they point to. For example, with p = &a[i], q = &a[j], the difference
* q-p is equivalent to j-i ((&a[i] - &a[j])/sizeof(a[0]). 
* 
* We tend to look at this result as an int. However, this is more precisely of type ptrdiff_t type, which is
* a signed version of size_t. A cast to int is most probably harmless in most common platforms. However, 
* it's best to use the actual type directly
* 
* Subtracting pointers is only valid if the pointers point to the same array (or the one after last). Otherwise,
* the result is undefined behavior (formally. But perhaps, a jump from one location of memory to another.
* 
* Thankfully, more complicated an nonsensical expressions such as p1 + p2, or p1 - p2 - p3 are not allowed!
*/
#include <iostream>
#include <cstdint>

using namespace std;

void pointer_diff_type() {
	int arr[5] = { 1, 2, 3, 4, 5 };


	ptrdiff_t t = &arr[3] - &arr[1];

	int arr1[5] = { 1, 2, 3, 4, 5 };

	int t1 = arr - arr1;

	cout << t1 << '\t' << arr << '\t' << arr1 << '\n';

	int* p1 = arr;
	int* p2 = arr + 2;

}

//int main() {
//	pointer_diff_type();
//}