#include <bits/stdc++.h>
using namespace std;

class form{
    public:
        string name;
        int day;
        int month;
        int year;
        long long phoneNumber;
        string gmail;

        form(string name, int day, int month, int year, long long phoneNumber, string gmail){
            this->name = name;
            this->day = day;
            this->month = month;
            this->year = year;
            this->phoneNumber = phoneNumber;
            this->gmail = gmail;
            cout << "Constructer called 📱" << endl;
        }

        int print(){
            cout << this->phoneNumber << endl;
            cout << this << endl;
            cout << endl;
        }
};

int main(){
    form * ptr = new form("Ansh", 24, 3, 2024, 1234567890, "anshsavadatti@gmai.com");
    // form * ptr2 = new form(*ptr);

    form ptr2(*ptr);
    form ptr3(ptr2);

    cout << "Before changing" << endl;
    ptr2.print();
    ptr->print();
    ptr3.print();

    ptr->phoneNumber = 34000;   

    cout << "After Changing" << endl;
    ptr2.print();
    ptr->print();
    ptr3.print();

    return 0;
}

/*
        OUTPUT
        Before changing
        1234567890
        0x61fe78

        1234567890
        0xf67f50

        After Changing
        1234567890
        0x61fe78

        34000
        0xf67f50

        COW PRINCIPLE APPLIED
*/