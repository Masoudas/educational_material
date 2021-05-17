/**
* It's the programmer's responsiblity to ensure that data-races don't occur:
int a[] = {0, 1};
vector<string> v{};
std::for_each(std::execution::parallel, std::begin(a), std::(b), [](int a){
	v.push_back("");	// Data race
});

std::atomic<int> x{0};
int a[] = {1,2};
std::for_each(std::execution::par, std::begin(a), std::end(a), [&](int) {
  x.fetch_add(1, std::memory_order_relaxed);
  while (x.load(std::memory_order_relaxed) == 1) { } // Error: assumes execution order
});

int x = 0;
std::mutex m;
int a[] = {1,2};
std::for_each(std::execution::par, std::begin(a), std::end(a), [&](int) {
  std::lock_guard<std::mutex> guard(m);
  ++x; // correct
});

*
*/
