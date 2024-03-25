/*Association is a relationship between two classes that defines a connection or a link between them. 
The association can be bi-directional, meaning that both classes can use each other’s methods and properties, 
or uni-directional, where only one class can use the methods and properties of the other. The relationship 
can be of any type, such as a one-to-one, one-to-many, or many-to-many.

For example, a Customer class might be associated with an Order class, where each customer can have multiple orders.*/


#include <iostream>
using namespace std;

class Account{
    private:
    int accno;
    int userid;
    float balance;

    public:
    Account():balance(1000){}

    float getBalance(){
        return this->balance;
    }
    int getId(){
        return this->userid;
    }
    void credit(double n){
        this->balance += n;
    }
    void debit(double n){
        this->balance -= n;
    }
    void displayaBalance(){
        cout << "The balance is " << this->balance << endl;
        return;
    }
};

class Bank{
    public:
        void transferAmount(Account& a, Account &b, int n){
            cout << "The balance before the transaction" << endl;
            a.displayaBalance();
            b.displayaBalance();

            a.credit(n);
            a.displayaBalance();

            b.debit(n);
            b.displayaBalance();
            return ;
        }
};

int main(){
    Account a;
    Account b;
    Bank t;
    t.transferAmount(a, b, 200);

}