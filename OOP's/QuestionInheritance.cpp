#include <bits/stdc++.h>
using namespace std;

class ATM{
  public:
    string bankName;
    string location;
    long double balance;

    virtual void debit(double amt){
        if(this->balance >= amt)
           this->balance -= amt;
        else{
            cout << "No sufficient balance" << endl;
            }
    }  

    virtual void printATM(){
        cout << "The balance of the account is " << endl;
        cout << this->balance << endl;
    }
};

class CashDepositeATM : public ATM{
    public :
        // assumming threshold amt to be 10000

        CashDepositeATM(string bankName, string location, double balance){
            this->balance = balance;
            this->bankName = bankName;
            this->location = location;
        }

        void debit(double amt)override {
            if(this->balance >= amt){
                this->balance -= amt;
                cout << amt << " Debited from Account" << endl;
            }
            else{
                cout << "CashDepositeATM" << endl;
                cout << "No sufficient balance" << endl;
                }
        }  

        void printATM()override{
            cout << "CashDepositeATM" << endl;
            cout << "The balance of the account is " << endl;
            cout << this->balance << endl;
        }

        void depositeCash(double cash){
            if(cash > 1000){
                this->balance += cash;
                cout << "The total balance is " << this->balance << endl;
            }
        }
};

class NormalATM : public ATM {
    public:

        NormalATM(string bankName, string location, double balance){
            this->balance = balance;
            this->bankName = bankName;
            this->location = location;
        }

        void debit(double amt)override {
        if(this->balance >= amt){
            this->balance -= amt;
            cout << amt << " Debited from Account" << endl;
        }
        else{
            cout << "NormalATM" << endl;
            cout << "No sufficient balance" << endl;
            }
    }  

    void printATM()override{
        cout << "NormalATM" << endl;
        cout << "The balance of the account is " << endl;
        cout << this->balance << endl;
    }
};

int main(){
    NormalATM na1("KLE_BANK","HUBLI",11111111.11);
    na1.debit(111111111111111);
    na1.debit(100);
    cout << endl;

    CashDepositeATM ca1("KARNATAKA_BANK","HUBLI",1234567.11);
    ca1.debit(111111111111111);
    ca1.debit(100);
    ca1.depositeCash(1000);

    return 0;

}