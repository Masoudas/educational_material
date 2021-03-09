/**
* Now, in cpp20, to resolve this ambiguity and at the same time keeping backward compatibility, the basic_string
* constructor does not take an optional argument (npos), and it's defined as below in the standard:
* 
* constexpr basic_string( const basic_string& other,
*                        size_type pos,
*                        size_type count,
*                        const Allocator& alloc = Allocator() );
* 
* First, notice that the ctor is now constexpr. Second, notice that count is now not optional, and we have to
* hand write it, which would make us remember that there's an interval notion involved here.
* 