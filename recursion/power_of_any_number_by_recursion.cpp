#include<iostream>
using namespace std;


int power(int n, int p){
    if(p == 0)
        return 1;
    int temp = power(n,p-1);
    return n * temp;
}

int main(){
    int n;
    cout << "Enter the value of number"<< endl;
    cin >> n;
    int p; 
    cout << "Enter the value of power " << endl;
    cin >> p;
    int ans = power(n,p);
    cout << "The answer is " << ans << endl;
    return 0;
}