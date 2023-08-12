#include<bits\stdc++.h>
using namespace std;

int main(){
    int a = 4;
    int b = 6;
    cout<<(a & b)<<endl;
    cout<<(a | b)<<endl;
    cout<<(~a)<<endl;
    cout<<(a^b)<<endl;
    int cnt = 0;
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    cout<<endl;
    for(int i = 2; i<n; i++){
        if(n % i == 0){
            cnt++;
            break;
        }
    }
    if(cnt == 0)
        cout<<"Number is prime"<<endl;
    else    
        cout<<"Number is not prime"<<endl;
return 0;
}