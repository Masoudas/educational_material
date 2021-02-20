/**
* Simply declaring a base class is insufficent, as the derived class needs to know the memory map of the base class.
* In fact, Bjarne says 'Using a class as a base is equivalent to defining an (unnamed) object of that class. 
* Consequently, a class must be defined in order to be used as a base'
*/

class Employee; // declaration only, no definition
//class Manager : public Employee { // error : Employee not defined
//};