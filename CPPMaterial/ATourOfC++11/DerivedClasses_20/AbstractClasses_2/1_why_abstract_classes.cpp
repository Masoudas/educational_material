/**
* In some situations, like for example if we define a shape, the area of the shape is an abstract concept. 
* Therefore, each derived class must have its own implementation. Therefore, the old pattern of just defining
* a virtual method does not correspond in this case. Moreover, a shape in and of itself is a concept, and trying
* to make a shape class does not make sense. In fact, what we need is particular shapes, such as rectangle, square,
* etc.
* 
* The alternative is to declare such methods as pure virtual function, leaving their implementation to the classes
* that are going to inherit them.
* 
* A class with one or more pure virtual functions is an abstract class, and no objects of that abstract class can 
* be created. An abstract interface is only meant to be accessed through reference or pointer (Me: and no slicing
* is possible, because the base class cannot be constructed, for having a pure virtual method).
* 
* Because the interface provided by an abstract class cannot be used to create objects using a constructor, 
* abstract classes don’t usually have constructors (but they can potentially, and we mean just by definition).
* 
* Note: As the example below shows, the base class destructor is not purely virtual. It could be purely virtual,
* however, note that in either case we need to have an implementation of the destructor, because it will be called
* in either case.
* Also note that as of C++20, a destructor may be declared pure virtual, for example in a base class which needs to 
* be made abstract, but has no other suitable functions that could be declared pure virtual. A pure virtual 
* destructor must have a definition, since all base class destructors are always called when the derived class is 
* destroyed.
* 
* Note also that a derived class is still abstract, if it hasn't overridden all the virtual methods of the base
* class.
* 
* The design style supported by abstract classes is called interface inheritance in contrast to the implementation 
* inheritance supported by base classes with state and/or defined member functions. Combinations of the two 
* approaches are possible. That is, we can define and use base classes with both state and pure virtual functions. 
* However, such mixtures of approaches can be confusing and require extra care.
*/
#include <utility>

class Shape { // abstract class
	int dim;
public:
	Shape(int d) : dim{d}{}
	virtual void rotate(int) = 0; // pure virtual function
	virtual void draw() const = 0; // pure virtual function
	virtual bool is_closed() const = 0; // pure virtual function
	// ...
	virtual ~Shape() {}; // virtual (Could be pure virtual, but needs implementation in any case.)
};

class Polygon : public Shape { // abstract class 
public:
	using Shape::Shape;
	bool is_closed() const override { return true; }
	// ... draw and rotate not overr idden ...
};

class Trapezoid : public Polygon {
public:
	Trapezoid() : Polygon{4}{}
	void rotate(int) override {}; 
	void draw() const override {}; 
};

void creating_polygons_and_shapes() {
	// Shape s{ 1 }; // Even though there's a constructor, construction is impossible. Abstract classes can't be 
					// constructed.

	Trapezoid t{};	// Ok, constructing, and noting that ctor uses base class.

	// Shape s{ t }; Slicing is impossible.

	Shape& s = t;	// Getting a reference is fine.
	Shape&& s_r = std::move(t);	// Getting an rvalue reference is also fine.

}