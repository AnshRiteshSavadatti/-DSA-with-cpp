#include <iostream>
#include <vector>
#include <ctime>
#include <stdexcept>

using namespace std;

class MyExcept : public exception{
    private:
        string msg;
    public:

        MyExcept(string s){
            this->msg = s;
        }

        void displayError(){
            cout << "The error is" << endl;
            cout << this->msg << endl;
        }
};

class ItemsPurchased{
    public:
        string ItemID;
        string ItemName;
        float ItemPrice;
        float Discount;

        ItemsPurchased(string ItemID, string ItemName, float ItemPrice, float Discount){
            this->ItemID = ItemID;
            this->ItemName = ItemName;
            this->ItemPrice = ItemPrice;
            this->Discount = Discount;

            cout << "Item purchased is " << this->ItemName << endl;
        }
};

class customer{
    public:
        string name;
        string custid;
        vector<ItemsPurchased*> ip;
        bool isPrivilaged;
        
};

class PrivilagedCustomer : public customer{
    public:
        PrivilagedCustomer(string name, string custid){
            this->name = name;
            this->custid = custid;

            int ch;
            ItemsPurchased* i;
            do{
                cout << "Enter 1 to purchase BabyProducts" << endl;
                cout << "Enter 2 to purchase BathroomProducts" << endl;
                cout << "Enter 3 to purchase KitchenProducts" << endl;
                cout << "Enter 4 to purchase ElectronicsProducts" << endl;
                cout << "Enter 5 to purchase DecorativeProducts" << endl;
                cin >> ch;

                switch(ch){
                    case 1:
                        i = new ItemsPurchased( "D1001", "BabyProducts", rand() % 1001, 0.05);
                        ip.push_back(i);
                        break;
                    case 2:
                        i = new ItemsPurchased( "D1002", "BathroomProducts", rand() % 501, 0.03);
                        ip.push_back(i);
                        break;
                    case 3:
                        i = new ItemsPurchased( "D1003", "KitchenProducts", rand() % 1001, 0.03);
                        ip.push_back(i);
                        break;
                    case 4:
                        i = new ItemsPurchased( "D1004", "ElectronicsProducts", rand() % 10001, 0.15);
                        ip.push_back(i);
                        break;
                    case 5:
                        i = new ItemsPurchased( "D1005", "DecorativeProducts", rand() % 5001, 0.10);
                        ip.push_back(i);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Please enter valid number" << endl;
                        break;
                }
            }while(ch);
        }

};

class RegularCustomer : public customer{
    public:
        RegularCustomer(string name, string custid){
            this->name = name;
            this->custid = custid;

            int ch;
            ItemsPurchased* i;
            do{
                cout << "Enter 1 to purchase BabyProducts" << endl;
                cout << "Enter 2 to purchase BathroomProducts" << endl;
                cout << "Enter 3 to purchase KitchenProducts" << endl;
                cout << "Enter 4 to purchase ElectronicsProducts" << endl;
                cout << "Enter 5 to purchase DecorativeProducts" << endl;
                cin >> ch;

                switch(ch){
                    case 1:
                        i = new ItemsPurchased( "D1001", "BabyProducts", rand() % 1001, 0);
                        ip.push_back(i);
                        break;
                    case 2:
                        i = new ItemsPurchased( "D1002", "BathroomProducts", rand() % 501, 0);
                        ip.push_back(i);
                        break;
                    case 3:
                        i = new ItemsPurchased( "D1003", "KitchenProducts", rand() % 1001, 0);
                        ip.push_back(i);
                        break;
                    case 4:
                        i = new ItemsPurchased( "D1004", "ElectronicsProducts", rand() % 10001, 0);
                        ip.push_back(i);
                        break;
                    case 5:
                        i = new ItemsPurchased( "D1005", "DecorativeProducts", rand() % 5001, 0);
                        ip.push_back(i);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Please enter valid number" << endl;
                        break;
                }
            }while(ch);
        }

};

class BigBazar{
    public:
        string location;
        vector<RegularCustomer*> r;
        vector<PrivilagedCustomer*> p;

        BigBazar(string location){
            this->location = location;

            int n;
            cout << "Enter the number of privilaged customer" << endl;
            cin >> n;

            for(int i=0; i<n; i++){
                string s, custid;
                cout << "Enter the Name and custid" << endl;
                cin >> s >> custid;
                PrivilagedCustomer* pp = new PrivilagedCustomer(s, custid);
                p.push_back(pp);
            }

            cout << "Enter the number of Regular Customer" << endl;
            cin >> n;

            for(int i=0; i<n; i++){
                string s, custid;
                cout << "Enter the Name and custid" << endl;
                cin >> s >> custid;
                RegularCustomer* pp = new RegularCustomer(s, custid);
                r.push_back(pp);
            }
        }


        void CalculateBill(){
            
            cout << "Bill for Privilaged customer is" << endl;
            for(auto it : this->p){
                float bill = 0;
                for(auto jt : it->ip)
                    bill += jt->ItemPrice - jt->Discount;
                cout << "The bill with discount is " << bill << endl;
            }

            cout << "Bill for Regular Customer is" << endl;

            for(auto it : this->r){
                float bill = 0;
                for(auto jt : it->ip)
                    bill += jt->ItemPrice;

                if(bill > 1000 && bill < 3000){
                    bill -= bill * 0.05;
                }else if(bill >= 3001 && bill <= 5000){
                    bill -= bill * 0.10;
                }else if(bill >= 5001 && bill <= 10000){
                    bill -= bill * 0.15;
                }else if(bill >= 10001){
                    bill -= bill * 0.20;
                }
                cout << "The bill with discount is " << bill << endl;
            }
        }
};

int main(){
    BigBazar b("Hubli");
    b.CalculateBill();
    return 0;
}