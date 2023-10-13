#include<iostream>
using namespace std;

int main(){
    int r = 3 ; int col = 4;
    int c = col/2;
    for(int i=0; i<col; i++){
        for(int j =0; j<i; j++)
            cout << " ";
        for(int j=0; j<c-i+1; j++)
            cout << "*";
        for(int j=0; j<c-i+1; j++)
            cout << "*";
        cout << endl;
    }
    for (int i=0; i<col; i++){
        for(int j=0; j<c-i+1; j++){
            cout << " ";
        }
        for(int j=0;j<=i; j++){
            cout << "*";
        }
        for(int j=0; j<i; j++)
            cout << "*";
                cout << endl;
        }
}