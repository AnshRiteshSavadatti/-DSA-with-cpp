// In this case 1 is the pivoting element we cans conside 9 as well as pivoting element
#include<bits\stdc++.h>
using namespace std;

int pivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    while(s < e){
        int mid = s + (e-s)/2;
        if(arr[mid] > arr[0])
            s = mid + 1;
        else
            e = mid ;
    }
    return s;
}

int main(){
    int arr[7] = {7,8,0,1,2,3,4};
    int ans = pivot(arr,7);
    cout << "The Index of pivoting element is "<< ans << endl;
    return 0;
}