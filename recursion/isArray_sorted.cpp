#include<iostream>
using namespace std;

void read_array(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << " Enter the " << i << " element" << endl;
        cin >> i[arr];
    }
}

bool isSorted(int arr[], int n){
    int ans;
    if(n == 0 || n == 1)
        return true;
    else if(arr[0] > arr[1])
        return false;
    else
        ans = isSorted(arr + 1, n-1);
    return ans;
}
int main(){
    int n;
    cout << "Enter the value of array size " <<endl;
    cin >> n;
    int *arr = new int[n];
    read_array(arr, n);
    bool ans = isSorted(arr,n);
    cout << ans << endl;
    return 0;
}