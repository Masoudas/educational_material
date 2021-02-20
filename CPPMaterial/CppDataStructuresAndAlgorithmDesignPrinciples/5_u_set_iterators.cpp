/**
* When it comes to iterators, we know that they do the normal operations we expect from such class. There are however
* two important points:
* 
* 1- We must not modify a set through its iterator.
* 2- We can't add integer steps to the iterator
* 
* The reason for these two observations is very obvious:
* It's very interesting to note that the iterator of an unordered_set is actually the const iterator of list. And this
* is exactly the point son. While you would have written an iterator interface for this class, the owner of the C++ 
* enterprise actually returns an already created iterator. In conclusion son, don't overdo things!
* 
* Now that we're here, we can actually take a look at the iterator for bucket. The begin and end functions both have
* an overload with size_t, which returns the iterator to a bucket. Easy pisy! Put this together with other methods such
* as bucket_count (n buckets), bucket, bucket_size , ...
* 
* Finally, note that iterators of a set are not stable. Therefore, two versions of a set constructed differently
* possibly return different values for the iterators.
*/
#include <list>
#include <unordered_set>
#include <iostream>
#include <iterator>

void traverse_u_set_with_itr() {
	std::unordered_set<int> s{ 1, 2, 3 };
	std::list<int>::const_iterator begin = s.begin();	// Felicitation!
}

void u_set_bucket_iterator() {
	std::unordered_set<int> s{ 1, 2, 3, 4, 5 };

	size_t bucket = s.bucket(3);	// Return bucket of the element.
	auto b1_begin = s.begin(bucket);
	auto b1_end = s.end(bucket);

	std::copy(b1_begin, b1_end, std::ostream_iterator<int>{std::cout, "\t"});
}

//int main() {
//	u_set_bucket_iterator();
//}