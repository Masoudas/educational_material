#include <memory>
#include <sstream>
#include <iostream>

/*
* Exercise: Create a dynamic array that holds any data type. Then create an student structure containing
* name and class and put it there. Add to_string to the data structure as well. Hence, student should implement
* an outstream operator as well.
* 
* Note that as the master once said, presence of pointer in the class implies overriding copy constructor.
* A couple of other points:
* 
* 1- First, note that for each accessor method, there's a corresponding const ... f(...) const version.
* 2- The end method as always returns one element right after the last element of the container.
* 3- Why declare operator+ as friend? It's kind of interesting. Because with the way the function is defined,
*	it has to be an stand-alone outside class operator (it has two inputs). However, defining it as friend
*	allow us to attach it to the scope. Interesting!
* 4- Note the use of ostreamstring for creating an stream of strings. Apparently, we prefer not to use 
*	the plus operator of basic_string. Perhaps, this is some form of string builder. Specially, given that
*	I can't think of an obvious way of converting an integer to string.
* 5- Note also the use of ostream, which is just an output stream in general.
* 6- Notice that it's better to use std::copy over std::memcpy, given that it does not require the
*	character size of elements.
* 
*/
template <typename T>
class dynamic_array {
	using Type = T;
	using _Tp = T*;

	int N = 0;
	_Tp data;

public:
	dynamic_array(int n) : N{n} {
		data = new T[N]{};
	}

	dynamic_array(const dynamic_array& other) : N{ other.N } {
		data = new T[N];
		std::copy(other.begin(), other.end(), data);
	}

	T& operator[](int n) {
		return data[n];
	}

	const T& operator[](int index) const {
		return data[index];
	}

	T& at(int index){
		if (index < N)
			return data[index];
		throw "Index out of range";
	}

	T* begin() noexcept {
		return data;
	}

	const T* begin() const noexcept {
		return data;
	}

	T* end() noexcept {
		return data + N;
	}

	const T* end() const noexcept {
		return data + N;
	}

	int size() const noexcept { return N; }

	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size() + arr2.size());
		std::copy(arr1.begin(), arr1.end(), result.begin());
		std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
		return result;
	}

	std::string to_string(const std::string& sep = ", ") {
		if (N == 0) return "";

		std::ostringstream os{};
		os << data[0];

		for (int i = 1; i < N; i++) {
			os << sep << data[i];
		}

		return os.str();
	}

	~dynamic_array() {
		delete[] data;
	}
};

struct student
{
	std::string name;
	int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
	
	return (os << "[Name: " << s.name << ", Standard: " << s.standard << "]");
}

//int main()
//{
//	int nStudents;
//	std::cout << "Enter number of students in class 1: ";
//	std::cin >> nStudents;
//	dynamic_array<student> class1(nStudents);
//	for (int i = 0; i < nStudents; i++)
//	{
//		std::cout << "Enter name and class of student " << i + 1 << ": ";
//		std::string name;
//		int standard;
//		std::cin >> name >> standard;
//		class1[i] = student{ name, standard };
//	}
//	// Now, let's try to access the student out of range in the array
//	try
//	{
//		class1.at(nStudents) = student{ "John", 8 };  // Will throw exception
//	}
//	catch (...)
//	{
//		std::cout << "Exception caught" << std::endl;
//	}
//
//	auto class2 = class1;  // Deep copy
//	std::cout << "Second class after initialized using first array: " << class2.to_string() << std::endl;
//
//	auto class3 = class1 + class2; // Combines both classes and creates a bigger one
//	std::cout << "Combined class: ";
//	std::cout << class3.to_string() << std::endl;
//	return 0;
//}