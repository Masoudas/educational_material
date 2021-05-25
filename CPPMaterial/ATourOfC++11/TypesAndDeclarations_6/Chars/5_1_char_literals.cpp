/**
* We have the following definitions:
*	*	c-char	-	either 
*			-	a character from the source character set minus single-quote ('), backslash (\), or the newline 
*			character,
*			-	an escape sequence, as defined in escape sequences (\', \", \t, \a for audible bell etc)
*			-	a universal character name, as defined in escape sequences
*	*	c-char-sequence	-	two or more c-chars
* 
* Then we have the following literals:
*	#1	'c-char'
*	#2	u8'c-char'
*	#3	u'c-char'
*	#4	U'c-char'
*	#5  L'c-char'
*	#6	'char-sequence'
*	#7	L'char-sequence'
* 
*	#1	Ordinary character literal or narrow character literal, e.g. 'a' or '\n' or '\13'. Such literal has 
*	type char and the value equal to the representation of c-char in the execution character set.
* 
*	#2	UTF-8 character literal, e.g. u8'a'. Such literal has type char (until C++20)char8_t (since C++20) and 
*	the value equal to ISO 10646 code point value of c-char, provided that the code point value is 
*	representable with a single UTF-8 code unit (that is, c-char is in the range 0x0-0x7F, inclusive)
* 
*	#3 UTF-16 character literal, e.g. u'猫', but not u'🍌' (u'\U0001f34c'). Such literal has type char16_t 
*	and the value equal to ISO 10646 code point value of c-char, provided that the code point value is 
*	representable with a single UTF-16 code unit (that is, c-char is in the range 0x0-0xFFFF, inclusive).
* 
*	#4	UTF-32 character literal, e.g. U'猫' or U'🍌'. Such literal has type char32_t and the value equal to 
*	ISO 10646 code point value of c-char
* 
*	#5	Wide character literal, e.g. L'β' or L'猫'. Such literal has type wchar_t and the value equal to the 
*	value of c-char in the execution wide character set.
* 
*	#6	Ordinary multicharacter literal, e.g. 'AB', is conditionally-supported, has type int and 
*	implementation-defined value
* 
*	#7 Wide multicharacter literal, e.g. L'AB', is conditionally-supported, has type wchar_t and 
*	implementation-defined value.
* 
*/

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string_view>

template <typename CharT>
void dump(std::string_view s, const CharT c) {
    const uint8_t* data{ reinterpret_cast<const uint8_t*>(&c) };
    std::cout << "'" << s << "' \t" << std::hex
        << std::uppercase << std::setfill('0');
    for (auto i{ 0U }; i != sizeof(CharT); ++i) {
        std::cout << std::setw(2) << static_cast<unsigned>(data[i]) << ' ';
    }
    std::cout << '\n';
}

void print(std::string_view str) { std::cout << str; }

// It's interesting that he tries to assign utf or wide chars to string_view. In MSVC compiler it casts to
// chars!
void some_playing_with_chars()
{
    print("literal hex dump \n"
        "─────── ───────────\n");

    dump("a", 'a');
    dump("🍌", '🍌'); // implementation-defined
    print("\n");

    // ordinary multi-character literal
    dump("ab", 'ab'); // implementation-defined
    print("\n");

    // UTF-16 character literals
    char16_t uc1 = u'a'; dump("a", uc1);
    char16_t uc2 = u'¢'; dump("¢", uc2);
    char16_t uc3 = u'猫'; dump("猫", uc3);
    //  char16_t uc4 = u'🍌'; dump("🍌", uc4); // error: 🍌 maps to two UTF-16 code units
    print("\n");

    // UTF-32 character literals
    char32_t Uc1 = U'a'; dump("a", Uc1);
    char32_t Uc2 = U'¢'; dump("¢", Uc2);
    char32_t Uc3 = U'猫'; dump("猫", Uc3);
    char32_t Uc4 = U'🍌'; dump("🍌", Uc4);
    print("\n");

    // wide character literals
    wchar_t wc1 = L'a'; dump("a", wc1);
    wchar_t wc2 = L'¢'; dump("¢", wc2);
    wchar_t wc3 = L'猫'; dump("猫", wc3);
    wchar_t wc4 = L'🍌'; dump("🍌", wc4);
}