/**
* Consider the following generations of a template. Also note that we can't use constexpr inside
* the template, but we can use constant expressions apparently.
* 
* When we use the same set of arguments, we have the same type. But what does "the same" mean here?
* Aliases don't introduce new types, hence string<Uchar>, string<uchar> are the same. However, char
* and unsigned char are not the same types, hence produce different types.
* 
*/
template <typename T>
struct string{

};

template <typename T, int SIZE>
struct Buffer {

};

constexpr int constexpr_calc(int i) {
	return i * 2;
}

void initializing_templates() {
	string<char> s;
	string<unsigned char> s1;

	using Uchar = unsigned char;
	using uchar = unsigned char;

	string<Uchar> s4;
	string<uchar> s5;

	Buffer<string<Uchar>, 10> c1;
	Buffer<string<Uchar>, 10 - 2> c2;
	Buffer<string<Uchar>, constexpr_calc(20)> c3;

}