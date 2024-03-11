#include <iostream>
#include <string>

class Name {
public:
    std::string name;
};

int main() {
    Name instance;
    
    std::cout << "Size of Name class: " << sizeof(instance) << " bytes" << std::endl;

    instance.name = "Ansh R savadatti I am a student at KLE technological university"  ;
    std::cout << "Size of Name class: " << sizeof(instance) << " bytes" << std::endl;
    std::cout << "Size of the string is " << sizeof(instance.name) << "bytes" << std::endl;

    std::string s = "Ansh R savadatti I am a student at KLE technological university";
    std::cout << "The size is " << sizeof(s) << std::endl;

    std::string str;
    std::cout<< "The size of uninitialized string is " << sizeof(str) << std::endl;
    std::cout << "The size of string is " << sizeof(std::string) << " The size of int is " << sizeof(int) << std::endl;
    return 0;
}
