/**
* From the standard, we have the following documentation:
* 
* The class lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex 
* for the duration of a scoped block.
* 
* When a lock_guard object is created, it attempts to take ownership of the mutex it is given. When control 
* leaves the scope in which the lock_guard object was created, the lock_guard is destructed and the mutex is 
* released.
* 
* The lock_guard class is non-copyable.
* 
* Notes: std::scoped_lock offers a replacement for lock_guard that provides the ability to lock multiple 
* mutexes using a deadlock avoidance algorithm.
* 
* Template parameters
*	-	Mutex	-	the type of the mutex to lock. The type must meet the BasicLockable requirements
* 
* Note also the constructor:
*   -   lock_guard( mutex_type& m, std::adopt_lock_t t );
* which acquires the ownership of the mutex without trying to lock it.
*/

#include <thread>
#include <mutex>
#include <iostream>
 
int g_i = 0;
std::mutex g_i_mutex;  // protects g_i
 
void safe_increment()
{
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;
 
    std::cout << "g_i: " << g_i << "; in thread #"
              << std::this_thread::get_id() << '\n';
 
    // g_i_mutex is automatically released when lock goes out of scope
}
 
void test_lock_guard()
{
    std::cout << "g_i: " << g_i << "; in main()\n";
 
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);
 
    t1.join();
    t2.join();
 
    std::cout << "g_i: " << g_i << "; in main()\n";
}