/**
* constexpr bool includes( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp );
* 
* Returns true if the sorted range [first2, last2) is a subsequence of the sorted range [first1, last1). (A subsequence need not be contiguous.)
* Both ranges must be sorted with the same way.
* 
* What if the second range is empty? It returns false, for the set does not contain empty set.
*/ 
#include <algorithm>
#include <vector>
#include <cctype>
#include <iostream>

template<class Os, class Co> Os& operator<<(Os& os, const Co& v) {
    for (auto i : v) os << i << ' ';
    return os << '\t';
}

void check_includes() {
    const auto 
        v1 = { 'a', 'b', 'c', 'f', 'h', 'x' },
        v2 = { 'a', 'b', 'c' },
        v3 = { 'a', 'c' },
        v4 = { 'a', 'a', 'b' },
        v5 = { 'g' },
        v6 = { 'a', 'c', 'g' },
        v7 = { 'A', 'B', 'C' };

    auto no_case = [](char a, char b) { return std::tolower(a) < std::tolower(b); };

    std::cout << v1 << "\nincludes:\n" << std::boolalpha
        << v2 << ": " << std::includes(v1.begin(), v1.end(), v2.begin(), v2.end()) << '\n'
        << v3 << ": " << std::includes(v1.begin(), v1.end(), v3.begin(), v3.end()) << '\n'
        << v4 << ": " << std::includes(v1.begin(), v1.end(), v4.begin(), v4.end()) << '\n'
        << v5 << ": " << std::includes(v1.begin(), v1.end(), v5.begin(), v5.end()) << '\n'
        << v6 << ": " << std::includes(v1.begin(), v1.end(), v6.begin(), v6.end()) << '\n'
        << v7 << ": " << std::includes(v1.begin(), v1.end(), v7.begin(), v7.end(), no_case)
        << " (case-insensitive)\n" << '\n'
        << "And does not contain empty set: " << std::includes(v1.begin(), v1.end(), v6.begin(), v6.end());
        
}

//int main() {
//    check_includes();
//}