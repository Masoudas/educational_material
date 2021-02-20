package GoF.Creational.Prototype;

/**
 * Intent: Specify the kinds of objects to create using a prototypical instance,
 * and create new objects by copying this prototype.
 * 
 * Applicability: Use the Prototype pattern when a system should be independent
 * of how its products are created, composed, and represented. And:
 * 
 * 1- when the classes to instantiate are specified at run-time, for example, by
 * dynamic loading; or
 * 
 * 2- to avoid building a class hierarchy of factories that parallels the class
 * hierarchy of products; (Me: The point is that we give the prototype to a
 * prototype factory, and then this single factory would be responsible for
 * creating classes, particularly if all classes submit to a similar interface,
 * and all of them implement the clone method. We pass a prototype to the
 * factory, and it will clone it for us. Or we can always clone objects
 * directly).
 * 
 * 3- when instances of a class can have one of only a few different
 * combinations of state. It may be more convenient to install a corresponding
 * number of prototypes and clone them rather than instantiating the class
 * manually, each time with the appropriate state.
 * 
 * Participants are Prototype interface, ConcretePrototype and client.
 * 
 * Consequences:
 * 
 * Adding and removing products at run-time: Prototypes let you incorporate a
 * new concrete product class into a system simply by registering a prototypical
 * instance with the client. That's a bit more flexible than other creational
 * patterns, because a client can install and remove prototypes at run-time.
 * (Me: When using builders and factories, usually they don't have a common
 * interface. Hence, we have to hard code which factory is to be used.
 * Prototypes on the other hand have the same interface, hence the same clone
 * method can be used with different instances to give flexibility at run-time).
 * 
 * Specifying new objects by varying values. Highly dynamic systems let you
 * define new behavior through object composition—by specifying values for an
 * object's variables, for example—and not by defining new classes. You
 * effectively define new kinds of objects by instantiating existing classes and
 * registering the instances as prototypes of client objects. A client can
 * exhibit new behavior by delegating responsibility to the prototype. (Me: This
 * I think is kind of like when you drag the mouse in an app, and then by
 * cloning a point, we can define new shapes, without having to write a bizzare
 * shape class).
 * 
 * Specifying new objects by varying structure. Many applications build objects
 * from parts and subparts. Editors for circuit design, for example, build
 * circuits out of subcircuits. 1 For convenience, such applications often let
 * you instantiate complex, user-defined structures, say, to use a specific
 * subcircuit again and again. The Prototype pattern supports this as well. We
 * simply add this subcircuit as a prototype to the palette of available circuit
 * elements. As long as the composite circuit object implements Clone as a deep
 * copy, circuits with different structures can be prototypes (Me:
 * Self-evident!)
 * 
 * Reduced subclassing. Factory Method (121) often produces a hierarchy of
 * Creator classes that parallels the product class hierarchy. The Prototype
 * pattern lets you clone a prototype instead of asking a factory method to make
 * a new object. Hence you don't need a Creator class hierarchy at all. This
 * benefit applies primarily to languages like C++ that don't treat classes as
 * first-class objects. Languages that do, like Smalltalk and Objective C,
 * derive less benefit, since you can always use a class object as a creator.
 * Class objects already act like prototypes in these languages (Me: I think by
 * having some sort of default clone method? Like is almost the case with
 * protected clone method of Java object?).
 * 
 * Configuring an application with classes dynamically. Some run-time
 * environments let you load classes into an application dynamically. The
 * Prototype pattern is the key to exploiting such facilities in a language like
 * C++ (essentially like we demand something from the database, and then clone it.
 * So we're adding new behavior at run-time to our code!)
 * 
 * 
 * (Me: The most important question here is that how can we clone an object without
 * actually using a lot of resource? How to initialize a clone? And at what
 * situations will it be handy? Also as GoF state, a deep clone is not straight forward).
 */