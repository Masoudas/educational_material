/**
 */

#include <csignal>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <string>

using namespace std;

sig_atomic_t signal_caught = 0;
mutex log_mutex;

// Simply sets the signal.
void siginit_handler(int sig){
    signal_caught = 1;
}

void logFnc(string text){
    log_mutex.lock();
    std::cout << text << '\n';
    log_mutex.unlock();
}

int main(){
    signal(SIGINT, &siginit_handler);
    Dispatcher::init(10);

}