
/*

Case Study: Cell Phone Sim Management System

CONTEXT:
A person purchases a cell phone with dual SIM capability and plans to manage SIM cards efficiently.
Initially, the person inserts SIM cards into the cell phone, and later decides to switch from their current
service provider, AirTel, to a new provider called &quot;ZOOM.&quot; The system is designed to facilitate the
insertion of SIM cards into the cell phone and manage the process of porting to a new service provider
seamlessly.
Develop a C++ program to model the Cell Phone Sim Management System. The program should include
classes for CellPhone and Sim, along with functions to perform specific tasks as described below:

Class Definitions:
CellPhone:
Attributes: model (model of the cell phone), make (make of the cell phone), Sim* (pointer to an array of
Sim objects)
Functions:
void portToServiceProvider(): Updates call rate and data plan corresponding to the new service provider.
void printCellPhone(): Prints details of the cell phone and the SIM cards inserted.
Sim:
Attributes: cellNumber (SIM card number), serviceProvider (AirTel/Idea), callRate, dataPlan
Functions: None

Function Descriptions:
void insertSim(): insert a new sim to the mobile
void portToServiceProvider(): This function facilitates the process of porting to a new service provider,
&quot;ZOOM.&quot; It updates the call rate and data plan of each SIM card in the cell phone to match the
corresponding plans offered by the new service provider.
void printCellPhone(): This function prints details of the cell phone, including its model and make, along
with the details of each SIM card inserted, such as SIM card number, service provider, call rate, and data
plan.
*/


/*************************************************
        Example of aggretation
        if the cell phone is changed the sim can remain the same ie if i take a new cell phone i will insert the old sim in the new cell phone
*************************************************/


#include <iostream>
using namespace std;

class Sim{
    public :
    long int cellNumber;
    string serviceProvider;
    float callRate;
    double dataPlan;

    Sim(long int cellNumber, string serviceProvider, float callRate, double dataPlan){
        this->callRate = callRate;
        this->serviceProvider = serviceProvider;
        this->cellNumber = cellNumber;
        this->dataPlan = dataPlan;
        cout << "Sim constructer called " << endl;
    }
};


class CellPhone{
    string model;
    string make;
    Sim* ptr;

    void _swap(Sim &a, Sim &b){
        Sim temp = a;
        a = b;
        b = temp;
        return;
    }

    public:
    CellPhone(string model, string make, Sim* ptr){
        this->model = model;
        this->make = make;
        this->ptr = ptr;
        cout << "CellPhone Constructer called" << endl;
    }

    void portToServiceProvider(){
        _swap(ptr[0], ptr[1]);
        
        cout << "The updated data plan is " << this->ptr[0].callRate << " " << this[0].ptr->dataPlan << endl;
        return;
    }

    void printCellPhone(){
        cout << endl;
        cout << "The cell phones details are " << endl;
        cout << this->make << " " << this->model << " " << this->ptr->callRate << " " << this->ptr->cellNumber << " "  << this->ptr->serviceProvider << endl;
        return;
     }

};

int main(){
    Sim  airtel (12345, "Airtel", 1.5, 4);
    Sim  jio    (74836, "Jio", 1, 5);

    Sim arr[] = {airtel, jio};
    CellPhone samsungA31("A31", "samsung", arr);
    // CellPhone samsungA51("A51", "samsung", airtel);
    // CellPhone poco      ("X2", "samsung", airtel);
    // CellPhone iphone    ("xv", "iphone", airtel);

    samsungA31.printCellPhone();
    // samsungA51.printCellPhone();

    samsungA31.portToServiceProvider();
    // samsungA51.portToServiceProvider();

    samsungA31.printCellPhone();
    // samsungA51.printCellPhone();
    // poco.printCellPhone();
    // iphone.printCellPhone();

    return 0;
}
