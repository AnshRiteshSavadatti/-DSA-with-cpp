#include<iostream>
#include<time.h>
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
    clock_t start,end;
   
    cout << "Enter the size of array " << endl;
    cin >> n;
    int* arr = new int[n];
    for(int i =0; i<n; i++){
        arr[i] = i;
    }
    // read_array(arr, n);
    int key = 0;
    // cout << "Enter the key which is to be searched " << endl;
    // cin >> key;
    start=clock();
    int ans = binary_search(arr, n, 0, n-1, key);
    end=clock();
    double duration=(end-start)/1000;
    cout << " The index of the element is " << ans << " " << endl;
    cout<<"time taken to execute is"<<duration<<endl;
    return 0;
}