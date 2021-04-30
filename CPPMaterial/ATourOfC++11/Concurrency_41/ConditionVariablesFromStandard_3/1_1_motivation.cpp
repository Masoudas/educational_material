/**
* Me: Often, we want to signal to a thread to start execution after a shared variable has been written to, 
* or some condition has changed. Normally, I used to think that this can be achieved using a while loop,
* but a more sophisticated way is to use condition_variable. Condition variable, always with the help of
* a lock, blocks the execution of a thread. The thread restarts only once the condition variable has been
* safely set (from another thread.) Hence, condition variables are just to way to fascilitate inter communcation
* among threads.
* 
* One thing to note is that the problem with the while approach is that the thread would always be working,
* which is not a very good idea. With condition_variables, the condition is checked periodically.
* 
* Objects of type condition_variable always use unique_lock<mutex> to wait: for an alternative that works 
* with any kind of lockable type, see condition_variable_any
* 
* The following is the simplest example one can think of. Note that all threads reach the print_id method,
* however, none can proceed, because the wait condition is false for all of them (it's the while loop
* condition essentially.) So as soon as we set the condition to true, then we allow the wait condition to
* be broken. Hence, the first threads to see this, wakes up, locks, and then executes the code. This 
* goes to the end, lock is destroyed (or unlocked,) which allows the next thread to just execute. This
* goes until all threads are done.
* 
* Question: What happens if instead of notifying all, we notify one? Then only one thread wakes up and
* finishes the job. But then again, all the other threads would remain sleep, and this program goes on
* forever. Whereas when we notify all, then all threads have woken up, and they don't go back to sleep,
* unless we do so.
* 
* We use the notify_all method below. There's a notify_one method, which notifies just one thread.
*/

// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex my_mtx;
std::condition_variable cv;
bool ready = false;

void print_id (int id) {
  std::unique_lock<std::mutex> lck(my_mtx);

  std::cout << "thread" << id << " is here but is waiting\n";
  cv.wait(lck, [] { return ready; });
  // ...
  std::cout << "thread " << id << '\n';
}

void go() {
  std::unique_lock<std::mutex> lck(my_mtx);
  ready = true;
  cv.notify_all();
}

void creating_threads()
{
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print_id,i);

  std::cout << "10 threads ready to race...\n";
  std::this_thread::sleep_for(std::chrono::seconds(3));
  go();                       // go!

  for (auto& th : threads) th.join();
}

//int main() {
//    creating_threads();
//}