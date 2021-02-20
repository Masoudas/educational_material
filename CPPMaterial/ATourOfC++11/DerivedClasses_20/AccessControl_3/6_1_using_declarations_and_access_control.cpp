/**
* A using-declaration cannot be used to gain access to additional information. It is simply a mechanism for making 
* accessible information more convenient to use. On the other hand, once access is available, it can be granted to 
* other users. (Me: note that this is possible even if the access granted by the base is protected. In other words,
* we can increase the access as well as decrease the access to a base class method. But we typically shouldn't 
* increase access. This also goes back to our treating a class as a namespace. Once we declare something in the
* new namespace, it hides the original one. So if a protected member is dragged as public, then the protected one
* is hidden).
* 
* One way this is helpful is that we can manipulate access control by inheriting as private or protected, and then
* defining access using such declarations.
*/

class base {
private:
	int pri;

protected:
	int pro;

public:
	int pub;
};

class derived : public base {
	// using base::pri; Nope! Can't access base private members.

public:
	using base::pro;	// Ok! increasing access, by dragging the protected member from the base.

protected:
	using base::pub;	// Ok! decreasing access by dragging the public base member.
};

class third : base {	// Inheriting as private for manipulation of access control of fields.
public:
	using base::pro;	// Ok! Manipulate the field, and declare it as public

private:
	using base::pub;	// Ok! Manipulate the field, and declare it as private

};