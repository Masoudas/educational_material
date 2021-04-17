/**
* So now the question has come down writing a type_function that would return false if the type is a particular
* class. There are two classes in std called true_type and false_type, for which ::type returns true or false,
* respectively. We can define our specialization to inherit from false. I know that this is complicating it a
* little bit, but this is how the big guy does it.
* Notice that the parameter 'type' is overwritten by false_type. That is at the point of specialization, we
* inherit from both true_type and false_type. However, I guess because false_type is that last explicit
* inheritance, we bring it forward.

struct substitution_failure { }; // represent a failure to declare something

template<typename T>
struct substitution_succeeded : std::true_type	{ };

template<>
struct substitution_succeeded<substitution_failure> : std::false_type
{ };

*/