#include<bits\stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter a number " << endl;
    cin >> n;
    int i = 0;
    while( n != 0){
        if(n & 1)
            i++;
        n = n >> 1;
    }
    if(i == 1)
        cout << "'Number is power of 2 " << endl;
    else 
        cout << "Number is not power of 2" << endl;
    return 0;
}