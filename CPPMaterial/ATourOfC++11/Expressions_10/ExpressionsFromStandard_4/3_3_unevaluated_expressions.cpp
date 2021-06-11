/**
* Me: Some expressions are computed at compile time, and as such they have no run-time effect. Although I must admit they
* must be quite exotic. For example something like "cout << sizeof(42)" is calculated at compile time, but the result has
* run-time implication. However, something like "sizeof(cout << 42)" has no run-time effect (recall that operator<< actually
* returns, and we calculate its size at compile time!)
* 
* The operands of the operators typeid, sizeof, noexcept, and decltype (since C++11) are expressions that are not evaluated 
* (unless they are polymorphic glvalues and are the operands of typeid), since these operators only query the compile-time 
* properties of their operands. Thus, std::size_t n = sizeof(std::cout << 42); does not perform console output.
* 
* The unevaluated operands are considered to be full expressions even though they are syntactically operands in a larger 
* expression (for example, this means that sizeof(T()) requires an accessible T::~T) (since C++14)
* The requires-expressions are also unevaluated expressions. (since C++20)
*/