/**
* To understand why the previous case happens in C++17, note the following two constructors:
* 
* basic_string( const basic_string& other,
*              size_type pos,
*              size_type count = std::basic_string::npos,
*              const Allocator& alloc = Allocator() );
*
* basic_string( const CharT* s,
*              size_type count,
*              const Allocator& alloc = Allocator() );
* 
* Clearly we see that when we pas an instance of basic_string, we select from a given position to the end (so
* that in the previous example, s2{s1, 3} drops the chars, starts from fourth position until npos). Whereas
* when passing const char*, we count 3 elements from the beginning.)
* 
* Note: It's interesting to think about 'pos' as dropping 'pos' chars rather than starting at 'pos' position.
* I tend to think of it as the latter saying 'Ok, if pos=3, then start at position 3, which is in fact the
* fourth char,' which is a lot of indirection in my brain! So it would be nice not to do that.
*/
