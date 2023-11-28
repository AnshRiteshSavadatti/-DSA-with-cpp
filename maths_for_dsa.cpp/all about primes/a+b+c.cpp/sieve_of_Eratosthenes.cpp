#include<bits/stdc++.h>
using namespace std;

int N = 100000;
vector<bool>arr(100001);

void MakeSieve(){
    for(int i=0; i <= N; i++){
        arr[i] = true;
    }

    for(int i=2; i*i <= N; i++){
        if(arr[i] == true){
            for(int j = i*i; j <= N; j += i){
                arr[j] = false;
            }
        }
    }
}

int main(){
    MakeSieve();
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    if(arr[n] == true)
        cout << "Yes " << n << " is a prime number " << endl;
    else
        cout << "No " << n << " is not a prime number" << endl;
    return 0;
}