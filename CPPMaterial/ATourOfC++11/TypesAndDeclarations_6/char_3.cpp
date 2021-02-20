/**
 * We have the following set of chars:
 * 
 * char: Guaranteed to have at least 8 bits in all platforms. It's used for supporting ASCII.
 * char maybe signed or unsigned by itself is not guaranteed to be signed or unsigned.
 * signed char: a signed version of char.
 * unsigned char: an unsigned version.
 * 
 * wchar_t: A character set that is usually large enough to hold the entire char set of the locale. It
 * is large enough to hold UNICODE. It's a distinct type and not defined in any header.
 * 
 * char16_t: A 16 bit char type, used for holding UTF-16
 * char32_t: A 16 bit char type, used for holding UTF-32
 * 
 * When it comes to chars, it's not safe to assume that chars are contiguous.
 * 
 * We may say char c = 'b'; int i {c}; The question however is that whether c is signed or unsigned, is it
 * implemented with one's complement or two's complement (hence, range from -127 to 127 or -128 to 127).
 * So even cast is not trivial. Best to use the home made cast function Mr.Bjrane talks about.
 * 
 * Note that case from int to char is also possible, because chars are still integer types.
 * void digits(){for (int i=0; i!=10; ++i)cout << static_cast<char>('0'+i);
 * The character literal '0' is converted to its integer value and is added.  
 * The resulting int is then converted to a char and written to cout.  
 * Plain '0'+i is an int, so if I had left out the static_cast<char>, the output would have been something like 
 * 48,49,and so on, rather than 0,1, and so on.
 * 
 * 
 * The inital value of char is of course implementation dependent. (Me: An uninitialized pointer or value has
 * random value).
 * 
 * As we said the following cast is undefined:
 * char c = 255;
 * int i = c;
 * Because we don't know whether c (which is all one) is actually -1 or 255. In other words, 255 is an int literal,
 * then converted to int, which if c is unsigned is 255, otherwise -1.
 * 
 * Naturally of course int i = 'c' is not allowed.
 * 
 * Character literals, confined to '', are of course in char.
 * 
 * We may also have char v1[] = "a", which contains as we know two chars, 'a' and '\0', which
 * is implicitly const char v1[].
 */

/**
 * Note that pointer conversion between signed and unsigned types is also not defined.*/
#include <iostream>
using namespace std;

void conversion_between_char_types(char c, unsigned char uc, signed char sc){
    // char* pc = &uc; Error, no conversion
    // unsigned char* puc = &c; Error, no conversion

    // This behavior is also undefined sc = c;  Depends on the implementation.
    
    // wchar_t is an unsigned entity, hence negative values underflow.
    wchar_t d {'\0'};
    d--;
   // cout << d;
}

/** Consider this in an 8bit system*/
void signedToUnsigned(){
    signed char sc = -160;
    unsigned char uc = sc;
    if (uc == 116) cout << "The conversion from signed to unsigned"; // (because 256-160==116). 160 + 116 = 256.
    
    char count[256]; 
    ++count[sc];  //likely disaster: out-of-range access, because pointer has to go far back from the starting
                  // point. So no direct conversion from signed to unsigned occurs.
    ++count[uc];                     //OK
}

void using_all_above_char_stuff(){
    conversion_between_char_types(0, 0, 0);
    int i;
    int* ptr;

//    cout << i << endl;    prints a random number. Not initialized.
 //   cout << ptr; prints a random address. Not initialized.
}