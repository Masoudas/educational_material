/**
* The standard reminds us of the following:
* 
* Friendship is not transitive (a friend of your friend is not your friend). (A is friend of B, C is friend of A, C is not
* friend of B).
* - Friendship is not inherited (your friend's children are not your friends).
* - A friend class declaration cannot define a new class (friend class X {}; is an error).
* - Access specifiers have no effect on the meaning of friend declarations (they can appear in private: or in public: 
*   sections, with no difference).
* - When a local class declares an unqualified function or class as a friend, only functions and classes in the innermost 
*   non-class scope are looked up, not the global functions.
* 
* A name first declared in a friend declaration within a class or class template X becomes a member of the innermost enclosing namespace of X, but is not visible for lookup (except argument-dependent lookup that considers X) unless a matching declaration at the namespace scope is provided 
* Note that the first rules restrict friendship greatly.
* 
* Me: FYI, I've no idea how to access Local from anywhere outside the function it's defined in. If we can't access it, then
* what's the point of declaring friends for it?
*/

class F {};
int f();
void local_scope_as_function(){
    extern int g();
    class Local { // Local class in the main() function
        friend int f(); // Error, no such function declared in main() (not in this scope or enclosing scope).
        friend int g(); // OK, there is a declaration for g in main()
        friend class F; // friends a local F (defined later) (If this were in another namespace, needed qualificaton).
        friend class ::F; // friends the global F

        int n;
    };
    class F {}; // local F
}