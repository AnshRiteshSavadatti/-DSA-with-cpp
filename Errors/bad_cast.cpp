// bad_cast example

/*
	pointer of derived class cannot point to base class but
	pointer to base class can point to derived class
*/

#include <iostream> 
#include <typeinfo> // std::bad_cast
using namespace std;

class Base {
	virtual void member(){}
};

class Derived : public Base {};

int main () {
	try
	{
		Base b;
		Derived& rd = dynamic_cast<Derived&>(b);
		Derived d;
		// Base& rb = dynamic_cast<Base&>(d);
	}
	catch (std::bad_cast& bc)
	{
		std::cerr << "bad_cast caught: " << bc.what() << '\n';
	}
	return 0;
}
