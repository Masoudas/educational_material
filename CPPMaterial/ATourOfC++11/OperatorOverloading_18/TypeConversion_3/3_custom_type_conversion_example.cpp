/**
* We define a 6-bit non-negative integer, Tiny, that can mix freely with integers in arithmetic operations. Tiny throws 
* Bad_range if its operations overflow or underflow.
* 
* Now, based on the given definitions, the operator Tiny::operator int() converts the type Tiny to int on demand, and 
* very important to note, implicity.  Note that the type being converted to is part of the name of the operator and 
* cannot be repeated as the return value of the conversion function.
*/

class Tiny {
	char v;
	void assign(int i) { if (i & ~077) throw Bad_range(); v = i; }
public:
	class Bad_range { };

	Tiny(int i) { assign(i); }
	Tiny& operator=(int i) { assign(i); return *this; }
	
	operator int() const { return v; } // conversion to int function
	operator bool() { return v; } // Eh!
};

void using_tiny() {
	Tiny c1 = 2;
	Tiny c2 = 62;
	
	
	int i = c1 + c2; // i = 64
	c1 = c1 + c2; // range error: c1 can’t be 64
	
	Tiny c3 = c2;	// No range check necessary!
}