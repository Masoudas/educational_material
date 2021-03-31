/**
* Note that we have an id, and a get_id method.
* 
* id is a member class of thread. The standard says "The class thread::id is a lightweight, trivially copyable 
* class that serves as a unique identifier of std::thread objects. Instances of this class may also hold the 
* special distinct value that does not represent any thread. Once a thread has finished, the value of 
* std::thread::id may be reused by another thread.
* This class is designed for use as key in associative containers, both ordered and unordered."
* 
* Note that id has the spaceship <=> operator, hence can be checked for equality.
* 
* Returns a value of std::thread::id identifying the thread associated with *this. If there is no thread 
* associated, default constructed std::thread::id is returned. (Me: We can't check if a thread has terminated
* execution with this check. For example, and empty constructed thread is still joinable! We see that in the
* definition of joinable method, this check is done for just checking whether a thread is joinable!)
* std::thread has a member function called get_id() that returns the unique ID of the std::thread 
*  instance. If the std::thread instance wasn't initialized or was joined or detached, get_id() returns a default std::thread::id object
*/
//??????