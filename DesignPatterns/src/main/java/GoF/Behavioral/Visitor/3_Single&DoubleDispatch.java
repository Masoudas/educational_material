package GoF.Behavioral.Visitor;

/**
 * One idea discussed is single and double dispatch methods.
 * 
 * Single dispatch methods: ?????????? Suppose we have several overloads of a
 * method with the same name. The method that's executed depends on the single
 * data type we pass them. Hence, we call these methods single dispatch
 * 
 * 
 * Double dispatch methods: ????????? Suppose we pass an abstraction (like the
 * visitor interface) to a class, with several methods overloaded. Then the
 * visit method executed depends on the implementation that is passed, as well
 * as the argument given to the method. Hence because it depends on two types,
 * we call it a Double Dispatch method.
 */