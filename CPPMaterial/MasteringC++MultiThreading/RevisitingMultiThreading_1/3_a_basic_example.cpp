/**
 * Consider the following example, where we safe-guard thread senstitive data using mutex. The thread and mutex 
 * includes are the core of our multithreaded application; they provide the basic means for creating threads, 
 * and allow for thread-safe interactions between them. 
 * 
 * The code is relatively easy to understand, apart from the random number generator. The static variable inside
 * the function is available on each call as we recall. The goal of the thread task is to read the value of the
 * first element of the vector, and then push back a new value based on what it containts.
 * 
 * Note that as each part of the method is released, other threads are able to access it. Hence, all threads
 * are executing the method simulatenously, it's that just one of them can execute a part of the method under
 * mutex, and others have to wait.
 * 
 * Regarding the randGen method, of note is the use of the thread_local keyword. What this means is that even 
 * though it is defined as a static variable, its scope will be limited to the thread using it. Every thread will 
 * thus create its own generator instance, which is important when using the random number API in the STL.
 * 
 * Me: Note that when we guard cout, NO OTHER THREAD CAN ACCESS IT IN THAT PART OF THE THREAD. But other threads
 * are able to access it from the outside possibly.
 * 
 * Me: Notice that every-time we use the threadFnc, we have to lock it on the current thread. Hence, the mutex 
 * must be defined globally, which is the best option. I guess we can define it as a stack variable too.
 * 
 * Me: Interestingly enough, I had to go through a fait bit of suffering to get this program not to act like it's
 * synchronized. In particular, I had to define a wait after the second print function. But I guaranty this to
 * you that on other platforms, without mutex it would print jibberish!
 */
#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <mutex>

using namespace std;

mutex values_mtx;
mutex cout_mtx;
vector<int> values;

int randGen(const int& min, const int& max) {
    static thread_local mt19937 generator(hash<thread::id>()(this_thread::get_id()));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void threadFnc(int tid) {
    cout_mtx.lock();    // Lock when we're here in this thread.
    cout << "Starting thread " << tid << ".\n";
    cout_mtx.unlock();  // Unlock it when we're finished. Must happen every time.


    values_mtx.lock();
    int val = values[0];
    values_mtx.unlock();

    int rval = randGen(0, 10);
    val += rval;

    cout_mtx.lock();
    cout << "Thread " << tid << " adding " << rval << ". New value: " << val << ".\n";
    cout_mtx.unlock();


    values_mtx.lock();
    values.push_back(val);
    values_mtx.unlock();
}

void multi_threaded_app(){
    values.push_back(42);

    thread tr1(threadFnc, 1);
    thread tr2(threadFnc, 2);
    thread tr3(threadFnc, 3);
    thread tr4(threadFnc, 4);

    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();

    cout << "Input: " << values[0] << ", Result 1: " << values[1] << ", Result 2: " << values[2] << ", Result 3: "
    << values[3] << ", Result 4: " << values[4] << "\n";

}

//int main(){ multi_threaded_app();}