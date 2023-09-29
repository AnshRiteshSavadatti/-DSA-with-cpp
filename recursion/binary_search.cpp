#include<iostream>
using namespace std;


void read_array(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << " Enter the " << i << " element" << endl;
        cin >> i[arr];
    }
}

int binary_search(int arr[], int n, int s, int e, int k){
    int ans = -1;
    int mid = s + (e -s) /2;
    if(s > e) // base case 
        return -1;  
    if(arr[mid] == k)  // base case
        return mid;
    else if(arr[mid] < k)
        ans = binary_search(arr, n, mid+1, e, k);
    else
        ans = binary_search(arr, n, s, mid-1, k);
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of array " << endl;
    cin >> n;
    int* arr = new int[n];
    read_array(arr, n);
    int key;
    cout << "Enter the key which is to be searched " << endl;
    cin >> key;
    int ans = binary_search(arr, n, 0, n-1, key);
    cout << " The index of the element is " << ans << " " << endl;
    return 0;
}