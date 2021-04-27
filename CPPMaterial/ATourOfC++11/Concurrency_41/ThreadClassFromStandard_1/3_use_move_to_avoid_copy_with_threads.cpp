/**
* One thing that we should not forget about functions that don't accept references (rather uncv qualified types) is that
* if we wanted to, we could still use move semantics to move objects to them and avoid a copy. That is if we have:

template<typename T>
void f(T t);

* The writing f(move(t)) would move an instance t, nullifying it for us. Recall that writing T t = static_cas<T&&>(t1)
* implies using move semantics.
* 
* Anyways, use move semantics to nullify objects that you pass to threads if needed.
* 
* Note that the same argument applies if we try to pass a functor as well. For example, if it doesn't have a copy ctor,
* the only way we can pass that object is to move it, otherwise we get a compile-time error.
* 
* Finally, note that with lambdas, it's possible to capture objects with move semantics! That is, we can write:

std::thread convertThread([ unique = std::move(unique) ] {	// Captured, but using move semantics to move the unique
															// object.
        unique->operator()("convert me");
});

*/

#include <iostream>
#include <thread>

class Handler
{
public:
	Handler()
	{
		std::cout << "Handler()" << std::endl;
	}

	Handler(const Handler&)
	{
		std::cout << "Handler(const Handler&)" << std::endl;
	}

	Handler& operator=(const Handler&)
	{
		std::cout << "Handler& operator=(const Handler&)" << std::endl;
		return *this;
	}

	Handler(Handler&& obj) noexcept
	{
		std::cout << "Handler(Handler && obj)" << std::endl;
	}

	Handler& operator=(Handler&& obj) noexcept
	{
		std::cout << "Handler & operator=(Handler && obj)" << std::endl;
		return *this;
	}

	~Handler()
	{
		std::cout << "~Handler()" << std::endl;
	}
};

void doSomeJob(Handler&& h)
{
    std::cout << "I'm here" << std::endl;
}

void passing_by_move() {
	Handler handler{};
	std::thread thr1(doSomeJob, std::move(handler));

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(5s);
}

// int main(){
//
// }
