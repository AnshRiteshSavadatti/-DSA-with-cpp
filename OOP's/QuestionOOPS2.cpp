/*
    All the banks operating in India are controlled by RBI. RBI has set a well defined guideline 
    (e.g. minimum interest rate, minimum balance allowed, maximum withdrawal limit etc) which 
    all banks must follow. For example, suppose RBI has set minimum interest rate applicable 
    to a saving bank account to be 4% annually; however, banks are free to use 4% interest rate 
    or to set any rates above it.

    Write a program to implement bank functionality in the above scenario. Note: Create few 
    classes namely Customer, Account, RBI (Base Class) and few derived classes (SBI, ICICI, PNB etc). 
    Assume and implement required member variables and functions in each class.





        Hint:
        Class Customer
        {
        //Personal Details ...
        // Few functions ...
        }

        Class Account
        {
        // Account Detail ...
        // Few functions ...
        } 

        Class RBI
        {
        Customer c; //hasA relationship
        Account a;	//hasA relationship
        ..
        Public double GetInterestRate() {	}
        Public double GetWithdrawalLimit() {	}
        }

        Class SBI: public RBI
        {
        //Use RBI functionality or define own functionality.
        } 

        Class ICICI: public RBI
        {
        //Use RBI functionality or define own functionality.
        }

*/

#include <bits/stdc++.h>
using namespace std;

class Customers{
    public:
        string name;
        string adress;
        int age;
        string phoneNo;

        Customers(string name, string address, int age, string phoneNo){
            this->name = name;
            this->adress = adress;
            this->age = age;
            this->phoneNo = phoneNo;
        }
};

class Account{
    public:
        string accountNum;
        float balance;
        string dataOpened;
        string accountType;
        string Name;

        Account(string accountNum, float balance, string dataOpened, string accountType, string Name){
                this->accountNum = accountNum;
                this->accountType = accountType;
                this->dataOpened = dataOpened;
                this->balance = balance;
                this->Name = Name;
        }

        void displayAccountDetails(){
            cout << "The account details are" << endl;
            cout << this->Name << endl;
            cout << this->accountNum << endl;
            cout << this->balance << fixed << setprecision(3) << endl;
            cout << endl;
        }
};

class RBI{
    public:

        Customers* c;
        Account* a;

        float rateOfIntrest;
        int withdrawalLimit;

        RBI():rateOfIntrest(4),withdrawalLimit(100000){}
        void getRateOfIntrest(){
            cout << this->rateOfIntrest << endl;
            return;
        }

        void getWithdrawlLimit(){
            cout << this->withdrawalLimit << endl;
            return;
        }

        virtual ~RBI(){}

};

class ICICI : public RBI{
    public:
    ICICI(Customers c, Account a){
        this->c = &c;
        this->withdrawalLimit = 2000000;
        this->a = &a;
    }
};

class SBI : public RBI{
    public:
        SBI(Customers c, Account a){
            this->rateOfIntrest = 7.88;
            this->c = &c;
            this->a = &a;
        }
};

int main(){
    Customers cc("Ansh", "HUBLI", 20, "1234567890");
    Account aa("12345", 7899.99, "14-12-2017", "savings", "Ansh");

    ICICI a1(cc, aa);

    SBI a2(cc, aa);

    a2.getRateOfIntrest();
    a2.a->displayAccountDetails();

    a1.getWithdrawlLimit();
    a1.getRateOfIntrest();

    return 0;
}
