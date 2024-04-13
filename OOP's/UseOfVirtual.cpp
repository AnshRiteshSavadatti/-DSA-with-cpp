#include <bits/stdc++.h>
using namespace std;

class BankAccount{
    public:
    string name;
    int accNo;

    BankAccount():name("Ansh"), accNo(2004){}

    // if we dont write virtual the function wont be overwritten
    virtual void display(){
        cout << name << endl;
        cout << "display of BankAccount Class" << endl;
        cout << endl;
        return;
    }
};

class SavingsAccount : public BankAccount{
    float balances;

    public:
    SavingsAccount(): balances(0){}

    void display()override{
        cout << name <<  " "  << accNo << endl;
        cout << balances << endl;
        cout << "display() of SavingsAccount" << endl;
        cout << endl;
        return;
    }
};

class CurrentAccount : public BankAccount{
    float balances;
    
    public:
    float charges;

    CurrentAccount():charges(100){}

    void display() override{
        cout << this->charges << endl;
        cout << "display() of CurrentAccount" << endl;
        cout << endl;
    }

};

main(){
    BankAccount *ba, b;
    SavingsAccount sb;
    
    ba = &sb;
    ba->display();
    /*
        In the above function will call the display of class BankAccount as it is pointer 
        to BankAccount
        By adding virtual keyword in base class the function can be overwritten
    */

    ba = &b;
    ba->display();

    CurrentAccount ca;
    ba = &ca;
    ba->display();

    return 0;
}