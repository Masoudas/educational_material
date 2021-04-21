/**
* We're already with pair and tuple. The idea of tuple is to be able to do something as follows:

Tuple<double , int, char> x {1.1, 42, 'a'};
cout << x << "\n";
cout << get<1>(x) << "\n";

* In the following implementation, the big guy assumes the tuple has at most four parameters, and refrains
* from using variadic templates.
*/