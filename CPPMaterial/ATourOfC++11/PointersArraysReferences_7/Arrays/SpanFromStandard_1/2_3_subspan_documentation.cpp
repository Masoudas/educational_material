/**
* We've three ways of getting a subspan from a span according to the standard:
* 
*	-	first:
* template< std::size_t Count >
* constexpr std::span<element_type, Count> first() const;
* constexpr std::span<element_type, std::dynamic_extent> first( size_type Count ) const;
* 
*   -   subspan:
* template< std::size_t Offset, std::size_t Count = std::dynamic_extent >
*   constexpr std::span<element_type, E // see below //> subspan() const; (1)
*   
* constexpr std::span<element_type, std::dynamic_extent>
*   subspan( size_type Offset, size_type Count = std::dynamic_extent ) const;
* 
* Obtains a span that is a view over the Count elements of this span starting at offset Offset. If Count is 
* std::dynamic_extent, the number of elements in the subspan is size() - offset (i.e., it ends at the end of 
* *this.).
* 
* (1) is ill-formed if:
*   -   Offset is greater than Extent, or
*   -   Count is not std::dynamic_extent and Count is greater than Extent - Offset.
* 
* The behavior is undefined if either Offset or Count is out of range. This happens if
*   -   Offset is greater than size(), or
*   -   Count is not std::dynamic_extent and Count is greater than size() - Offset.
* 
* This example still does not in MSVC.
* 
* 
*/

#include <iostream>
#include <span>
#include <string_view>
 
void print_first(std::string_view const title, 
           /* std::ranges::forward_range */ const auto& container) {
    std::cout << title << "[" << std::size(container) << "]{ ";
    for (auto const& elem : container)
        std::cout << elem << ", ";
    std::cout << "};\n";
}
 
void run_game(std::span<const int> span)
{
    print_first("span: ", span);
 
    std::span<const int, 5> span_first = span.first<5>();
    print_first("span.first<5>(): ", span_first);
 
    std::span<const int, std::dynamic_extent> span_first_dynamic = span.first(4);
    print_first("span.first(4):   ", span_first_dynamic);
}
 
//int main()
//{
//    int a[8]{ 1, 2, 3, 4, 5, 6, 7, 8, };
//    print_first("int  a", a);
//   run_game(a);
//}