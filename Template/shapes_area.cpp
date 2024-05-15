/*
    Consider 2 classes circle and rectangle, these 2 classes are not related to each other. Create a global
    methode using templates that accpets single object as paramenter and displays the area of the corresponding
    object
*/

#include <iostream>
using namespace std;

class circle{
    public:
    int radius;
    
    circle(int radius){
        this ->radius = radius;
    }

    double calcarea() const {
        return 3.14 * radius * radius;
    }
};

class triangle{
    public:
    int side;

    triangle(int side){
        this->side = side;
    }

    double calcarea() const {
        return 0.5 * side * side; // Assuming equilateral triangle for simplicity
    }
};



template <typename T>
double area(const T &obj) {
    return obj.calcarea();
}

int main(){
    circle c(10);
    triangle t(10);

    cout << "The area of circle is " << area(c) << endl;
    cout << "The area of triangle is " << area(t) << endl;

    return 0;

}