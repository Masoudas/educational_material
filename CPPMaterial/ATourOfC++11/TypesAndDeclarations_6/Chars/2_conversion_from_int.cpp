/**
* Note that case from int to char is also possible, because chars are still integer types. That is, we often
* tend to initialize chars with int literals, saying char c = 10. Therefore, a static_cast is considered safe
* here, or we could just directly work with ints.
* 
* The character literal '0' is converted to its integer value and is added.  
* The resulting int is then converted to a char and written to cout.  
* Plain '0'+i is an int, so if I had left out the static_cast<char>, the output would have been something like 
* 48,49,and so on, rather than 0,1, and so on.
*/

#include <iostream>

void digits(){
	using namespace std;
	for (int i = 0; i != 10; ++i) {
		cout << static_cast<char>('0' + i);	// Converting int to char using static_cast
		// Me: Equivalently:
		//char c = '0' + i;
		//cout << c;
	}
}

//int main() {
//	digits();
//}
