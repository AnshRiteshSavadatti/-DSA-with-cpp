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
  
 void neg_number(int arr[], int n, int k){ 
    int i = 0, j = 0; 
    list<int>l;
    while(j < n){ 
    if(arr[j] < 0)
        l.push_back(arr[j]);
        if(j - i + 1 < k){
            j++;
        }
        else if(j - i + 1 == k){
            if(l.empty()){
                cout << 0 << " ";
            }
            else{
                cout << l.front() << " ";
                if(arr[i] == l.front()){
                    l.pop_front();
                }
            }
        i++;
        j++;
        }
    }
    return;
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
     neg_number(arr,n,k);    
     return 0; 
 }