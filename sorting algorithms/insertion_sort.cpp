#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int n){
    for(int i=1; i<=n-1; i++){
        int j = i-1;
        int v = arr[i];
        while(j >=0 && arr[j] > v){
            arr[j+1] = arr[j];
            j--;
        }
    swap(arr[j+1],v);
    }
}

void generate_array(int arr[], int n){
    srand(time(NULL));
    for(int i=0; i<n; i++)
        arr[i] = rand();
    return;
}

void print_array(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[100];
    generate_array(arr,100);
    sort(arr,100);
    print_array(arr,100);
    return 0;
}