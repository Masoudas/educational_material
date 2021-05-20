/**
*	-	constexpr ForwardIt remove( ForwardIt first, ForwardIt last, const T& value )
*	-	constexpr ForwardIt remove_if( ForwardIt first, ForwardIt last, UnaryPredicate p );
* 
* Removes all elements satisfying specific criteria from the range [first, last) and returns a past-the-end 
* iterator for the new end of the range.
* 
* Removing is done by shifting (by means of move assignment) the elements in the range in such a way that the 
* elements that are not to be removed appear in the beginning of the range. Relative order of the elements 
* that remain is preserved and the physical size of the container is unchanged. Iterators pointing to an 
* element between the new logical end and the physical end of the range are still dereferenceable, but the 
* elements themselves have unspecified values (as per MoveAssignable post-condition). A call to remove is 
* typically followed by a call to a container's erase method, which erases the unspecified values and reduces 
* the physical size of the container to match its new logical size.
* 
* Note: The similarly-named container member functions list::remove, list::remove_if, forward_list::remove, 
* and forward_list::remove_if erase the removed elements.
* 
* Note: These algorithms cannot be used with associative containers such as std::set and std::map because 
* ForwardIt does not dereference to a MoveAssignable type (the keys in these containers are not modifiable).
* 
* The standard library also defines an overload of std::remove taking const char*, used to delete files: 
* std::remove. 
* 
* Because std::remove takes value by reference, it can have unexpected behavior if it is a reference to an 
* element of the range [first, last).
* 
* My Note: What the standard implies is that we can actually use this method with strings and containers, but
* we need to call their trim methods to remove the nulled elements.
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
#include <vector>

// Notice how we're passing the iterator to the new end to the erase method.
void removing_white_spaces_from_strings()
{
    std::string str1 = "Text with some   spaces";
    str1.erase(std::remove(str1.begin(), str1.end(), ' '),
        str1.end());
    std::cout << str1 << '\n';

    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(std::remove_if(str2.begin(),
        str2.end(),
        [](unsigned char c) { return isspace(c); }),
        str2.end());
    std::cout << str2 << '\n';
}

void remove_from_vector() {
    std::vector<int> v(10, 1);
    v[5] = 0;

    v.erase(std::remove(v.begin(), v.end(), 0));
}