/**
 * Because std::string is in fact a pointer to char, the content of it are located on the heap.
 * However, it will automatically manage its memory, hence there's no need to delete its elements
 * when we're done with it. However, the string itself if like an automatic variable, and goes
 * out of scope once it's done.
 */

#include <string>
#include <iostream>
#include <vector>

std::string reverse_string(const std::string& s ){
    std::string ss;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        ss.push_back(s[i]);
    }
    
    return ss;  // We use the copy constructor of string here.
}

/**
 * Here, we return a reference to the string. However, the variable goes out of scope
 * when it's returned, hence, we would not be able to access its element.*/
std::string& reverse_string1(const std::string& s ){
    std::string ss;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        ss.push_back(s[i]);
    }
    
    return ss; // Disaster. Returning reference to an automatic variable.
}

/**
 * Here, we create a string with new. Now the reference to the string object is in the memory as well.*/
std::string* reverse_string2(const std::string& s ){
    std::string* ss = new std::string{};

    for (int i = s.size() - 1; i >= 0; i--)
    {
        ss->push_back(s[i]);
    }
    
    return ss;  // We use the copy constructor of string here.
}

/** Vector and array and I'm guessing all other structures do the same as well.
*/

std::vector<int> vecIsTheSame(){
    std::vector<int> v{1,2,3};
    return v;   // Using move semantics
}

//int main(){
//    const std::string str = "AX";
//
//    std::cout << reverse_string(str) << std::endl;
//
//    std::string& ref = reverse_string1();   // This will throw an exception if used. Resource is already deleted.
//    std::string* ptr = reverse_string2();   // This is fine.
//    delete ptr;
//}