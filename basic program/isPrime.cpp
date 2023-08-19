#include<bits\stdc++.h>
using namespace std;

void isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            cout << "The number is not Prime"<<endl;
            return;
        }
    }
    cout<<"The number is prime"<<endl;
    return;
}

int main(){
    int num;
    cout << " Enter the number " <<endl;
    cin>>num;
    isPrime(num);
    return 0;
}