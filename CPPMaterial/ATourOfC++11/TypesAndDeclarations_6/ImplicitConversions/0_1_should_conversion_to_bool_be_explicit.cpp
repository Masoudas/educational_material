/**
* Here's a question, particularly based on 7 of this section.
* 
* We know that conversion from int to bool is implicit, 0 is false, and all other values are true, and vice
* versa. So, imagine I have a conversion to bool operator for some class S which is not explicit:

S::operator bool(){...}

* Now, when if I write for example:

if (int x = s){...}

* it does compile. because a bool can implicitly convert to int. Hence, even the following code is possible:

s << 1;

* Why? Because operator << even though not defined on s, is defined for int. Hence, operator<<(int) is a 
* valid left shift operator. Hence, to avoid this problem, we better define conversion to bool or I guess
* all primitive types as explicit.
*/