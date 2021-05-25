/**
 * Character literals, confined to '', are of course in char.
 *
 * We have the following set of chars:
 * 
 * char: Guaranteed to have at least 8 bits in all platforms. It's used for supporting ASCII. char maybe 
 * signed or unsigned by itself is not guaranteed to be signed or unsigned. (The standard says that for ARM
 * platforms, this is normally unsigned, whereas for x_86 and x_64, it's normally signed.)
 * signed char: a signed version of char.
 * unsigned char: an unsigned version.
 * 
 * wchar_t: A character set that is usually large enough to hold the entire char set of the locale. It
 * is large enough to hold UNICODE. It's a distinct type and not defined in any header.
 * 
 * char16_t: A 16 bit char type, used for holding UTF-16
 * char32_t: A 16 bit char type, used for holding UTF-32
 *
 * We may also have char v1[] = "a", which contains as we know two chars, 'a' and '\0', which
 * is implicitly const char v1[].
 * 
 * Continue reading about chars in the respective folder.
 * 
 */

/**
 * Note that pointer conversion between signed and unsigned types is also not defined.
 */
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