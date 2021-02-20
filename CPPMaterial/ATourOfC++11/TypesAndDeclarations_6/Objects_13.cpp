/** Note that an object is contigous space in memory, and exceeds the realization of a class meaning.
 * An lvalue referes to an object then.
 * 
 * Objects have different life times:
 * automatic: The ones that are created in the life time of an scope, and are phased out by the end of it.
 *            These objects are declared in the stack.
 * static: Are declared in the global or namespace scope. One should be cautios about these,
 * because the exist throughout the life-time of the program.
 * 
 * free store: Using new and delete, we can create objects whose lifetime we can control. These objects
 * are not declared in the stack, otherwise they would vanish (so I assume they're declared in heap).
 * 
 * thread local: Objects that are created in a local thread. They die with thread.
 * 
 * temporary objects: These are the result of operations. If they're bound to a reference, they remain
 * in memory, otherwise they vanish as soon as the expression is complete.
 * 
 * In conclusion, the reason why you can't return an int t declared in a scope of function is that
 * it's automatic, and defined on the stack, which is overridden by the next function. This is why you
 * need to use the new operator.
*/