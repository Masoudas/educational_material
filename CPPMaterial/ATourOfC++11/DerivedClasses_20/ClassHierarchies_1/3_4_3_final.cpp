/**
* (Me: Has any one ever in the history of the programming used the final keyword I wonder? I mean among us lesser
* mortals I guess.)
* 
* We use virtual for functions we want writers of derived classes to be able to define or redefine. We base our 
* choice on the meaning (semantics) of our class:
* - Can we imagine the need for further derived classes?
* - Does a designer of a derived class need to redefine the function to achieve a plausible aim?
* - Is overriding a function error-prone (i.e., is it hard for an overriding function to provide the expected 
*	semantics of a virtual function)?
* 
* If the answer is "no" to all three questions, we can leave the function non-virtual to gain simplicity of 
* design and occasionally some performance (mostly from inlining). The standard library is full of examples of 
* this.
* 
* Far more rarely, we have a class hierarchy that starts out with virtual functions, but after the definition 
* of a set of derived classes, one of the answers becomes "no.". In such a case, we use the final keyword as
* a post function keyword.
* 
* We can make all virtual methods of a class by writing the keyword final after it. Note that adding final to the
* end of class definition as such, prevents the class from being inherited as well.
* 
* A final specifier is not part of the type of a function and cannot be repeated in an out-of-class definition.
*/
#include <string>
using namespace std;

struct Node { // interface class
	virtual string type() = 0;
	// ...
};

class If_statement : public Node {
public:
	string type() override final; // prevent further overriding
};

class For_statement final : public Node {
public:
	string type() override;
};