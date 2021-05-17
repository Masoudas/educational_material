/**
* As we know, a program starts by calling a main function. The main allow us to pass arguments from the 
* command line.
* 
* When this is done, main() is given two arguments specifying the number of arguments, conventionally called 
* argc, and an array of arguments, conventionally called argv. The arguments are C-style character strings, 
* so the type of argv is char*[argc+1]. The name of the program (as it occurs on the command line) is passed 
* as argv[0], so argc is always at least 1. The list of arguments is zero-terminated; that is, argv[argc]==0.
* For example, for the command

dc 150/1.1934

* argc would have a value of 2, argv[0] = "dc", and argv[1] = "150/1.1934" and argv[2] = '\0'.
* The idea is to read from the command string in the same way that we read from the input stream. A stream 
* that reads from a string is unsurprisingly called an istringstream. In other words, we can wrap the 
* stream in an istringstream as follows to stream a string (if needed of course):

istringstream(argv[1]);	 // argv[1] from the above example is now invertible to istream.

* Me: Interestingly, notice that to avoid slicing, can't directly convert from ifstream ot istringstream to
* an istream. We must get a reference or a pointer to it!

*/

#include <sstream>

void main_parser(int argc, char** argv) {
	std::istringstream arg_stream{ argv[0] };
	
	std::istream& istr =  arg_stream ;
}