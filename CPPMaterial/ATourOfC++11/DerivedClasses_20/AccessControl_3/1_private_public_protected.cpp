/**
* A member of the class can be public, private or protected:
* 
* -  If it is private, its name can be used only by member functions and friends of the class in which it is 
*	declared
* - If it is protected, its name can be used only by member functions and friends of the class in which it is 
*	declared and by member functions and friends of classes derived from this class
* - If it is public, its name can be used by any function.
* 
* This reflects the view that there are three kinds of functions accessing a class: functions implementing the 
* class (its friends and members), functions implementing a derived class (the derived class’s friends and members), 
* and other functions.
* 
* In a class, members are by default private; in a struct, members are by default public.
*/

