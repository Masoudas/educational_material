/** This is all me:
* As always, C++ takes things to another level. This I think due to the C++ implementation of templates,
* generating a member only when needed. Hence, a static member of the template can be generated. As we 
* see in the following example, the int type static is independent of string type template!
* 
* This does make sense when we compare it to 0_2. Every template in and of itself creates a new
* class in memory, hence, an static of one type is independent from other types!
* 
* Of course, we can provide static methods with templates. This we can surmise is like a normal
* outside the class method that has templates. Hence, it will simply replaced at run-time.
*/
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct class_with_static_template
{
public:
	static T val;
	void f(T t) {}
};

int class_with_static_template<int>::val = 10;
string class_with_static_template<string>::val = "My default string";


//int main() {
//	class_with_static_template<string> c1{};
//	class_with_static_template<int> c2{};
//
//	cout << c1.val << endl;
//	cout << c2.val << endl;
//	
//	c2.f(int{});
//	c1.f(string{});
//}


