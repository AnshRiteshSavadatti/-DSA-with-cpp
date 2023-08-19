#include<bits\stdc++.h>
using namespace std;

int fac(int a){
    int fac = 1;
    for(int i=1; i<=a; i++)
        fac *= i;
    return fac;
}

int nCr(int n, int r){
   int m = fac(n);
   int q = fac(r);
   int s = fac(n-r);
   cout<< m/(q*s)<<endl;
   return 0;
}

int main(){
    int n , r;
    cout<< "Enter the value of n and r "<< endl;
    cin>>n>>r;
    nCr(n,r);
    return 0;
}