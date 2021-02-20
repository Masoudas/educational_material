/**
* Note C++ stl only provides functions for computing the hash value of basic types, and some of the types provided
* by stl. 
* 
* If we want to hash any custom type, we must write a hash function for the type ourself, which requires a deep
* knowledge of hashing mechanism, etc. 
* 
* The boost library provides a mechanism for doing so in the boost/functional/hash.hpp header. This method starts
* from a hash seed and augments each hash to it. Hence, we can create a hash interface as such for our custom type.
* 
*/ 
#include <string>
#include <unordered_map>
#include <unordered_set>

struct Car 
{
	std::string model;
	std::string brand;
	int buildYear;

};

struct CarHasher
{
	std::size_t operator()(const Car& car) const
	{
		std::size_t seed = 0;
		// boost::hash_combine(seed, car.model); Starts from a particular hash value and augments it
		// boost::hash_combine(seed, car.brand); 
		return seed;
	}
};

struct CarComparator
{
	bool operator()(const Car& car1, const Car& car2) const
	{
		return (car1.model == car2.model) && (car1.brand == car2.brand);
	}
};

void create_map_for_car_class() {
	// We can use the hasher as follows:
	std::unordered_set<Car, CarHasher, CarComparator> carSet;
	std::unordered_map<Car, std::string, CarHasher, CarComparator> carDescriptionMap;
}