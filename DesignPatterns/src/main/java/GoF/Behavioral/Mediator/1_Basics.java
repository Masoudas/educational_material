package GoF.Behavioral.Mediator;

/**
 * (Me: See 1_MediatorForWidgets.png. Note that the director does not
 * necessarily have to be an observer of the objects it direct (list or Widget).
 * For example, here the method WidgetChanged(Widget), passes itself to the
 * director. Also note that as always, the director itself maybe just a simple
 * implementation, or it may have abstractions of its own. But in any case, the
 * objects being directed have a reference of the director object).
 * 
 * 
 * Applicability: Use the Mediator pattern when
 * 
 * 1- A set of objects communicate in well-defined but complex ways. The
 * resulting interdependencies are unstructured and difficult to understand.
 * 
 * 2- Reusing an object is difficult because it refers to and communicates with
 * many other objects.
 * 
 * 3- A behavior that's distributed between several classes should be
 * customizable without a lot of subclassing.
 * 
 * Participants:
 * 
 * Mediator (DialogDirector) : defines an interface for communicating with
 * Colleague objects.
 * 
 * ConcreteMediator (FontDialogDirector): implements cooperative behavior by
 * coordinating Colleague objects. knows and maintains its colleagues.
 * 
 * Colleague classes (ListBox, EntryField): each Colleague class knows its
 * Mediator object. each colleague communicates with its mediator whenever it
 * would have otherwise communicated with another colleague.
 * 
 * 
 * Collaborations: Colleagues send and receive requests from a Mediator object.
 * The mediator implements the cooperative behavior by routing requests between
 * the appropriate colleague(s).
 * 
 * 
 */