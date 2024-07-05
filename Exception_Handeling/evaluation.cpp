#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

class Loan {
    public :
        unsigned loanId;
        unsigned loanAmt;
        double intRate;
        int rPeriod;
};

class FourWheelerLoan : public Loan{
    public:

    FourWheelerLoan(unsigned loanId, unsigned loanAmt, double intRate, int rPeriod){
        this->intRate = intRate;
        this->loanId = loanId;
        this->rPeriod = rPeriod;
        this->loanAmt = loanAmt;
    }
    
        void checkLimit(int n){
            try{
                if(n <= 1){
                    throw 0;
                }else if(n < 100000){
                    throw 'a';
                }else{
                    cout << "Loan Approved" << endl;
                }
            }
            catch(int a){
                cout << "The loan amount cant be less than or equal to  1" << endl;
                return;
            }
            catch(char ch){
                cout << "The loan amount limit is 1,00,000" << endl;
                return;
            }
        }
    
};

class TwoWheelerLoan : public Loan{
    public:

    TwoWheelerLoan(unsigned loanId, unsigned loanAmt, double intRate, int rPeriod){
        this->intRate = intRate;
        this->loanId = loanId;
        this->rPeriod = rPeriod;
        this->loanAmt = loanAmt;
    }
    
        void checkLimit(int n){
            try{
                if(n <= 1){
                    throw 0;
                }else if(n < 10000){
                    throw 'a';
                }else{
                    cout << "Loan Approved" << endl;
                }
            }
            catch(int a){
                cout << "The loan amount cant be less than or equal to 1" << endl;
                exit(0);
            }
            catch(char ch){
                cout << "The loan amount limit is 10,000" << endl;
                exit(0);
            }
        }
    
};

class Customers{
    public:
        string name;
        unsigned int custid;
        FourWheelerLoan* ptr1;
        TwoWheelerLoan* ptr2;

        Customers(string name, unsigned int custid, FourWheelerLoan* ptr1, TwoWheelerLoan* ptr2){
            this->name = name;
            this->custid = custid;
            this->ptr1 = ptr1;
            this->ptr2 = ptr2;
            if(ptr1 == nullptr && ptr2 == nullptr){
                cout << "This customer has taken no loan" << endl;
            }
        }

        void calculateEmi(double intrest, FourWheelerLoan* ptr1, TwoWheelerLoan* ptr2){
            try{
                if(intrest <= 0){
                    throw 'a';
                }else{
                    if(ptr1 != nullptr)
                        cout << "The EMI with 6 percent intrest rate is " <<  0.06 * ptr1->loanAmt + ptr1->loanAmt << endl; 
                    else{
                        cout << "The EMI with 6 percent intrest rate is " <<  0.06 * ptr2->loanAmt + ptr2->loanAmt << endl; 
                    }
                }
            }
            catch(char ch){
                cerr << "Intrest cannot be negative" << endl;
                exit(0);
            }
        }

        void print(){
            cout << endl;
            cout << "The customers details are" << endl;
            cout << this->name << endl;
            cout << this->custid << endl;
            if(this->ptr1 != nullptr){
                cout << endl;
                cout << "FourWheelr loan is" << endl;
                cout << this->ptr1->intRate << endl;
                cout << this->ptr1->loanAmt << endl;
                cout << this->ptr1->loanId << endl;
                cout << this->ptr1->rPeriod << endl;
            }
            if(this->ptr2 != nullptr){
                cout << endl;
                cout << "Two Wheeler loan is" << endl;
                cout << this->ptr2->intRate << endl;
                cout << this->ptr2->loanAmt << endl;
                cout << this->ptr2->loanId << endl;
                cout << this->ptr2->rPeriod << endl;
            }
            cout << endl;
        }
};


int main(){
    FourWheelerLoan l1(100, 100000, 5.6, 12);
    TwoWheelerLoan l2(100, 10000, 7, 7);

    Customers c1 ("Ansh", 1234, &l1, &l2);
    c1.ptr1->checkLimit(c1.ptr1->loanAmt);
    c1.ptr2->checkLimit(c1.ptr1->loanAmt);
    c1.calculateEmi(c1.ptr1->intRate, &l1, nullptr);
    c1.calculateEmi(c1.ptr2->intRate, nullptr, &l2);

    c1.print();

    Customers c3 ("ars", 4321, nullptr, nullptr);

    FourWheelerLoan l3(100, 100000, -5.6, 7);
    Customers c2 ("ars", 4321, &l3, nullptr);

    c2.ptr1->checkLimit(c2.ptr1->loanAmt);
    c2.ptr2->checkLimit(c2.ptr1->loanAmt);
    c2.calculateEmi(c2.ptr1->intRate, &l3, nullptr);
    c2.print();

    

    return 0;
}