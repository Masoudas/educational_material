/**
* me: Essentially, deadlock is like two cars are at the junction, and either both of them want to move forward, or both
* of them want to go back. 
* 
* Let's go back to the philosophers' dinner example. The original issue was that one philosopher has only one chopstick. 
* So, they can eat their sushi one by one by sharing chopsticks with each other. Although it will take a long time for them 
* to finish their sushi, all of them will be well-fed. But if each of them grabs a chopstick at the same time and doesn't 
* want to share the second chopstick, they won't be able to eat their sushi as each of them will be waiting for the second 
* chopstick forever. This leads to a deadlock.
* 
* This happens when two threads are waiting for another thread to continue its job.
* 
* One of the causes of deadlocks is when one thread joins another thread, but another thread joins the first thread. So, 
* when both threads are joined to each other, none of them can continue their job. Let's consider the following example 
* of a deadloc (me: just as we expect, the example is bizzare, and we pass pointers of threads to one another.
* 
* Note that it's interesting that the deadlock does not cause the program to run forever, rather, it terminates abruptly
* with an error. I think this does make sense, because the OS is able to see what's going on underneath and one thread
* is trying to join another illegally, which is why it throws an error.
*/

#include <thread>

std::thread* thr1;
std::thread* thr2;

void someStuff()
{
    thr1->join();
}

void someAnotherStuff()
{
    thr2->join();
}

void deadlock_two_threads()
{
    std::thread t1(someStuff);
    std::thread t2(someAnotherStuff);

    thr1 = &t1;
    thr2 = &t2;

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
}

//int main() {
//    deadlock_two_threads();
//}