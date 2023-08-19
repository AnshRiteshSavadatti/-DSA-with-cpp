#include<bits\stdc++.h>
using namespace std;

void read_array(int arr[], int n){
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}
void print_array(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void sort(int arr[], int n){
    int i=0, j=n-1;
    while(i<j){
        if(arr[i] == 0)
            i++;
        if(arr[j] == 1)
            j--;
        if(arr[i] == 1 && arr[j] == 0){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        if(arr[i] == 1 && arr[j] == 1)
            swap(arr[i],arr[i+1]);
        else if(arr[i] == 0 && arr[j] == 0)
            swap(arr[j],arr[j-1]);
    }

}
int main(){
    int n;
    cout << "Enter the size of array "<<endl;
    cin>> n;
    int arr[100];
    read_array(arr,n);
    print_array(arr,n);
    sort(arr,n);
    print_array(arr,n);
    return 0;
}