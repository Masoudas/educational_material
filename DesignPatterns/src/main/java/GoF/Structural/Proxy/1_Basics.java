package GoF.Structural.Proxy;

/**
 * Intent:
 * 
 * Provide a surrogate or placeholder for another object to control access to it
 * 
 * Motivation:
 * 
 * (Me: If an object is heavy, we may want to delay its construction as much as
 * possible, but we may still need the information concerning it. Hence, we use
 * a place holder like proxy. This may be for example, when we want to open an
 * image (see 1_GraphicsExample.jpg). Hence the image proxy complies the same
 * interface as the image, but delays actually opening it the longest possible.)
 * 
 * Related patterns:
 * 
 * (Me: The proxy pattern is essentially like the decorator pattern (in most
 * cases), in that it (usually) implements the same interface as the object it
 * proxies. The difference however is that proxy does not add new behavior,
 * whereas decorator does. Moreover, the pattern resembles adaptor in the sense
 * that it adapts the object for some needs, the difference however is that
 * adaptor changes the interface for a completely new application.)
 * 
 * Applicability:
 * 
 * Proxy is applicable whenever there is a need for a more versatile or
 * sophisticated reference to an object than a simple pointer.
 * 
 * 1. A remote proxy provides a local representative for an object in a
 * different address space. NEXTSTEP [Add94] uses the class NXProxy for this
 * purpose. Coplien [Cop92] calls this kind of proxy an "Ambassador."
 * 
 * 
 * 2. A virtual proxy creates expensive objects on demand. The ImageProxy
 * described in the Motivation is an example of such a proxy.
 * 
 * 3. A protection proxy controls access to the original object. Protection
 * proxies are useful when objects should have different access rights. For
 * example, KernelProxies in the Choices operating system [CIRM93] provide
 * protected access to operating system objects
 * 
 * 4. A smart reference is a replacement for a bare pointer that performs
 * additional actions when an object is accessed. Typical uses include 1-
 * counting the number of references to the real object so that it can be freed
 * automatically when there are no more references (also called smart pointers
 * [Ede92]). 2- loading a persistent object into memory when it's first
 * referenced. 3- checking that the real object is locked before it's accessed
 * to ensure that no other object can change it.
 * 
 * Structure:
 * 
 * Structure is given in 1_Structure.png. Note that Subject is the interface
 * which the client deals with. RealSubject is a realization of it. Proxy
 * shields the RealSubject.
 * 
 * Participants:
 * 
 * Proxy: 1- maintains a reference that lets the proxy access the real subject.
 * Proxy may refer to a Subject if the RealSubject and Subject interfaces are
 * the same. 2- provides an interface identical to Subject's so that a proxy can
 * by substituted for the real subject. 3- controls access to the real subject
 * and may be responsible for creating and deleting it. 4- other
 * responsibilities depend on the kind of proxy: § remote proxies are
 * responsible for encoding a request and its arguments and for sending the
 * encoded request to the real subject in a different address space. § virtual
 * proxies may cache additional information about the real subject so that they
 * can postpone accessing it. For example, the ImageProxy from the Motivation
 * caches the real image's extent. § protection proxies check that the caller
 * has the access permissions required to perform a request.
 * 
 * Subject: Defines the common interface for RealSubject and Proxy so that a
 * Proxy can be used anywhere a RealSubject is expected.
 * 
 * RealSubject: defines the real object that the proxy represents.
 * 
 * Collaborations:
 * 
 * The proxy sends the request to subject whenever it's appropriate.
 * 
 * Consequences: The indirect access provided by the proxy has many uses. 1. A
 * remote proxy can hide the fact that an object resides in a different address
 * space. 2. A virtual proxy can perform optimizations such as creating an
 * object on demand. 3. Both protection proxies and smart references allow
 * additional housekeeping tasks when an object is accessed.
 * 
 * (Me according to GoF: If an expensive object is copied, but never modified,
 * the proxy can keep a safe copy somewhere and only represent that to every
 * one.)
 * 
 * Implementation:
 * 
 * In C++, we can overload the operator -> to work with the proxy rather than
 * the actual subject. But in general, we tend to use an actual class (Me: and
 * say we have a builder, factory or the kind, we can actually return the proxy
 * interface rather than the actual one.)
 * 
 * Note also that a proxy does not have to refer to a concrete implementation of
 * a class. It may use an interface for a class.
 */