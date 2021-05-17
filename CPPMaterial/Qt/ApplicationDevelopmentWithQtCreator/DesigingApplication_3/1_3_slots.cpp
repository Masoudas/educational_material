/**
 * A slot is called when a signal connected to it is emitted. Slots are normal C++ functions and can be called 
 * normally; their only special feature is that signals can be connected to them.
 * 
 * Since slots are normal member functions, they follow the normal C++ rules when called directly. However, as 
 * slots, they can be invoked by any component, regardless of its access level, via a signal-slot connection. 
 * This means that a signal emitted from an instance of an arbitrary class can cause a private slot to be invoked 
 * in an instance of an unrelated class. (me: Hence, slots can be public or private member functions, 
 * nevertheless, they can be called by a signal. We usually want to connect a signal to a slot in its own class
 * however.)
 * 
 * You can also define slots to be virtual, which we have found quite useful in practice.
 */