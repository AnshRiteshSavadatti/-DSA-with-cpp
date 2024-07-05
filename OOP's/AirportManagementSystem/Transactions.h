#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

class Transactions {
public:
    int transactionID;
    int flightID;
    int passengerID;
    double amount;

    Transactions(int transactionID, int flightID, int passengerID, double amount);
    void processPayment() const;
    void refund() const;
    void validateTransaction() const;
};

#endif // TRANSACTIONS_H
