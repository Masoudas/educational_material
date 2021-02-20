/**
* When the return type of the lambda is void, we can drop the -> void, and the compiler deduces it to be
* void. Hence, [](){} is equivalent to []()->void{}.
* 
* If the lambda has no arguments, we can drop the paranthesis too. Hence, we can say []{} = [](){}.
*/