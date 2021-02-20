package GoF.Structural.Composite;

/**
 * Intent: Compose objects into tree structures to represent part-whole (Joze be
 * Kol in Farsi!) hierarchies. Composite let's clients treat objects and
 * composites of objects uniformly.
 * 
 * Imagine a graphics application. Each element has different properties, but we
 * want all of them to have a common denominator. Hence, we can treat all the
 * objects the same way. This implies that the client knows there's a common
 * behavior among them, and for example can use the draw function in all the
 * graphical units to draw them, no matter what they are. Also, each unit has
 * it's own children (like a window has buttons) and this forms the tree
 * structure we mentioned before. Note that there would be no difference between
 * nodes and leaves in this structure.
 * 
 * Hence, The key to the Composite pattern is an abstract class that represents
 * both primitives and their containers.
 * 
 * As is clear, the most important pitfall is the over generalization.
 * 
 * Use pattern: 
 * 1- When you want to respresent part-whole hierarchies. 
 * 2- When you want the client to treat all the objects equally, and forget about their
 * differences.
 * 
 * Participants are (and the key is that we can distinguish between leaves and nodes): 
 * 1- Component: The common interface among all elements. This
 * is the draw in our case. It perhaps gives a default implementation. It
 * defines a method to access children, and optionally to access parents. 
 * 2- Leaf: Represents the leaf in the structure. These objects have no children.
 * 3- Composite: This object defines behavior for components having children. It also stores
 * child component, and implements child related behavior in the Component.
 * 4- Client: Manipulates the objects through the component behavior.
 * 
 * Clients use the Component class interface to interact with objects in the 
 * composite structure. If the recipient is a Leaf, then the request is handled 
 * directly. If the recipient is a Composite, then it usually forwards requests 
 * to its child components, possibly performing additional operations before 
 * and/or after forwarding
 */