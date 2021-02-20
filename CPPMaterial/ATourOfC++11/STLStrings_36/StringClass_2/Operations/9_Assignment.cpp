/*
* For startes, an assignment creates a new copy of the string, independent of the source.
* 
* Assigning a c-style string to a string completely changes the content of the string to the
* new string.
*/

#include <string>
using namespace std;
void assigning_strings(){
	string str1 = "S1";
	string str2 = "S2";

	str1 = str2;	// This would be a copy of str2;
	str2 = "S3";	// This changes str2 to S3, but does not change str1

}