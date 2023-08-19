#include<bits\stdc++.h>
using namespace std;

int binary_search(int arr[], int n){
    int s = 0;
    int e = n-1;
    int key;
    cout << "Enter the key "<< endl;
    cin >> key;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(key == arr[mid])
            return mid;
        if(key < arr[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int main(){
   int arr[8] { 0,2,4,5,6,7,8,9};
   int ans = binary_search(arr , 8 );
   cout << "The index of the key is " << ans << endl;
   return 0;
}