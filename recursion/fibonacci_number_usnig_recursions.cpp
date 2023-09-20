#include<iostream>
using namespace std;

int fibonacci(int n,int a, int b){
    if(n == 0)
        return b;
    int temp = fibonacci(n-1,b,a+b);
    return temp;
}

int main(){
    int n;
    cout << "Enter the position upto which we need fibonacci number " << endl;
    cin >> n;
    if(n ==1 ){
        cout << 0;
        return 0;
    }
    else if ( n ==2){
        cout << 1 ;
        return 0;
    }
    int ans = fibonacci(n-2,0,1);
    cout << "The number at " << n << " position is " << ans << endl;
    return 0;
}