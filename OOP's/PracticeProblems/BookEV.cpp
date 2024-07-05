/*
    Consider an electrical two-wheeler vehicle showroom sells a single type of electrical vehicle (EV). An EV can be 
    described by its color, single or dual battery, and price. An EV can be booked by a customer, if the same vehicle 
    is booked again by any other customer the code shall raise exception (Apply user defined exception concept to manage 
    run-time error/exception). The showroom maintains a fixed number of EV with single and dual batteries and prepares the 
    daily reports of available and booked EV list. Write a CPP program to simulate the above scenario.

*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class EV{
    public:
        string color;
        float price;
        bool booked;

        EV(string color, float price, bool booked){
            this->color = color;
            this->price = price;
            this-> booked = booked;
        }
};

class DualBattery : public EV{
    public:
        void printDetails(){
            cout << this->color << endl;
            cout << this->price << endl;
            cout << this->booked << endl;
        }
};