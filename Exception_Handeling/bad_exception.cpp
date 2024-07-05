// bad_exception example

/*
	myfunction is declared with an exception specification that allows it to throw int 
	and std::bad_exception. However, inside the function, it throws a char ('x'), which 
	is not listed in the exception specification.
*/

#include <iostream> // std::cerr
#include <exception> // std::bad_exception, std::set_unexpected
using namespace std;

void myunexpected () {
	std::cerr << "unexpected handler called\n";
	throw ;
}

void myfunction () throw (int,std::bad_exception) {
	throw 'x'; // throws char (not in exception-specification)
}

int main (void) {
	std::set_unexpected (myunexpected);
	try {
		myfunction();
	}
	catch (int) { std::cerr << "caught int\n"; }
	catch (char){ std::cerr <<"caught char\n"; }
	catch (std::bad_exception be) { std::cerr << "caught bad_exception\n"; }
	catch (...) { std::cerr << "caught some other exception\n"; }
	return 0;
}
