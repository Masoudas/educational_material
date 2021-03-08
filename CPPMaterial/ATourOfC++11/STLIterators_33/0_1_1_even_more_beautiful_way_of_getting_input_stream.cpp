/**
* Using the istream_iterator class, we can write an even more beautiful way of reading from the command
* prompt. This class like all other iterators reside in the iterator header.
* 
* The header of the class as written in the standard is:
* template< class T, 
*           class CharT = char,
*           class Traits = std::char_traits<CharT>,
*           class Distance = std::ptrdiff_t >
* class istream_iterator
* 
* The standard says "std::istream_iterator is a single-pass input iterator that reads successive objects of 
* type T from the std::basic_istream object for which it was constructed, by calling the appropriate 
* operator>>. The actual read operation is performed when the iterator is incremented, not when it is 
* dereferenced. The first object is read when the iterator is constructed. Dereferencing only returns a copy 
* of the most recently read object.
* 
* Hence for example, if we're reading from a file, each increment in the iterator reads a new line, whereas
* with cin, each increment reads one line from the command line. Naturally, if we define T as string, then
* the stream is converted to that, and then can be dereferenced.
* 
* Now, here comes the important part. It says "The default-constructed std::istream_iterator is known as the 
* end-of-stream iterator. When a valid std::istream_iterator reaches the end of the underlying stream, it 
* becomes equal to the end-of-stream iterator. Dereferencing or incrementing it further invokes undefined 
* behavior."
* 
* Hence, for a file, and empty constructed iterator would imply eof. It's actually a bit more complicated,
* which we discuss below.
* 
* Finally, "T must meet the DefaultConstructible, CopyConstructible, and CopyAssignable requirements." The
* point is that this iterator converts to the template so long as it's possible to. For example, if we want
* to convert to int, because there's conversion from basic_stream to int, it naturally happens.
* 
* The standard also mentions that "When reading characters, std::istream_iterator skips whitespace by default
* (unless disabled with std::noskipws or equivalent), while std::istreambuf_iterator does not. In addition, 
* std::istreambuf_iterator is more efficient, since it avoids the overhead of constructing and destructing 
* the sentry object once per character.
* 
* So here's the rub. The empty constructed iterator occurs if either reach the end of the stream, or that
* the iterator can't convert to the template we demanded. Also, don't forget that for example for cin, 
* white space or enter don't terminate an stream, as we once discussed, and they're skipped at the beginning
* or end of stream. So, if I wanted to convert to string, I still can't check for size zero string, 
* because that won't flush! The workaround is to use getline of course. 
* 
* With that in mind, consider the very elegeant code we write below to read from the command line and convert
* to int. int could have been replaced with string of course, but it's interesting the stl has these conversion
* inherit to the implementation!
*/
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void read_from_the_command_line_elegeantly () {
	auto next = std::istream_iterator<double>(std::cin);	// Used for reading the next line. 
															// Quite interesting. This acts like the begin
															// iterator!
	auto end_line = std::istream_iterator<double>();		// An empty constructed iterator acts like end!

	// So we have a begin and end iterator, so obviously, we're going to use foreach to dereference it!
	std::vector<int> inputs{};
	std::for_each(next, end_line, [&](const int& val) {inputs.push_back(val); });

	std::cout << '\n';
	std::for_each(inputs.cbegin(), inputs.cend(), [&](const int& val) {std::cout << val << "\t"; });
}
