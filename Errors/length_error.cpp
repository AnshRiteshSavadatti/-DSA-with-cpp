// length_error example
#include <iostream> // std::cerr
#include <stdexcept> // std::length_error
#include <vector> // std::vector

int main (void) {
	try {
	// vector throws a length_error if resized above max_size
		std::vector<int> myvector;
		std::cout<<myvector.max_size()<<std::endl;
		myvector.resize(myvector.max_size()+1);
		myvector.resize(10);
	}
	catch (const std::length_error& le) {
		std::cerr << "Length error: " << le.what() << '\n';
	}
	return 0;
}
