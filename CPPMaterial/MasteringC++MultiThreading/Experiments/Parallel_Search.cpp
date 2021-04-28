/**
 * We shall show that so long as all the threads are not reading and writing the same part of the memory, we 
 * can access a resource with no problem.
 * 
 * In the following example, we implement a search algorithm as such, which dispatches work among several threads
 * 
 * There are at least two problems associated with this implementation:
 *  -   Each thread that has a miss will continue searching, even if other threads have found the value. I don't
 *      actually know if using hadoop loops help with this or not.
 *  -   We join each thread, which is not a big deal, because every thread terminates simultaneously. Therefore,
 *      when we join the other threads, they're finished.
 *  -   I compared it with std::find and the differences are in the order of 10 to 20 percent.
 */
#include <iostream>
#include <iterator>
#include <thread>
#include <vector>
#include <algorithm>

template<typename Itr, typename Val>
void my_find(Itr begin, Itr end, Val val){
    while( begin != end && *begin != val) ++begin;

    if (begin != end) std::cout << "Found the value " << *begin << "\n";
}


// Create three threads.
template<typename Itr, typename Val>
void parallel_search(Itr begin, Itr end, const Val& val){
    size_t N = std::distance(begin, end);

    std::vector<std::thread> thrds{};

    auto first = begin;
    auto last = begin;
    for (int i = 0; i < N; i+=N/4)
    {
        if ( (i + N / 4) > N){
             last = end; 
        }
        else std::advance(last, N/4);     

        thrds.push_back(std::thread{my_find<Itr, Val>, first, last, std::ref(val)});   // Didn't know we need to
                                                                                    // specify templates here!
        first = last;
    }

    for (auto &&thrd : thrds)
    {
        thrd.detach();   
    }

}

//int main(){
//    std::vector<int> v(100023, 1);
//    v[1]= 100;
//    v[100022] = 2;
//
//    auto start_p = std::chrono::steady_clock::now();
//    parallel_search(v.begin(), v.end(), 2);
//    auto end_p = std::chrono::steady_clock::now();
//    
//    auto start_s = std::chrono::steady_clock::now();
//    my_find(v.begin(), v.end(), 2);
//    auto end_s = std::chrono::steady_clock::now();
//
//    std::cout << "The parallel version takes " << std::chrono::duration_cast<std::chrono::microseconds>(
//        end_p - start_p).count() << " and the single thread version takes " << 
//        std::chrono::duration_cast<std::chrono::microseconds>(end_s - start_s).count() << " milli-seconds";
//}