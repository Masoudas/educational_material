/**
* We can sort a user-defined type by providing a comparison function pointer to it.
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct User {
	const char* name;
	const char* id;
	int dept;
};

void print_id(User (&v)[6])
{
	for (auto& x : v)
		cout << x.name << '\t' << x.id << '\t' << x.dept << '\n';
}

void sort_user_defined_type_with_qsort() {
	// Question: are these objects stored in the stack or in the heap? It must be stack. We didn't use new.
	// So initializer list just copies the stuff in the underlying vector.
	User heads[] = {
		{"Ritchie D.M.", "dmr", 11271},
		{"Sethi R.", "ravi", 11272},
		{"Szymanski T.G.", "tgs", 11273},
		{"Schr yer N.L.", "nls", 11274},
		{"Schr yer N.L.", "nls", 11275},
		{"Kernighan B.W.", "bwk", 11276}
	};

	auto cmp1 = [](const void* p, const void* q)->int
	{
		return strcmp(static_cast<const User*>(p)->name, static_cast<const User*>(q)->name);
	};

	auto cmp2 = [](const void* p, const void* q)->int
	{
		return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
	};

	cout << "Heads in alphabetical order:\n";
	qsort(heads, 6, sizeof(User), cmp1);
	print_id(heads);
	cout << '\n';
	cout << "Heads in order of department number:\n";
	qsort(heads, 6, sizeof(User), cmp2);
	print_id(heads);

}

//int main()
//{
//	sort_user_defined_type_with_qsort();
//}
