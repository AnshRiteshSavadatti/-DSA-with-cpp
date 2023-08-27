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

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int index = i;
        for(int j =i; j<n; j++){
            if(arr[index] > arr[j])
                index = j;
        }
        swap(arr[i], arr[index]);
        cout<<arr[i]<< " ";
    }
    cout << endl;
}
int main(){
    int n;
    cout << "Enter the size of Array" << endl;
    cin>>n;
    int arr[1000];
    readArray(arr,n);
    displayArray(arr,n);
    selectionSort(arr,n);
    displayArray(arr,n);
    return 0;


}