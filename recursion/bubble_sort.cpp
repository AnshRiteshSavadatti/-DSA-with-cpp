#include<iostream>
using namespace std;

void read_array(int arr[], int n){
    for(int i =0; i<n; i++){
        cout << "Enter the element at " << i << " index "<< endl;
        cin >> arr[i];
    }
}

void print_array(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << i[arr] << " ";
    return;
}

void sort(int arr[], int n){
    if( n == 0 || n == 1)
        return;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1])
            swap(arr[i] , arr[i+1]);
    }
    sort(arr, --n);
    return;
}

int main(){
    int n;
    cout << "Enter the size of Array" << endl;
    cin >> n;
    int* arr = new int[n];
    read_array(arr,n);
    sort(arr, n);
    print_array(arr, n);
    return 0;
}