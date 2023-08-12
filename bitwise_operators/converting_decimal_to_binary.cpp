#include<bits\stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the digit which is to be converted"<<endl;
    cin>>n;
    float num = 0;
    for(int i=0; n != 0; i++){
        int bit = (1&n);
        num =  (bit * pow(10,i)) + num;
        n =  n>>1;
    }
    cout<<num<<endl;
    return 0;
}