/**
* When consturction takes place, invariants are set. 
* 
* The important point here is that if construction is impossible, the class throws an exception, 
* and we the writers of the class must ensure that the resource it has acquired is freed.
* Of course the class releases the resources where it can.
* 
* If new fails, like the example below, a bad_all exception is thrown and the exception-handling 
* mechanism invokes the appropriate destructors so that all memory that has been acquired (and only that)
* is freed.
*/
#include <iostream>
#include <limits>
using namespace std;

struct string {
	~string() { cout << "Calling string destructor" << endl; }
};

struct Dest_Call {
	::string str{};
	::string* str_ptr;
	Dest_Call() {
		try {
			str_ptr = new ::string[numeric_limits<int>::max() - 1];	// This would call default consturctor.
						// Initializes memory properly, because there are no constructors.
		}
		catch (bad_alloc e) {
			cout << "Now that we caught bad_alloc" << endl;
			// delete[] str_ptr; This line is not needed, because the allocation is not completed.
			// Hence, the memory is freed. However, str is destroyed using its destructor.
		}
		
	}

	~Dest_Call() { cout << "Initializing destruction" << endl; }
};

//int main() {
//	Dest_Call dest{};
//}