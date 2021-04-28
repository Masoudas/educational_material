/**
 * One thing that I need to pay attention is that mutexes can only be used inside a function (after all, they're
 * just an algorithm, so putting them around say a class field makes no sense whatsoever!)
 * 
 * Consequently, the only thing mutexes do is that they don control execution order of part of the function. In
 * that sense, we can't make a resource atomic with them!
 * 
 * To illustrate this point, in the example below, I first lock part of the function. Then inside that locked
 * part, first I set a flag. This flag releases the main thread to write to the shared data! As a consequence,
 * even though the critical section of the function is locked, the shared data is changed.
 * 
 * Hence, don't confuse mutexes with atomic data.
 * 
 *
 */
#include <mutex>
#include <thread>
#include <iostream>

bool flag = false;
int arr[] = {1, 2, 3, 4};

std::mutex arr_mx;

void change_vector(){
    using namespace std::chrono_literals;

    arr_mx.lock();
    flag = true;
    std::this_thread::sleep_for(100ms);
    std::cout << arr[0] << '\n';

    arr[0]++;
    arr_mx.unlock();    
}

//int main(){
//    using namespace std::chrono_literals;
//    
//    std::thread t{change_vector};
//
//    t.detach();
//    while( !flag); 
//    arr[0] = 1000;  // This is being set here. I
//
//    std::this_thread::sleep_for(1s);
//    std::cout << arr[0];
//}