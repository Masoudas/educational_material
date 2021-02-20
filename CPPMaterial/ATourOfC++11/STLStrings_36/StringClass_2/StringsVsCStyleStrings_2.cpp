/**
 * As we said, by c-style strings we mean const char arrays, ending in '\0'.
 * 
 * Let's just say strings have simpler semantics, and are as efficient or even better as C-style strings. So,
 * we shall not use C-style strings for the reason of efficiency, or because they're low level. We shall only
 * use them if we're forced to deal with them.
 * 
 * Like for example say we wanted to add two strings together. Obviously the string class example
 * is less verbose, and c-style example is prone to error.
 */
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>    // contains sort algorithms as well
using namespace std;
/**
 * Addition of two strings creates a new string.
 * 
 */
string add(const string& str1, const string& str2){
    return str1 + str2; 
}

/** We have to allocate memory, copy them and then return the pointer! */
char* add(const char* str1, const char* str2){
    int len1 = strlen(str1);    // Length does not contain \0
    int len2 = strlen(str2);    

    char* add = (char*)(malloc(len1 + len2 + 1));  // One is added for the end '\0';
  
    //strcpy(add, str1); // Copies to destination, including null char. Null will be overwritten next.
    //strcpy(add + len1, str2);   // Add the remainder starting from len1;

    return add;
}
namespace StringVsCStyleString_2 {
    void using_c_string_style() {
        const char* c1 = "abc";
        const char* c2 = "def";

        char* c3 = add(c1, c2);
        cout << c3 << endl;    // Is this call ambiguous? I think because we need an implicit conversion for the first one,
                                // whereas the second one is just a direct call, no!

        // WE MUST NOT FORGET TO DELETE c3 AS WELL.
        free(c3);

        string str1{ c1 };
        string str2{ c2 };
      
        cout << add(str1, str2);
    }

}

/**
 * Also when it comes to comparisons, checkout how easy they're with string compared to c-style string*/
void compare(){
    string s1 = "Str";

    if (s1 < "String") cout << "This is less";

    const char* c = "Str";
    if (strcmp(c, "String") != 0) cout << "More difficult compare";
}

/**
 * Finally, sorting is much, much easier with the string class.
 */
void sorting(){
    vector<string> strs = {"abc", "hij", "def"};
    sort(strs.begin(), strs.end()); // sort is in the algorithm header.

    // array of char pointers.
    const char* as[] = {"Grieg", "Williams", "Bach", "Handel" };
    qsort(as, sizeof(*as), sizeof(as)/sizeof(*as), (int(*)(const void*,const void*))strcmp);
}