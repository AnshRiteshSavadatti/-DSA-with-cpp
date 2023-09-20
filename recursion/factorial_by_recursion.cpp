#include<iostream>
using namespace std;

int fact(int n){
    // base case
    if(n ==0)
        return 1;
    // recursive relation
    int temp = fact(n-1);
    return n * temp;
}

int main(){
    int n;
    cout << "Enter the value of n " << endl;
    cin >> n;
    int ans = fact(n);
    cout << "The answer is " << ans << endl;
    return 0;
}