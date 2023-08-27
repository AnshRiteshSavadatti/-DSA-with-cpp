#include<bits\stdc++.h>
using namespace std;

void readArray(int arr[], int n){
    for(int i =0; i<n; i++)
        cin >> arr[i];
}

void displayArray(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n){
    int j;
    for(int i=1; i<n; i++){
        int temp = arr[i];
        for(j=i-1; j>=0 ; j--){
            if(arr[j] > temp)
                arr[j+1] = arr[j];
            else    
                break;
        }
        arr[j+1] = temp;
    }
}
int main(){
int n;
    cout << "Enter the size of Array" << endl;
    cin>>n;
    int arr[1000];
    readArray(arr,n);
    displayArray(arr,n);
    insertionSort(arr,n);
    displayArray(arr,n);
    return 0;
}