/**
 * The queue structure is in the <queue> include of stl of the std namespace.
 * 
 * It provides the following functions:
 * empty() – Returns whether the queue is empty.
 * size() – Returns the size of the queue.
 * queue::swap() in C++ STL: Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
 * queue::emplace() in C++ STL: Insert a new element into the queue container, the new element is added to the end of the queue.
 * queue::front() and queue::back() in C++ STL– front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
 * push(g) and pop() – push() function adds the element ‘g’ at the end of the queue. pop() function deletes the first element of the queue.
 */
#include <queue>
#include <iostream>

void constructors();    // See below

using namespace std;
void using_FIFO_queue(){
    std::queue<int> queue{};
    queue.push(1);
    queue.push(2);

    std::cout << "The first element is " << queue.front() << std::endl;
    std::cout << "The last element is " << queue.back() << std::endl;
    
    queue.pop();
    std::cout << "After popping the first element is 2: " << queue.front() << std::endl;

    constructors();
}

/** Checking out the different constructors 
 * 
 * Most constructors allow for providing allocators. There's the traditional move and copy constructor as well. 
*/
std::queue<int> create_queue();

void constructors(){
   std::queue<int> queue{};
   queue.push(1);
    
   std::queue<int> queue1{queue};   // Using the copy constructor. Note that move constructor is called when there's 
                                    // an Rvalue involved. It's not like we can call the move constructor whenever we want;
   queue1.push(2); 
   
   std::cout << "The front element of the copied queue is: " << queue1.front() << std::endl;
   std::cout << "The front element of the copied queue is: " << queue.front() << std::endl;

   std::queue<int> queue2{create_queue()}; // Now here, we're using the move assignment, because there's an rvalue involved.
}

std::queue<int> create_queue(){
    std::queue<int>* queue = new std::queue<int>{};

    queue->push(3);

    return *queue;
}