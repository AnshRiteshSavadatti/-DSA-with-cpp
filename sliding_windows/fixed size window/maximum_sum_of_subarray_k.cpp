#include<iostream>
#include<set>
#include<bits\stdc++.h>
using namespace std;
void read_array(int arr[], int n){
    for(int i=0; i<n; i++)
        cin >> arr[i];
}

void print_array(int arr[] ,int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void sum(int arr[], int n, int k){
    int i = 0, j = 0;
    int sum = 0;
    int maxi = INT_MIN;
    while(j < n){
        sum += arr[j];
        if(j-i+1 < k)
            j++;
        else if (j-i+1 == k){
            maxi = max(maxi, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    cout << "The largest sum is " << maxi << endl; 
}

int main(){
    int n;
    int k;
    int arr[1000];
    cout << "Enter the size of array" << endl;
    cin >> n;
    cout << "Enter the size of subarray " << endl;
    cin >> k;
    cout << "Enter the array elements "<< endl;
    read_array(arr,n);
    print_array(arr,n);
    sum(arr,n,k);
    return 0;
}