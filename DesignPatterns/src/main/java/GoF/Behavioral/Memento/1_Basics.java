package GoF.Behavioral.Memento;

/**
 * Intent: Without violating encapsulation, capture and externalize an
 * object'sinternal state so that the object can be restored to this state later
 * 
 * When it's necessary to store the internal state of an object. For example, in
 * a graphical software, we move around objects, but at the same time we want to
 * know theire previous locations too.
 * 
 * A memento is an object that records an snapshot of another object's internal
 * state, the memento's originator. Only the originator can add data to the
 * object, or retrieve information from it (memento is a friend of its
 * originator). It's opaque to other objects. The memento pattern simplifies the
 * internal state of the originater, because it would not be responsible for
 * keeping track of its own state, and deal with storage and so forth.
 * 
 * The memento has a private interface, which can only be used by the originator
 * to access the state. This allows the internal state of the object to remain
 * unexposed (can be implemented with private interface in Java and friend in
 * C++).
 * 
 * A downside to the algorithm being the number of mementos that have to be
 * saved in the caretaker. To remedy it, we could save the incremental change of
 * states.
 * 
 * Participants:
 * 
 * Memento: Stores as much as the internal state of the object as desired.
 * Implements interfaces to be accessed only by the originator, not other classes. Care
 * taker sees a very narrow memento to the interface.
 * 
 * CareTaker: (Most probably a singleton), that keeps (all) the mementos of an
 * object and can return them when desired. This object does not do any
 * processing on the mementos. 
 * 
 * Originator: This is the object responsible for generating the memento, and uses it to 
 * get the state as well.
 */