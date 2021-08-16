/**
 * Question is, can we define class members const? Yes we can. However, we can't modify them using constructors, 
 * or any other function for that matter. This is because memory space is declared with class memory instantiation.
 * Hence, it can't be modified with constructors.
 *
 * Me: Note that we CAN'T change the value of const member classes, unless we use const_cast. Later on, we shall
 * learn that we can change class memebers inside const methods, but that's a totally separate thing. So, don't
 * confuse the two. Only a const_cast allows one to change const entities, class member or not.
 */