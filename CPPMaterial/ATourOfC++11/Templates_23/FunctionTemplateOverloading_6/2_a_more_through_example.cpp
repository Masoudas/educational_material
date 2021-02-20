/**
* Pay special attention to the last one. The problem with the last two calls is that we don’t apply promotions 
* and standard conversions UNTIL AFTER template parameters have been uniquely determined
* There is no rule telling the compiler to prefer one resolution over the other. In most cases, 
* it is probably good that the language rules leave subtle decisions in the hands of the programmer
*/

template<typename T>
T max(T, T) { return T{}; };

const int s = 7;

void k()
{
	max(1, 2); // max<int>(1,2)
	max('a', 'b'); // max<char>(’a’,’b’)
	max(2.7, 4.9); // max<double>(2.7,4.9)
	max(s, 7); // max<int>(int{s},7) (trivial conversion used)
	//max('a', 1); // error : ambiguous: max<char,char>() or max<int,int>()?
	//max(2.7, 4); // error : ambiguous: max<double,double>() or max<int,int>()?
}