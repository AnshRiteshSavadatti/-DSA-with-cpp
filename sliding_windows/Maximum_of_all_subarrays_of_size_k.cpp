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
        if(j - i + 1 < k){
            l.push_back(arr[j]);
            maxi = max(maxi, arr[j]);
            j++; 
        }
        else{
            vec.push_back(maxi);
            list < int > :: iterator it = find(l.begin(), l.end(), maxi);
            list < int > :: iterator  it1 = l.begin(); 
            while( it1 != it){
                l.pop_front();
                it1++;
            }
            if(arr[i] == maxi && arr[i] == l.front()){ 
                l.pop_front();
                maxi = l.front();
            }
            i++;
            j++;
            l.push_back(arr[j]); 
            if(arr[j] > maxi){
                l.clear();
                l.push_back(arr[j]);
            }
            maxi = max(maxi, arr[j]);
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