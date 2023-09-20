#include<bits/stdc++.h>
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

int size_of_window(int arr[], int n, int k){
    int m = INT_MIN;
    int sum = 0, i = 0, j = 0;
    while (j < n)
    {
        sum += arr[j++];
        if (sum == k){
            m = max(m, j - i + 1);
            j++;
            if (j < n) sum += arr[j];
        }
        else{
            while(sum > k){
                sum -= arr[i];
                i++;
            }
        }
    }
    return (m == INT_MIN) ? -1 : m;
    
}

int main(){
    int arr[1000];
    int n;
    cout << "Enter the size of array " << endl;
    cin >> n;
    cout << "Enter the sum which is to be found " << endl;
    int k;
    cin >> k;
    read_array(arr, n);
    print_array(arr, n);
    cout << "The size of largest window with size k is --> " << size_of_window(arr, n, k);
    return 0;
}