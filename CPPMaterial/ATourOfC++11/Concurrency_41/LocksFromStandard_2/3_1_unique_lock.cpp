/**
* Me: Essentially, the unique_lock class allows us to do very interesting things with the lock, defer 
* locking, try locking for a certain period or until a period, and many other things. The standard says:
* 
* The class unique_lock is a general-purpose mutex ownership wrapper allowing deferred locking, 
* time-constrained attempts at locking, recursive locking, transfer of lock ownership, and use with 
* condition variables.
* 
* The class unique_lock is movable, but not copyable -- it meets the requirements of MoveConstructible and 
* MoveAssignable but not of CopyConstructible or CopyAssignable.
* 
* The class unique_lock meets the BasicLockable requirements. If Mutex meets the Lockable requirements, 
* unique_lock also meets the Lockable requirements (ex.: can be used in std::lock); if Mutex meets the 
* TimedLockable requirements, unique_lock also meets the TimedLockable requirements.
*/

#include <mutex>
#include <thread>
#include <chrono>
 
struct Box {
    explicit Box(int num) : num_things{num} {}
 
    int num_things;
    std::mutex m;
};
 
void transfer(Box &from, Box &to, int num)
{
    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);
 
    // lock both unique_locks without deadlock
    std::lock(lock1, lock2);
 
    from.num_things -= num;
    to.num_things += num;
 
    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
}
 
void making_the_threads()
{
    Box acc1(100);
    Box acc2(50);
 
    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);
 
    t1.join();
    t2.join();
}

