/**
 * for (auto x : v);
 * 
 * As we normally expect for such loops, for a collection T[] we want it to return every T.
 * The expression after the colon in for range must be a range. Hence, it must have a 
 * v.begin(), v.end() to obtain an iterator.
 * 
 * The compiler first looks for begin and end. If it sees that they're not a function (
 * for example are just variables), it throws an error. If this is not the case, the compiler
 * looks for begin and end in that scope, and if does not find one (for example because
 * because begin does not take an argument of its type), it returns an error.
 * 
 * The compiler uses v and v + N for a built in array of T v[N]. Hence, we could say it uses
 * the pointer to access the values.
 * 
 * The <iterator> header provides begin(c) and end(c) for built-in arrays and for all 
 * standard-library containers.
 * 
 * As always, don't forget that elements are copied in the for loop (at least for the first one.
 * The second one? I guess v is initialized, hence just an assignment). Hence, it might be better
 * to use references here.
 * 
 * This is very elegeant when asking for variables from a user for example:
 * for (string s; cin>>s;)
 *        v.push_back(s);
 * 
 * 
 */

void for_range_gets_the_content() {
	int arr[] = { 1, 2, 3, 4 };

	for (int var : arr)
	{
		// For each, we use arr + i, and then access it using *. We use start because
		// remember, we want to access the collection type, which is int, not int*. And 
		// don't delete this point in the future!!!
	}
}

/*
* When using reference, a for range loop does the equivalent of T& = (*ptr).
*/
void for_range_when_using_reference() {
	int arr[] = { 1, 2, 3, 4, 5 };

	// This is equivalent to for (int& val : arr)
	for (int i = 0; i < 5; i++)
	{
		int& val = *(arr + i);
	}
}