#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int n){
    for(int i=0; i<=(n-1)/2; i++){
        int mini = i;
        int maxi = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[mini]){
                mini = j; 
            }else if(arr[j] > arr[maxi]){
                maxi = j;
            }
        }
        swap(arr[mini], arr[i]);
        if (maxi == i) {
            maxi = mini;
        }
        swap(arr[maxi], arr[n-i-1]);
    }
    return;
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