#include<bits\stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number in binary "<<endl;
    cin>>n;
    int m = n;
    int i = 0;
    int ans = 0;
    while(m != 0){
        int num = m % 10;
        ans = ans + num * (pow(2,i));
        i++;
        m /= 10;
    }
    cout << "The number which is in decimal system is "<<ans<<endl;
    return 0;
}