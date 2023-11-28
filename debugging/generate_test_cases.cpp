// wap a function to find the largest number in array
#include<bits/stdc++.h>
using namespace std;

// int find(int arr[], int n){
//     sort(arr, arr+n);
//     return arr[n-2];
// }

// int true(int arr[], int n){
//     int maxi = 0;
//     for(int i=0; i<n; i++){
//         maxi = max(maxi, arr[i]);
//     }
//     int s = 0;
//     for
// }

int main(){
    srand(time(NULL));
    int t = rand() % 2 + 1;
    cout << t << endl;
    while(t--){
        int n = rand() % 6 + 1;
        cout << n << endl;
        for(int j=0; j<n; j++)
            cout << rand() % 7 + 1 << " ";
        cout << endl;
    }
    return 0;
}