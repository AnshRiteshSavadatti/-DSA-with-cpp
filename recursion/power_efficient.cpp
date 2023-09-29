#include<iostream>
// #include<math.h>
using namespace std;

int power(int n, int p){
    int temp;
    if(p == 0)
        return 1;
    if(p == 1)
        return n;
    int ans = power(n, p/2);
    if(p & 1){
        temp = n * ans * ans;
        cout << temp << endl;
        return temp;
    }
    else{
        temp = ans * ans;
        cout << temp << endl;
        return temp;
    }
}

int main(){
    int p, n;
    cout << "Enter the number " << endl;
    cin >> n;
    cout << "Enter the power" << endl;
    cin >> p;
    int ans = power(n,p);
    cout << "The power of " << n << " raise to " << p << " is " << ans << endl;
    return 0;
}