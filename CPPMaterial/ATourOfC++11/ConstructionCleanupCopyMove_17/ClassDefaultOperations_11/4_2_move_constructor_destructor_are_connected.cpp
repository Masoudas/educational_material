/**
* Example 2: Maintaining invariants.
* 
* Often, we want the copy and move operations to maintain the status of class invariants, and the destructor
* to free the memory. Unfortunately, the compiler cannot in every case know what a programmer considers 
* an invariant.
* 
* Note that no constructors are defined. Hence, a user now sets the values using memberwise initialization.
* Note that when we copy or move the class, my_favoritve and largest are copied or moved as well. However, if the
* original object is deleted, largest would point to destructed memory. Moreover, if we move Z, then my_favorite
* would be out of range.
* 
* Point being, think about the move and copy operations when creating something as simple as POD. Bjarne says:
* 1- Establish an invariant in a constructor (including possibly resource acquisition).
* 2- Maintain the invariant with copy and move operations (with the usual names and types).
* 3- Do any needed cleanup in the destructor (incl. possibly resource release).
*/

#include <vector>
using namespace std;

struct Z { 
	// invariant:
	// my_favorite is the index of my favorite element of elem
	// largest points to the element with the highest value in elem
	vector<int> elem;
	int my_favorite;
	int* largest;
};

void using_struct_z() {
	Z val{ {1,2,3}, 1, &val.elem[2] };	// Holy mother of God!
	Z v2 = val;	// largest at least for now points to largest in val.
	Z v3 = move(val); // moves: val.elem becomes empty; v3.my_favor ite is out of range

}