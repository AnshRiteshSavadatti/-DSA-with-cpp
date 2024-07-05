/*
    Imagine that the State Bank of India offers a "CashCard" service for its customers, which includes two types of cards: 
    Credit Cards and Debit Cards. Customers can use these cards for their shopping needs. While using a Debit Card, customers 
    have the option to change their PIN. Additionally, they can transfer funds from their Debit Card to their Credit Card to pay 
    off their balance.

    Develop a C++ program to simulate this scenario. The program should include appropriate attributes for each class and handle 
    various operations. Furthermore, the program should identify and manage potential error conditions using custom-defined 
    exceptions.
*/


#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class Card {
public:
    float amount;
    long long int pin;

    Card(float amount = 1500, long long int pin = 12345) : amount(amount), pin(pin) {}

    virtual ~Card() = default;  // virtual destructor for base class
};

class CreditCard : public Card {
public:
    CreditCard(float amount = 0) : Card(amount) {}
};

class DebitCard : public Card {
public:
    DebitCard(float amount = 1500, long long int pin = 12345) : Card(amount, pin) {}

    void changePin() {
        long long int testPin;
        cout << "Enter the current pin: ";
        cin >> testPin;

        if (testPin == this->pin) {
            long long int newPin;
            cout << "Enter new pin: ";
            cin >> newPin;

            this->pin = newPin;
            cout << "Pin changed successfully." << endl;
        } else {
            cout << "Incorrect pin." << endl;
        }
    }

    void transferFunds(CreditCard &creditCard, float amount) {
        if (amount > this->amount) {
            throw runtime_error("Insufficient funds to transfer.");
        }
        this->amount -= amount;
        creditCard.amount += amount;
        cout << "Transferred " << amount << " to Credit Card." << endl;
    }
};

class Customer {
public:
    string name;
    unsigned long int custno;
    DebitCard debitCard;
    CreditCard creditCard;

    Customer(string name, unsigned long int custno, float debitAmount, long long int debitPin, float creditAmount) 
    : name(name), custno(custno), debitCard(debitAmount, debitPin), creditCard(creditAmount) {}
};

class Bank {
public:
    string name;
    string location;
    vector<Customer*> customers;

    Bank(string name, string location) : name(name), location(location) {}

    void addCustomer(Customer* customer) {
        customers.push_back(customer);
    }

    void displayCustomersDetails() {
        for (auto it : customers) {
            cout << "Customer Name: " << it->name << endl;
            cout << "Customer Number: " << it->custno << endl;
            cout << "Debit Card Balance: " << it->debitCard.amount << endl;
            cout << "Credit Card Balance: " << it->creditCard.amount << endl << endl;
        }
    }

    ~Bank() {
        for (auto customer : customers) {
            delete customer;
        }
    }
};

int main() {
    Bank sbi("SBI", "Bharat");

    Customer* customer1 = new Customer("John Doe", 1, 5000, 12345, 1000);
    Customer* customer2 = new Customer("Jane Smith", 2, 3000, 67890, 2000);

    sbi.addCustomer(customer1);
    sbi.addCustomer(customer2);

    sbi.displayCustomersDetails();

    // Example operations
    try {
        customer1->debitCard.transferFunds(customer1->creditCard, 1000);
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    customer1->debitCard.changePin();

    sbi.displayCustomersDetails();

    return 0;
}
