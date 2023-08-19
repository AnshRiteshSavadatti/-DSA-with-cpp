#include<bits\stdc++.h>
using namespace std;

void read_array(int arr[] , int size){
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    return;
}

void print_array(int arr[], int n){
    for(int i = 0; i< n; i++)
        cout << arr[i] << " ";
    return;
}

void reverse_array(int arr[], int n){
    for(int i = 0; i < n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    return;
}
int main(){
    int arr[10];
    int n;
    cout << "Enter the number of array elaments " << endl;
    cin >> n;
    cout << "Enter the arrray elements " << endl;
    read_array(arr, n);
    print_array(arr, n);
    cout << endl;
    reverse_array(arr, n);
    cout << endl;
    print_array(arr, n);
    return 0;
}