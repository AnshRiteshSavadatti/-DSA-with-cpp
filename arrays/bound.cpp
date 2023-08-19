#include<bits\stdc++.h>
using namespace std;

int firstOccurrance(int arr[], int n, int key){
    int s = 0, e = n-1;
    int ans = -1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(key == arr[mid]){
            ans = mid;
            e = mid -1;
        }
        else if(key < arr[mid]){
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}

int lastOccurrance(int arr[], int n, int key){
    int s = 0, e = n-1;
    int ans = -1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(key == arr[mid]){
            ans = mid;
            s = mid + 1;
        }
        else if(key < arr[mid]){
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
    int arr[6] = { 1,3,3,3,6,8};
    cout << "The first occurance of 3 is at index " << firstOccurrance(arr,6,3) << endl;
    cout << "The last occurance of 3 is at index " << lastOccurrance(arr,6,3) << endl;
    return 0;
}