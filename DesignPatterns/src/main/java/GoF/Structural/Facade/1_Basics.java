package GoF.Structural.Facade;

/**
 * Facade means the frontal part of the building, especially the part that faces
 * the street (Nama in Farsi!).
 * 
 * Intent: Provide a unified interface to a set of interfaces in a subsystem.
 * Facade defines a higher-level interface that makes the subsystem easier to
 * use (Me: This frontal level interface is not necessarily an interface, but
 * could be an actual class, like the system.out in Java).
 * 
 * An example is access to compiler functions, where every function (like the
 * command line, printing, etc), has a unified interface, but all of them have a
 * concrete implementation with more detail.
 * 
 * Applicability:
 * 
 * 1- you want to provide a simple interface to a complex subsystem. Subsystems
 * often get more complex as they evolve. Most patterns, when applied, result in
 * more and smaller classes. This makes the subsystem more reusable and easier
 * to customize, but it also becomes harder to use for clients that don't need
 * to customize it. A facade can provide a simple default view of the subsystem
 * that is good enough for most clients. Only clients needing more
 * customizability will need to look beyond the facade.
 * 
 * 2- there are many dependencies between clients and the implementation classes
 * of an abstraction. Introduce a facade to decouple the subsystem from clients
 * and other subsystems, thereby promoting subsystem independence and
 * portability.
 * 
 * 3 - you want to layer your subsystems. Use a facade to define an entry point
 * to each subsystem level. If subsystems are dependent, then you can simplify
 * the dependencies between them by making them communicate with each other
 * solely through their facades (Me: What does this mean? If systems communicate
 * with each other only through their facades, then we have an interface for all
 * of them, that can work on them. Then this is exactly what we are looking for
 * as a facade!)
 * 
 * Participants:
 * 
 * 1- facade: Knows which subsystem is responsible for a request, and delegates
 * the request to that subsystem (Me: How can an interface know what subsystem
 * is responsible for the request? Depends on who invokes the request I
 * suppose!).
 * 
 * 2- Subsystems: implement subsystem functionality. Handle work assigned by the
 * Facade object. have no knowledge of the facade; that is, they keep no
 * references to it.
 * 
 * 
 * Collaborations:
 * 
 * 1- The client sends the request to the facade. Facade is responsible for
 * invoking the proper class for handling the request.
 * 
 * 2- Clients that use the facade don't have to access its subsystem objects
 * directly
 * 
 * Consequences:
 * 
 * 1- It shields clients from subsystem components, thereby reducing the number
 * of objects that clients deal with and making the subsystem easier to use.
 * 
 * 2. It promotes weak coupling between the subsystem and its clients. Often the
 * components in a subsystem are strongly coupled. Weak coupling lets you vary
 * the components of the subsystem without affecting its clients. They can
 * eliminate complex or circular dependencies (Me: This is very interesting. I
 * wonder if what makes circular dependency go away is the use of facade, when
 * for example we're creating a multi-modular project in Java.)
 * 
 * 3- It doesn't prevent applications from using subsystem classes if they need
 * to. Thus you can choose between ease of use and generality.
 * 
 * 
 * Implementation:
 * 
 * 1- Reducing client-subsystem coupling. The coupling between clients and the
 * subsystem can be reduced even further by making Facade an abstract class with
 * concrete subclasses for different implementations of a subsystem. Then
 * clients can communicate with the subsystem through the interface of the
 * abstract Facade class. This abstract coupling keeps clients from knowing
 * which implementation of a subsystem is used. An alternative to subclassing is
 * to configure a Facade object with different subsystem objects. To customize
 * the facade, simply replace one or more of its subsystem objects.
 * 
 * 2- Public versus private subsystem classes. A subsystem is analogous to a
 * class in that both have interfaces, and both encapsulate something—a class
 * encapsulates state and operations, while a subsystem encapsulates classes.
 * And just as it's useful to think of the public and private interface of a
 * class, we can think of the public and private interface of a subsystem. The
 * public interface to a subsystem consists of classes that all clients can
 * access; the private interface is just for subsystem extenders. The Facade
 * class is part of the public interface, of course, but it's not the only part.
 * Other subsystem classes are usually public as well. For example, the classes
 * Parser and Scanner in the compiler subsystem are part of the public
 * interface.
 */