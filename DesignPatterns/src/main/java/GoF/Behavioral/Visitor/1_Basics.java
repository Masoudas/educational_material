package GoF.Behavioral.Visitor;

/**
 * Intent: Represent an operation to be performed on the elements of an object
 * structure. Visitor lets you define a new operation without changing the
 * classes of the elements on which it operates (Me: Note the difference between
 * object structure and object. Visitors apply to a particular object, and they
 * let you traverse an object structure at the same time.)
 * 
 * 
 * Motivation:
 * 
 * With the Visitor pattern, you define two class hierarchies: one for the
 * elements being operated on, and one for the visitors that define operations
 * on the elements. You create a new operation by adding a new subclass to the
 * visitor class hierarchy. As long as the grammar doesn'tchange (that is, we
 * don't have to add new element subclasses), we can add new functionality
 * simply by defining new subclasses (Me: And supposedly, the visitor is not
 * supposed to change the internal value of the elements. Also note that the
 * visitor of a class should take reference to that class. Suppose for example a
 * class has an array and we want to visit that, we don't pass the reference to
 * that array in the visitor, rather reference to the entire class, to indicate
 * that the visitor visits this particular class.)
 * 
 * (Me: Supposedly, visitors are not supposed to change the internal structure
 * of a class. They just perform an operation using the data, like printing
 * something for example. If we let visitors change the internal structure of
 * the class, who knows what would happen? But I'm not sure this applies 100%.
 * If we are considerate and careful, why wouldn't a visitor change the internal
 * structure of the class).
 * 
 * Applicability: Use pattern when,
 * 
 * 1- an object structure contains many classes of objects with differing
 * interfaces, and you want to perform operations on these objects that depend
 * on their concrete classes (Me: Essentially, the operation is the same, but
 * the data types are different. So you have print, but you have ClassA, ClassB,
 * etc. So you define PrintVisitor, but in it you write visitA, visitB, for
 * different data types).
 * 
 * 2- many distinct and unrelated operations need to be performed on objects in
 * an object structure, and you want to avoid "polluting" their classes with
 * these operations. Visitor lets you keep related operations together by
 * defining them in one class. When the object structure is shared by many
 * applications, use Visitor to put operations in just those applications that
 * need them.
 * 
 * 3- the classes defining the object structure rarely change, but you often want
 * to define new operations over the structure. Changing the object structure
 * classes requires redefining the interface to all visitors,which is
 * potentially costly. If the object structure classes change often, then it's
 * probably better to define the operations in those classes.
 * 
 * 
 * 
 * 
 * 
 * Structure:
 * 
 * See the photo. (Me: it's interesting that in the visitor interface, we
 * explicitly say VisitConcreteElementA, or VisitConcreteElementB. I suppose it
 * does make sense, because a visit operation maybe defined for a particular
 * concrete class. But would it be possible to define the operation for the
 * Element class directly?). (Me: Pay speciall attention to the ObjectStructor
 * class. It's the class responsible for passing all instances of
 * ConcreteElementA or B to the visitor. Hence, it can be composite, or it can
 * be a list, etc.)
 * 
 * Consequences:
 * 
 * 1- Visitor makes adding new operations easy.Visitors make it easy to add
 * operations that depend on the components of complex objects.You can define a
 * new operation over an object structure simply by adding a new visitor. In
 * contrast, if you spread functionality over many classes, then you must change
 * each class to define a new operation (Me: Suppose we define the action
 * directly inside the class. Then to define new actions, we have to extend the
 * class, recompile or other. Allowing visitors to pass help us define new
 * actions without changing the code)
 * 
 * 2- A visitor gathers related operations and separates unrelated ones.Related
 * behavior isn't spread over the classes defining the object structure; it's
 * localized in a visitor. Unrelated sets of behavior are partitioned in their
 * own visitor subclasses. That simplifies both the classes defining the
 * elements and the algorithms defined in the visitors. Any algorithm-specific
 * data structures can be hidden in the visitor (Me: Again, note that visitors
 * are not supposed to change the internal state of the class, otherwise we may
 * not know the state of a class after several visits.)
 * 
 * 3- Adding new ConcreteElement classes is hard.The Visitor pattern makes it
 * hard to add new subclasses of Element. Each new ConcreteElement gives rise to
 * a new abstract operation on Visitor and a corresponding implementation in
 * every ConcreteVisitor class. Sometimes a default implementation can be
 * provided in Visitor that can be inherited by most of the ConcreteVisitors,
 * but this is the exception rather than the rule. So the key consideration in
 * applying the Visitor pattern is whether youare mostly likely to change the
 * algorithm applied over an object structure or the classes of objects that
 * make up the structure. The Visitor class hierarchy can be difficult to
 * maintain when newConcreteElement classes are added frequently. In such cases,
 * it'sprobably easier just to define operations on the classes that make up the
 * structure. If the Element class hierarchy is stable, but you are continually
 * adding operations or changing algorithms, then the Visitor pattern will help
 * you manage the changes.
 * 
 * 4- Visiting across class hierarchies. An iterator can visit the objects in a
 * structure as it traverses them by calling their operations. But an iterator
 * can't work across object structures with different types of elements. For
 * example, the Iterator interface defined on page 295 can access only objects
 * of a particular type with its getItem (or next) method, whereas a visitor can
 * have methods that work on different kinds of data types.
 * 
 * 5- Accumulating state. Visitors can accumulate state as they visit each
 * element in the object structure. Without a visitor, this state would be
 * passed as extra arguments to the operations that perform the traversal, or
 * they might appear as global variables (Me: perhaps it implies we can keep the
 * state of each class as we visit it (Memento pattern)?).
 * 
 * 6- Breaking encapsulation.Visitor's approach assumes that the ConcreteElement
 * interface is powerful enough to let visitors do their job. As a result, the
 * pattern often forces you to provide public operations that access an
 * element's internal state, which may compromise its encapsulation.
 * 
 * 
 * 
 * 
 */