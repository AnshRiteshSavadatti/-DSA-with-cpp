/*
    In this program we cant throw a string, We must write our own exception handler
    If you give the value of b less than 0 the program will throw error
    terminate called after throwing an instance of 'char const*'
*/

#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    float d;

    try{
        if(b == 0){
            throw 10;
        }else if(b== 1){
            throw 'c';
        }else if(b < 0){
            throw "Yo";
        }

    }
    catch(int a){
        cout << "Cannot divide by zero :C" << endl;
        exit(0);
    }
    catch(char ch){
        cout << "Divided by one, ha !! :)" << endl;
        cout << a << endl;
        exit(0);
    }
    catch(string s){
        cout << "Dekh bhai less than 0 mat dal" << endl;
        exit(0);
    }

    d = a / b;
    cout << d << endl;

    return 0;
}