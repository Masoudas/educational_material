package GoF.Creational.Singleton;

/**
 * A problem of singleton pattern is that unit testing it is difficult.
 * Suppose in Java, we create a JUnit method to test a singleton. The method
 * runs, terminates, but then there's another method that wants to work
 * on the singleton. Now, because we have instantiated the singleton and it
 * is shared in the class (after all a test class is a class, and not some magical
 * class where if we write a method, it will open and close all the resource 
 * on the program!), we have the singleton instantiated in another method, but
 * it's being used in another. Especially if the singleton is stateless, we get
 * into trouble. This goes to show you how essential interfaces are!
 * 
 * Now, one solution to this is to define an interface for the singleton. Then for each
 * test, we can implement that interface (or other possibilites). 
 */
