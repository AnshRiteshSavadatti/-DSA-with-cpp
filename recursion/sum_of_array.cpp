#include<iostream>
using namespace std;

void read_array(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << " Enter the " << i << " element" << endl;
        cin >> i[arr];
    }
    return;
}

int sum(int arr[], int n){
    int s = 0;
    if(n == 0)
        return s;
    else{
        s = sum(arr+1, n-1);
        s += arr[0];
    }
    return s;
}

int main(){
    int n ;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int* arr = new int[n];
    read_array(arr,n);
    int ans = sum(arr,n);
    cout << "The sum is " << ans << endl;
    return 0;
}