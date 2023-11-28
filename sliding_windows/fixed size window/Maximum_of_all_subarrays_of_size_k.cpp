// 9 8 7 6 5 4 3 2 1 0
// 9 8 6 6 5 4 3 2
// its not showing 7 here
// ERROR

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

vector<int> answer(int arr[], int n, int k){
    int i = 0;
    int j = 0;
    list < int > l;
    vector < int > vec;
    int maxi = INT_MIN;

    while(j  < n){

        // calculations 
        while(l.size() > 0 && l.back() < arr[j])
            l.pop_back();
        l.push_back(arr[j]);

        // window size not yet reached
        if(j - i + 1 < k){
            j++;
        }    
        else if (j - i + 1 == k){
            // print the answer || push_back() answer
            vec.push_back(l.front());

            // slide the window
            if(l.front() == arr[i])
                l.pop_front();
            i++;
            j++;
        }
    }
    return vec;
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
    vector< int > ans;
    ans = answer(arr,n,k);
    for(auto it : ans)
        cout << it << " ";
    return 0;
}