/**
* Just to stress on the fact that string_view does not allocate new memory, take a look at the following
* example for a comparison with string, where many operations, including sharing a string results in allocation
* of memory.
* 
* There's something very clever about this example, which is also odd! So, we overload the new operator for
* size_t operator. Now, because string by default uses this operator, this override of new does what we need
* and also allocates memory. The odd thing is that new string is in the std namespace. So, shouldn't we use 
* the new operator of std due to ADL? Point is that std does not overrides of new. When string uses allocator,
* it just uses the allocate method, which uses the new operator, and well, the new operator is in the global
* name space. Therefore, if we overload, it will be used.
*/

// stringView.cpp 
#include <string_view>
#include <iostream>

//void* operator new(std::size_t count) {
//    std::cout << "   " << count << " bytes" << std::endl;
//    return malloc(count);
//}
//
//void getString(const std::string&) {}
//
//void getStringView(std::string_view) {}
//
//void investiage_allocations(){
//    std::string large = "0123456789012345678901234567890123456789";  // 41 bytes allocated (4 * 10 + 1).
//                                                                    // Though allocated buffer size is 48.
//    
//    std::string substr = large.substr(10);      // 31 bytes allocated (40 - 10 + 1)
//    
//    std::string_view largeStringView{ large.c_str(), large.size() };
//    largeStringView.remove_prefix(10);              // 0 bytes allocated
//
//    getString(large);
//    getString("0123456789012345678901234567890123456789");           // 41 bytes allocated
//    const char message[] = "0123456789012345678901234567890123456789";
//    getString(message);                         // 41 bytes allocated
//
//    getStringView(large);                   // 0 bytes allocated
//    getStringView("012345678901234567890"
//        "1234567890123456789");   // 0 bytes allocated
//    getStringView(message);                 // 0 bytes allocated
//
//}


//int main() {
//    investiage_allocations();
//}