/**
* If the name of a base class can be reached through multiple paths in a multiple-inheritance lattice, it is 
* accessible if it is accessible through any path (Me: keep in mind a class inheriting from two classes as well).
* 
* 
* If a single entity is reachable through several paths, we can still refer to it without ambiguity.
*/


/// <summary>
///  Entity reachable through multiple paths, because accessible through any path.
/// </summary>
struct B {
	int m;
	static int sm;
	// ...
};

int B::sm = 2;

class D1 : public virtual B { /* ... */ };
class D2 : public virtual B { /* ... */ };
class D12 : public D1, private D2 { /* ... */ };

void accessing_common_method_in_double_inheritance() {
	D12* pd = new D12;
	B* pb = pd; // OK: accessible through D1
	int i1 = pd->m; // OK: accessible through D1
}

class X1 : public B { /* ... */ };
class X2 : public B { /* ... */ };
class XX : public X1, public X2 { /* ... */ };

void ambiguous_access_through_several_paths() {
	XX* pxx = new XX;
	//int i1 = pxx->m; // error, ambiguous: XX::X1::B::m or XX::X2::B::m?
	int i2 = pxx->sm; // OK: there is only one B::sm in an XX (sm is a static member)
	
}
