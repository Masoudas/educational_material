/**
* The MSVC website mentions the following use cases for enable_if:
* 
* In C++, substitution failure of template parameters is not an error in itself-this is referred to as SFINAE 
* (substitution failure is not an error). Typically, enable_if is used to remove candidates from overload resolution—that 
* is, it culls the overload set-so that one definition can be rejected in favor of another. This conforms to SFINAE 
* behavior.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
* Scenario 1: Wrapping the return type of a function:

template <your_stuff>
enable_if_t<your_condition, your_return_type>
yourfunction(args) {}

* Scenario 2: Adding a function parameter that has a default argument (me: Doesn't mean removes the argument. Removes the
entire defintion of functions as the big guy says. Also note that FOO is a type, not a template:)

template <your_stuff>
your_return_type_if_present
    yourfunction(args, enable_if_t<your condition, FOO> = BAR) {}

* Scenario 3: Adding a template parameter that has a default argument (me: again, removes the entire function:)

template <your_stuff, typename Dummy = enable_if_t<your_condition>>
rest_of_function_declaration_goes_here

* Scenario 4: If your function has a non-templated argument, you can wrap its type (me: yes, removes the entire function:)

template <typename T>
void your_function(const T& t, enable_if_t<is_something<T>::value, const string&>s) {}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

* Scenario 1 doesn't work with constructors and conversion operators because they don't have return types.
* 
* Scenario 2 leaves the parameter unnamed. You could say ::type Dummy = BAR, but the name Dummy is irrelevant, and giving 
* it a name is likely to trigger an "unreferenced parameter" warning. You have to choose a FOO function parameter type and 
* BAR default argument. You could say int and 0, but then users of your code could accidentally pass to the function an 
* extra integer that would be ignored. Instead, we recommend that you use void ** and either 0 or nullptr because almost 
* nothing is convertible to void **:

template <your_stuff>
your_return_type_if_present
yourfunction(args, typename enable_if<your_condition, void **>::type = nullptr) {// ...
}

* (me: in other words, we're not using that last parameter. We're just putting it there as a check to enable)
* 
* Scenario 3 uses the name Dummy, but it's optional. Just " typename = typename" would work, but if you think that looks 
* weird, you can use a "dummy" name—just don't use one that might also be used in the function definition. If you don't 
* give a type to enable_if, it defaults to void, and that's perfectly reasonable because you don't care what Dummy is. 
* This works for everything, including conversion operators and variadic constructors.
* 
* Scenario 4 works in constructors that don't have return types, and thereby solves the wrapping limitation of Scenario 1. 
* However, Scenario 4 is limited to non-templated function arguments, which aren't always available. (Using Scenario 4 on 
* a templated function argument prevents template argument deduction from working on it.)
*/
