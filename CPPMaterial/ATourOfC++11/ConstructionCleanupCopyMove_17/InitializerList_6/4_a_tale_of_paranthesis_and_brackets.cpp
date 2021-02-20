/* In what follows, we see the dramatic difference between using paranthesis and using brackets.

%%%%% ----------------------- Using Paranthesis ------------------------------ %%%%%
vector<double> v1(7); // OK: v1 has 7 elements; note: uses () rather than {}
vector<double> v2 = 9; // error : no conversion from int to vector
void f(const vector<double>&);
void g()
{
v1 = 9; // error : no conversion from int to vector
f(9); // error : no conversion from int to vector
}
%%%%% ----------------------- Using Paranthesis ------------------------------ %%%%%

%%%%% ----------------------- Using Brackets ------------------------------ %%%%%
vector<double> v1 {7}; // OK: v1 has one element (with the value 7)
vector<double> v2 = {9}; // OK: v2 has one element (with the value 9)
void f(const vector<double>&);
void g()
{
v1 = {9}; // OK: v1 now has one element (with the value 9)
f({9}); // OK: f is called with the list {9}
}
%%%%% ----------------------- Using Brackets ------------------------------ %%%%%

As we can see, because there's only an explicit method with single int, we get several errors
with the first example. All of those become meaningful when we use the initializer_list notion.
*/