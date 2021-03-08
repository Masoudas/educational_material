/**
*  Question: What's the difference between reading cin with char and string?
*  Question: What's difference between putting noskipws for cin and not?
*   Question: What's the difference between the following two codes?
* std::string s, s1, s2, s3, s4;
*  std::cin >>  s >> s1 >> s2 >> s3 >> s4;
* and 
* std::char s, s1, s2, s3, s4; std::cin >>  s >> s1 >> s2 >> s3 >> s4;
* 
*  Question: Write and string and at the end press ctrl+z. A '^Z' appears in the end. Now, if you press
* enter, a -> sign appears if you print this string. Why? Why wouldn't the same thing happen if you 
* write a simple ^Z?
* 
* Question: If I write a '\' on the command line, will it appear as \\ or as \ in a string? The answer to
* this one is that it appears as the ASCII char equivalent to \. \\ is for when we write string. What's
* stored in a char is just a single number, not two numbers for \\!
* 
*/
#include <iostream>
#include <string>
#include <sstream>

// More precisely, this one reads from the last preceding white space, to first ending white space, or enter!
void this_reads_one_line_till_we_press_enter() {
	std::string s{};
	std::cin >> s;
}

void using_no_skip() {
    char c1, c2, c3;
    std::istringstream(" a b c") >> c1 >> c2 >> c3;
    std::cout << "Default  behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';
    std::istringstream(" a b c") >> std::noskipws >> c1 >> c2 >> c3;
    std::cout << "noskipws behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';

    std::string s, s1, s2, s3, s4;
    std::cin >>  s >> s1 >> s2 >> s3 >> s4;

    std::cout << s << s1 << s2 << s3 << s4;
}


