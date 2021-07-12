/**
* Since I've been pretty much stuck with ip address, which belong to the network layer of course, consider the following:
*	*** Write a code that prints all ip addresses of a particular range with the given stem and subnet mask***
* 
* Hence, if base ip is 128.10.10.0/24, then we must print the range 128.10.10.0 to 128.10.10.255 (remembering of course
* that the 0 and 255 ip addresses are usually reserved.)
* 
* One solution would be to define a byte stream of four bytes, and then increment each byte stream, and as soon as we reach
* 0xFF in one, increase the next. This solution however is not very handy for non-multiples of eight subnet masks. So, a
* better solution would be to use a 32bit unsigned, and then increment it by one, and then segment its octets and then
* print each one. Increasing this number by 1 from 0 address ensures that all addresses are printed.
* 
* I'm going to use two concepts here. First would be strtok C function. Then, I'm going to using a regular string and a
* regex together with a regex_itr to process the ip.
*/

#include <string>
#include <string.h>
#include <cmath>
#include <iostream>
#include <regex>

using std::string;
void use_strtok(char* base_ip) {
	auto token = strtok(base_ip, ".");

	// First token
	uint32_t ip = std::stoi(token) << 24;

	// Second token
	token = strtok(NULL, ".");
	ip += std::stoi(token) << 16;

	// Third token
	token = strtok(NULL, ".");
	ip += std::stoi(token) << 8;

	// For the fourth one, break on the '/' token
	token = strtok(NULL, "/");
	ip += std::stoi(token);	// The LSB of the ip address.

	token = strtok(NULL, "/");	// The subnet mask.
	int ip_range = pow(2, 32 - std::stoi(token));

	uint8_t* ip_bytes = reinterpret_cast<uint8_t*>(&ip);	// Get each individual byte of the ip.
	for (uint32_t ctr = 0; ctr < ip_range; ++ctr) {
		std::cout << (int)*(ip_bytes + 3) << '.' << (int)*(ip_bytes + 2) << '.' << (int)*(ip_bytes + 1) << '.' << 
			(int)*(ip_bytes) << '\n';

		++ip;
	}
}

void using_regex(const string& ip_base) {
	using namespace std;
	regex rgx{ R"(\d{1,3})" };

	sregex_iterator begin{ ip_base.begin(), ip_base.end(), rgx };	// Notice the use of s.
	// sregex_iterator end{};  We don't need an end here essentially.

	uint32_t ip = 0;
	for (int i = 0; i < 4; i++) {
		ip += stoi(begin++->str()) << ( (3 - i) * 8 );
	}

	int ip_range = pow(2, 32 - stoi(begin->str())) - 1;

	uint8_t* ip_bytes = reinterpret_cast<uint8_t*>(&ip);	// Get each individual byte of the ip.
	for (uint32_t ctr = 0; ctr < ip_range; ++ctr) {
		std::cout << (int)*(ip_bytes + 3) << '.' << (int)*(ip_bytes + 2) << '.' << (int)*(ip_bytes + 1) << '.' << 
			(int)*(ip_bytes) << '\n';

		++ip;
	}


}

//int main() {
//	char ip_stem[] = { '1', '2', '8', '.', '1', '0', '.', '1', '0', '.', '0', '/', '2', '3' };
	// use_strtok(ip_stem);

//	string ip_stem = "128.10.10.0/23";
//	using_regex(ip_stem);
//}