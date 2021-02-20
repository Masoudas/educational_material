/**
* Even more interestingly, variable templates can be specialized too. This can be both a typed template, or
* a valued template.
* 
* In the following example, we generate the Fibonacci sequence using a specialized variable template.
* That being said, the following does not work in MSVC.
*/


//typename<int Value>
//constexpr auto fibonacci = fibonacci<Value - 1> +fibonacci<Value - 2>;
//
//typename<>
//constexpr auto fibonacci<0> = 0;
//
//typename<>
//constexpr auto fibonacci<1> = 0;