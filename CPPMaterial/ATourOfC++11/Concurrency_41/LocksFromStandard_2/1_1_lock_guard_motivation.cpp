/**
* This is me:
* 
* Apparently, what lock_guard does is simply to ensure that no matter what happens, even if an exception is
* thrown, when we reach the end of a block in which a lock_guard has been defined, the lock is unlocked!
* 
* This apparently is very important, because in the case of having an exception, the lock may not be released.
* 
* Of course, because the lock is released at the end of a block, we need to have brackets in the middle of 
* the code, indicating release of lock (Ok! So that's why they define those blocks in the middle of multi-threaded
* code.)
* 
* Note however that lock_guard is in no way responsible for destruction of the lock object itself. It just
* unlocks it.
* 
* Note: Try using the following code with lock and unlock, and you'll see that because we don't reach the
* unlock part, the code freezes, FOREVER! This is because we remain in a state of eternal lock.
*/

#include <mutex>
#include <thread>
#include <iostream>

// lock_guard example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard
#include <stdexcept>      // std::logic_error

std::mutex mtx;

void print_even(int x) {
    if (x % 2 == 0) std::cout << x << " is even\n";
    else throw (std::logic_error("not even"));
}

void print_thread_id(int id) {
    // Do some stuff here
    {
        try {
            // using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
            std::lock_guard<std::mutex> lck(mtx);
            //mtx.lock();
            print_even(id);
            // mtx.unlock();
        }
        catch (std::logic_error&) {
            std::cout << "[exception caught]\n";
        }
    }
    // Do other stuff here.
}

void using_mutex_lock_in_print_thread()
{
    std::thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_thread_id, i + 1);

    for (auto& th : threads) th.join();
}
