/**
 * A question that may arise is that, when having a factory, how should one return the 
 * object created? Should one return a pointer, an actual object (a copy), an smart pointer (like shared pointer),
 * or a unique pointer?
 * 
 * The answer is, on who wants to take care of the resource. The caller, or the callee (the factory). If the
 * answer is caller, then copy is good, which is the same for the unique_ptr case. If a shared pointer is
 * returned, the answer is both the caller and the caller. With a raw pointer however, we would assume the
 * callee, because it didn't want us to know anything about the resource.
 * 
 * Here are some thoughts:
 * If the factory must be polymorphic such as a virtual constructor, you have to use a smart pointer. I have already written about this special use-case. Read the details in the post: C++ Core Guidelines: Constructors (C.50).
 * If the object is cheap to copy and the caller should be the owner of the widget, use an object. If not cheap to copy, use an std::unique_ptr.
 * If the callee wants to manage the lifetime of the widget, use an std::shared_ptr
 * 
 */