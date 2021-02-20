/**
 * Conversion from for example double to int is implicit in C++. However, sometimes we need
 * explicit ones.
* There are several forms of conversion available. They're ordered  in terms of safety.
1- Construction, using the {} notation, providing type-safe construction of new values.
2- const_cast for getting write access to constant variables.
3- static_cast for reversing a well-defined implicit conversion.
4- reinterpret_cast for changing the meaning of bit patterns.
5- dynamic_cast for dynamically checked class hierarchy navigation.
6- C style cast, which is just type name before the type to be casted. No compile time checks
are done here.
7- Functional notation, providing a different notation for C-style casts

As we can see, c-style cast comes at the very buttom of the list. Hence, it should be avoided.

For narrowing casts, Bjarne prefers using a home-made conversion. What this does is that it casts,
then it casts back to check and see if the two values are equal.


template<class Target, class Source>
Target narrow_cast(Source v)
{
	auto r = static_cast<Target>(v); // convert the value to the target type
	if (static_cast<Source>(r)!=v) throw runtime_error("narrow_cast<>() failed");
	return r;
}

This apparently is a generalization of the rules applied by the language.

void test(double d, int i, char* p)
{
	auto c1 = narrow_cast<char>(64);
	auto c2 = narrow_cast<char>(-64); // will throw if chars are unsigned
	auto c3 = narrow_cast<char>(264); // will throw if chars are 8-bit and signed
	auto d1 = narrow_cast<double>(1/3.0F); // OK
	auto f1 = narrow_cast<float>(1/3.0); // will probably throw
	auto c4 = narrow_cast<char>(i); // may throw
	auto f2 = narrow_cast<float>(d); // may throw
	auto p1 = narrow_cast<char*>(i); // compile-time error
	auto i1 = narrow_cast<int>(p); // compile-time error
	auto d2 = narrow_cast<double>(i); // may throw (but probably will not)
	auto i2 = narrow_cast<int>(d); // may throw
}

As we already know, for float types, it's best to use a range test.
*/



