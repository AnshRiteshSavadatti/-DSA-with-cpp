#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    printf("Enter the number\n");
    cin>>a;
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++)
            cout<<'*'<<" ";
        cout<<endl;
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++)
            cout<<i+1<<" ";
        cout<<endl;
    }

    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            char ch = 'A' + i + j ;
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    return 0;
}