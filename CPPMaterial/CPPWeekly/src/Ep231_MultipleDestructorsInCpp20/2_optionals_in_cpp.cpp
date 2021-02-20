/**
* If we change the compiler to C++17, there's an optional in CPP.
*/
#include <optional>
#include <string>
#include <iostream>

//int main() {
//	std::optional<std::string> op;
//
//	// std::cout << op.value(); This would throw an exception if empty
//
//	if (op.has_value())
//	{
//		std::cout << op.value();
//	}
//	else {
//		op = "My String";
//		if (op) std::cout << op.value() << '\n';
//		
//		//op.reset(); Returns optional to original form, which throws exception if empty!
//					  // It doesn't matter if the type is built-in.
//		//std::cout << op.value();
//	}
//
//
//	
//}