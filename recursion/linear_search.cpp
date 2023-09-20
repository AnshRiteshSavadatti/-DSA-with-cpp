#include<iostream>
using namespace std;

int search(int arr[], int n, int s){
    // base condition
    if(s == 0)
        return 0;
    if(arr[0] == n)
        return 1;
    int ans = search(arr+1, n, s-1);
    return ans;
}

int main(){
    int n;
    cout << "Enter the element which is to be searched " << endl;
    cin >> n;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int s = 10;
    int ans = search(arr,n,s);
    if(ans)
        cout << "Found " << endl;
    else
        cout << "Not found" << endl;
    return 0;
}