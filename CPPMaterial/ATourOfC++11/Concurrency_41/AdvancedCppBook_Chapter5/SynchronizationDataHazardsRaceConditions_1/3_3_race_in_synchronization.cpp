/**
* Even under event race conditions race can occur, but this would be mostly due to a flawed interface of the class.
* 
* Consider for example the following Messages class.
* 
* Here, we have a class called Messages that has a dynamically allocated array of strings. In the constructor, it takes 
* the size of the array and creates an array of the given size. It has a function, full(), that returns true if the array 
* is full and false otherwise. It also has an empty() function that returns true if the array is empty and false otherwise. 
* It is the user's responsibility to check if the array is full before pushing a new value and checking if the array is 
* empty, and before popping a new value from the array. This is an example of a poor interface of the class that leads to 
* race conditions.
* 
* Even if we protect the push() and pop() functions with locks, race conditions will not disappear, which is what we've
* done in the function cause_race.
* 
* As we can see in this function, one thread is constantly writing to the queue, and one is constantly reading. This is a
* receipe for disaster. For one thing, we may read from messages, because the other thread has not had the chance to reset
* the number of messages. We may also write, despite the fact the other thread is not yet finished popping the messages.
* Effectively, one of the threads can check the array's size and can be interrupted by the OS. At this time, another 
* thread can change the array. When the first thread continues its work, it can try to push to the full array or pop from 
* the empty array. So, synchronization is only effective in a pair with a good design.
*/
#include <string>
#include <thread>
#include <iostream>

class Messages
{
public:
    Messages(const int& size) : ArraySize(size), currentIdx(0), msgArray(new std::string[ArraySize])
    {}

    void push(const std::string& msg)
    {
        msgArray[currentIdx++] = msg;
    }

    std::string pop()
    {
        auto msg = msgArray[currentIdx - 1];

        msgArray[currentIdx - 1] = "";
        --currentIdx;
        return msg;
    }

    bool full()
    {
        return ArraySize == currentIdx;
    }

    bool empty()
    {
        return 0 == currentIdx;
    }

private:

    const int ArraySize;
    int currentIdx;
    std::string* msgArray;
};

void cause_race() {
    Messages msgs(10);

    std::thread thr1([&msgs](){
		while(true)
		{
			if (!msgs.full())
			{
				msgs.push("Hello");
			} else
			{
				break;
			}

		}});

    std::thread thr2([&msgs](){
		while(true)
		{
			if (!msgs.empty())
			{
				std::cout << msgs.pop() << std::endl;
			} else
			{
				break;
            }
        }});

    thr1.detach();
    thr2.detach();

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
}