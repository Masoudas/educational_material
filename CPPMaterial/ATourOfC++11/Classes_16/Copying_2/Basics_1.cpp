/**
 * Be default, every class defines a copy constructor. The following expressions uses that 
 * copy constructor to create a new object from old one:
 * 
 * class A{}
 * A a;
 * 
 * A a1 = a; // Copy, because a1 is not already initialized (see chapter _17, Copy constructor);
 * A a2{a}; // Again, using copy constructor
 * 
 */ 