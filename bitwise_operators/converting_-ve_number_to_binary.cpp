#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the negative number which is to be converted to binary"<<endl;
    cin>>n;
    float ans = 0;
    for(int i = 0; n != 0; i++){
        int bit = n & 1;
        ans = ans + bit * (pow(10,i));
        n = n >> 1;
    }
    int a = ans;
    cout<<"The positve answer in bits is "<<ans<<endl;
    cout<<endl;
    long long int sum = 0;
    for(int i=0; i<32; i++){
        int bit = a & 1;
        if(bit){
            sum = sum + 0;
        }
        else{
            sum = sum + 1 * pow(10,i);
        }
        a = a >> 1;
    }
    cout<<sum<<endl;
    return 0;
}