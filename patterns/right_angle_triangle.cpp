#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(int i =0; i<n; i++){
        for(int j=0; j<=i; j++)
            cout<<"* ";
        cout<<endl;
    }
    int i = 0;
    while(i<n){
        int j = 0;
        while(j<=i){
            cout<<i+1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    int cnt = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<cnt<<" ";
            cnt++;
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++)
            cout<<i+1+j<<" ";
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++)
            cout<<i-j+1<<" ";
        cout<<endl;
    }
    char a = 'A';
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            char ch = a+i;
            cout<<ch<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            char ch = 'A' + n -i + j - 1;
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    return 0;
}