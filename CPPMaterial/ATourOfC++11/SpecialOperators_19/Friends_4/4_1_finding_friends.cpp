/**
* As is the case, A friend must be previously declared in an enclosing scope or defined in the non-class scope immediately 
* enclosing the class that is declaring it to be a friend. In other words, friend classes in the same scope need not be
* scoped with the :: parameter. (Me: Although as the following example shows, f1 which is in the enclosing scope is unable
* to find private members of C, even though declared a friend!).
* 
* (Me: So, the fundamental rule of friendship is that it has to be previously declared (be it class or method), Putting
* the class identifier is simply a convenience that works for this namespace or enclosing namespace. For example, we see
* below that if we do so between namespace nn1 and nn, because class v is declared after nn1 is known, friendship does
* not work, even when using class. It's like a friend of yours introducing someone to you. Just because he was introduced
* to you (equivalent to using class before its name), you cannot let him know everything about you, because you don't
* know him. The only way making personal friends works is that if he's already in your scope (in your namespace) or he's
* a family member (your parent's scope), in which case its fine).
* 
* A friend function can be found through its arguments (§14.2.4) even if it was not declared in the immediately enclosing 
* scope (this is equivalent to ADL, but then again, it doesn't seem to work I have to say).
*/

class C1 { }; // will become friend of N::C
void f1() {
	// N::C c; This is pointless, because even if I declare N before here, then this function still cannot see
	// C. So, I don't know!
	

}; // will become friend of N::C

namespace N {
	class C2 { }; // will become friend of C
	void f2() { } // will become friend of C
	
	class C {
		int x;
	public:
		friend C1; // OK (previously defined)
		friend void f1();
		friend class C3; // OK (defined in enclosing namespace)
		friend void f3();
		friend class C4; // First declared in N and assumed to be in N
		friend void f4();
	};
	
	class C3 {}; // friend of C
	
	void f3() { 
		C x; x.x = 1; 
	} // OK: friend of C
}

class C4 { }; // not friend of N::C
//void f4() { N::C x; x.x = 1; } // error : x is private and f4() is not a friend of N::C

namespace nn1 {}

namespace nn {
	class u{
	//	friend class nn1::v;	// Error! class v is not known in this context. Hence, the use of class does not help.
	};

	void m(const u& r);
}

namespace nn1 {
	class v {
		friend void m(const nn::u&);// Well. ADL does not seem to be work to find m! I thought the whole point of Bjarne's
								    // last statement was that we can find m with ADL!
		int val;
	};
}

void nn::m(const u& r) {
	nn1::v V{};

	// V.val; Nope! Cannot see val, unless we declare friendship as friend void nn:m(const nn::u&);
}
