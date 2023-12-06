#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int n){
    for(int i=0; i<=n-2; i++){
        for(int j=0; j <= n-2-i; j++){
            if(arr[j+1] < arr[j]){
                swap(arr[j],arr[j+1]);
            }
        }
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