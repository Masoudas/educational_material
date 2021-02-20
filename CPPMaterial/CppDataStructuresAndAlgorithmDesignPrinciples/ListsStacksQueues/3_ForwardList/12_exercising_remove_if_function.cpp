/**
* Because we're interested in Indian elections now for some reason, we shall use forward_list together with
* remove_if function to explore the indian electoral base. And because India is such a vast country and has
* no time, we should use constexpr, however, forward_list can't be constexpr!
* 
* Voters are defined as citizen structs.
* 
* I urget you to take a look at how the output stream is built, and how we supply it as a chunck of information
* once at the end of this whole process.
*/
#include <forward_list>
#include <string>
#include <iostream>

using std::string;
using std::ostream;

struct citizen{	// constexpr
	string name;
	int age;

	friend ostream& operator<<(ostream& stream, citizen c) {
		return stream << "[Name: " << c.name << ", Age: " << c.age << "]\n";
	}
};

void exploring_the_indian_electoral_base()
{
	std::forward_list<citizen> citizens = { {"Raj", 22}, {"Rohit", 25}, {"Rohan", 17}, {"Sachin", 16} };

	auto citizens_copy = citizens;
	
	std::cout << "All the citizens: ";
	for (const auto& c : citizens)
		std::cout << c << " ";
	std::cout << std::endl;

	citizens.remove_if(
		[](const citizen& c)
		{
			return (c.age < 18);
		});

	std::cout << "Eligible citizens for voting: ";
	for (const auto& c : citizens)
		std::cout << c << " ";
	std::cout << std::endl;

	citizens_copy.remove_if(
		[](const citizen& c)
		{
			// Returns true if age is less than 18
			return (c.age != 17);
		});
	std::cout << "Citizens that will be eligible for voting next year: ";
	for (const auto& c : citizens_copy)
		std::cout << c << " ";
	std::cout << std::endl;
}

//int main() {
//	exploring_the_indian_electoral_base();
//}

