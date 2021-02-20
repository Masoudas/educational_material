package GoF.Structural.Bridge;

/**
 * Also know as Handle/Body pattern, where Handle is the abstraction, and body
 * is the implementation.
 * 
 * Intent: Decouple an abstraction from its implementation so that the two can
 * vary independently.
 * 
 * (Me: So let's say we have an abstract Window class. Then for each platform we
 * need to extend it, like IBMWindow, AppleWindow and so forth. Moreover, if we
 * have new types of windows like TransientWindow, we need to again write
 * IBMTransientWindow, AppleTransientWindow. So what do we do? We can define
 * another abstract class called WindowImp, which is an abstract class for
 * window implementation. Now, the implementation itself is abstracted. Hence,
 * we give the implemetation as a parameter to the Window, then it will act as a
 * bridge between implementation and abstraction! The interesting phenomen is
 * that in this case, implementation and abstraction vary independently! This is
 * exactly the pattern I used in 4Polar software, where I give the Views
 * (implementation) to ViewModels.)
 * 
 * (Me: A very interesting example could be implementing a class of primitive operations
 * like sines and cosines, etc, and an abstraction would be computation of very
 * complicated mathematical formulas).
 * 
 * Note that the implementation usually consists of primitive (simple) operations,
 * where as abstraction forms more complicated options using the primitive type.
 * 
 * Applicability:
 * 
 * 1- Use when you want to decouple an abstraction from it's implementation
 * Especially when implementation must be chosen at run-time.
 * 
 * 2- both the abstractions and their implementations should be extensible by
 * subclassing. In this case, the Bridge pattern lets you combine the different
 * abstractions and implementations and extend them independently
 * 
 * 3- changes in the implementation of an abstraction should have no impact on
 * clients; that is, their code should not have to be recompiled
 * 
 * 4- you want to hide the implementation of an abstraction completely from
 * clients. In C++ the representation of a class is visible in the class
 * interface.
 * 
 * 5- You have a proliferation of classes (as is the case for the windows)
 * 
 * 6- you want to share an implementation among multiple objects (perhaps using
 * reference counting), and this fact should be hidden from the client
 * 
 * Participants:
 * 
 * Abstraction: defines the abstraction's interface. Maintains a reference to an
 * object of type Implementor.
 * 
 * RefinedAbstraction: Extends the interface defined by Abstraction.
 * 
 * Implementor (WindowImp): Defines the interface for implementation classes.
 * This interface doesn't have to correspond exactly to Abstraction's interface;
 * in fact the two interfaces can be quite different. Typically the Implementor
 * interface provides only primitive operations, and Abstraction defines
 * higher-level operations based on these primitives.
 * 
 * ConcreteImplementor: implements the Implementor interface and defines its
 * concrete implementation
 * 
 * Collaboration: Abstraction forwards requests to clients.
 * 
 * Consequenses:
 * 
 * 1- An implementation is not bound permanently to an interface. The
 * implementation of an abstraction can be configured at run-time. It's even
 * possible for an object to change its implementation at run-time.
 * 
 * 2- Improved extensibility. You can extend the Abstraction and Implementor
 * hierarchies independently
 * 
 * 3- Hiding implementation details from clients. You can shield clients from
 * implementation details, like the sharing of implementor objects and the
 * accompanying reference count mechanism (if any)
 * 
 * Implementation:
 * 
 * 1- In situations where there's only one implementor, it usually does not make
 * sense to perform this abstraction.
 * 
 * 3- Who should chose the implementor is up for debate. The Abstraction implementor
 * can do this inside, or the client can provide the implementation.
 */