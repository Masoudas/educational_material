package GoF.Behavioral.ChainOfResponsibility;

/**
 * 
 * (Me: The Handler interface keeps an instance of it's successor. If it can
 * handle the request, it will be fine, otherwise, it will send it along to the
 * successor. In this sense, this is like the observer pattern, right?)
 * 
 * (Me: Notice that we are talking about the successor here, but in face the
 * successor can be superior to the predecessor in some sense. For example, the
 * help button is part of a widget (successor), which is part of a Dialog
 * (successor).)
 * 
 * Intent:
 * 
 * Avoid coupling the sender of a request to its receiver by giving morethan one
 * object a chance to handle the request. Chain the receiving objects and pass
 * the request along the chain until an object handles it.
 * 
 * Applicability:
 * 
 * 1- more than one object may handle a request, and the handler isn't knowna
 * priori. The handler should be ascertained automatically.
 * 
 * 2- you want to issue a request to one of several objects without specifying
 * the receiver explicitly.
 * 
 * 3- the set of objects that can handle a request should be specified
 * dynamically.
 * 
 * Participants:
 * 
 * Handler : Defines an interface for handling requests. (optional) implements
 * the successor link (Me: Who is the successor)
 * 
 * ConcreteHandler : handles requests it is responsible for. Can access its
 * successor. if the ConcreteHandler can handle the request, it does so;
 * otherwise it forwards the request to its successor.
 *
 * Client: initiates the request to a ConcreteHandler object on the chain.
 * 
 * Consequences:
 * 
 * 1- The pattern frees an object from knowing which other object handles
 * arequest. An object only has to know that a request will be handled
 * "appropriately." Both the receiver and the sender have no explicit knowledge
 * of each other, and an object in the chain doesn't have toknow about the
 * chain's structure.
 * 
 * 2- Added flexibility in assigning responsibilities to objects.Chain of
 * Responsibility gives you added flexibility in distributingresponsibilities
 * among objects. You can add or changeresponsibilities for handling a request
 * by adding to or otherwisechanging the chain at run-time. You can combine this
 * with subclassingto specialize handlers statically (Me: To understand this,
 * take a look at 2_Example. There, we set the handler with a set method, hence
 * we can change it at run-time.)
 * 
 * 3- Receip is not guaranteed: Since a request has no explicit receiver,
 * there's no guaranteeit'll be handled—the request can fall off the end of the
 * chainwithout ever being handled. A request can also go unhandled when the
 * chain is not configured properly (Me: This would be the main concern
 * regarding this pattern).
 * 
 * Implementation issues:
 * 
 * 1- Implementing the successor chain.There are two possible ways to implement
 * the successor chain: a. Define new links (usually in the Handler, but
 * ConcreteHandlerscould define them instead). b. Use existing links. Often you
 * can use existingobject references to form the successor chain. For example,
 * parentreferences in a part-whole hierarchy can define a part's successor.
 * Awidget structure might already have such links. Composite (183) discusses
 * parent references in more detail (Me: Essentially, if another source defines
 * the parent of an object (like the case of composite pattern), you can use
 * that same parent as successor).
 * 
 * 2- Connecting successors.If there are no preexisting references for defining
 * a chain, then you'llhave to introduce them yourself. In that case, the
 * Handler not only defines the interface for the requests but usually maintains
 * thesuccessor as well. That lets the handler provide a defaultimplementation
 * of HandleRequest that forwards the request to thesuccessor (if any). If a
 * ConcreteHandler subclass isn't interestedin the request, it doesn't have to
 * override the forwarding operation,since its default implementation forwards
 * unconditionally (Me: Such is the case of defining the Handler as an interface
 * or purely virtual in C++).
 * 
 * 3- Representing requests.Different options are available for representing
 * requests. In thesimplest form, the request is a hard-coded operation
 * invocation, as inthe case of HandleHelp. This is convenient and safe, but you
 * canforward only the fixed set of requests that the Handler class defines. An
 * alternative is to use a single handler function that takes arequest code
 * (e.g., an integer constant or a string) as parameter.This supports an
 * open-ended set of requests. The only requirement is that the sender and
 * receiver agree on how the request should be encoded (or, we may use classes
 * for defining requests).
 */