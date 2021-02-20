/** 
* When it comes to swapping with pointers, we need to do it using move notion to ensure
* that no unnecessary copying (into temp) takes place. The following is an implementation
* 
* stl has a swap function that swaps many things, but not two pointer content.
*/
using namespace std;

template <typename T>
void swap_normal(T* t1, T* t2) {
	T temp = move(t1);
	*t1 = move(*t2);
	*t2 = move(temp);
}
