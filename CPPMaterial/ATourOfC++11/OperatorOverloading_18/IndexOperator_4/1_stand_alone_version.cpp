/**
* This is all me:
* Note that the bracket operator cannot be overloaded outside the class. It has to be overloaded inside.
*/

struct S { 
	int x[3] = { 1, 2, 3 };  
	int operator[](int i) {
		return x[i];
	}
};

/** Can't overload here.
int operator[](const S& s, int i) {
	return s.x[i];
}
*/
