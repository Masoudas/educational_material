/**
* We can recast pointer to functions to a different type. Why would someone need it though?
* It should also be pointed out that VS does not allow this!
*/

using fp_1 = void(int, int);
using fp_2 = void();

void casting_fptr_using_interpret_cast(fp_1 f1) {
	//fp_2 f2 = reinterpret_cast<fp_2>(f1);
}