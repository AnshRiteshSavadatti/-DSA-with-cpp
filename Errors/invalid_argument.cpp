// invalid_argument example
#include <iostream> // std::cerr
#include <stdexcept> // std::invalid_argument
#include <bitset> // std::bitset
#include <string> // std::string

int main (void) {
	try {
	// bitset constructor throws an invalid_argument if initialized
	// with a string containing characters other than 0 and 1
	std::bitset<5> mybitset (std::string("01211"));
	// std::bitset<5> mybitset (std::string("11011"));
	}
	catch (const std::invalid_argument& ia) {
	std::cerr << "Invalid argument: " << ia.what() << '\n';
	}
	return 0;
}
