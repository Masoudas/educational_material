/**
* The following chapter is from 'The C++ Standard Library - Second Edition' by Rainer Grimm et al.
* 
* A string_view is a non-owning representation of sequence of chars. It represents a view of such sequence.
* This sequence of characters can be a C++-string or a C-string. By non-owning we mean allocation has occured
* some place else (in case of string) or is a C-string. They reside in the string_view header.
* 
* string_view classes are templates, just like a normal string. Notice however that they don't require an allocator,
* as they don't own the string:
template<
    class CharT,
    class Traits = std::char_traits<CharT>
> class basic_string_view;

* And we have the same famous aliases as well:
typedef std::string_view std::basic_string_view<char>
typedef std::wstring_view std::basic_string_view<wchar_t>
typedef std::u16string_view std::basic_string_view<char16_t>
typedef std::u32string_view std::basic_string_view<char32_t>
*/