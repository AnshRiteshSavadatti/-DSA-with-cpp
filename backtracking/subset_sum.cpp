#include<iostream>
#include<vector>
using namespace std;

void solve(int n, int k, vector<int>arr, vector<int>&output, int sum, int i, vector<vector<int>> &ans){
    if(n <= i) return;
    else if(sum == k){
        ans.push_back(output);
        return;
    }
    else{
        output.push_back(arr[i]);
        solve(n, k, arr, output, sum + arr[i], i+1, ans);
        output.pop_back();
        solve(n, k, arr, output, sum, i+1, ans);
    }
    return;
}

int main(){
    cout << "Enter the number of elements in set" << endl;
    int n;
    cin >> n;
    vector<int>arr;
    int k;
    cout <<"Enter the sum which is to be found " << endl;
    cin >> k;
    cout << "Is the number of input set of natural numbers in a continious fashion ? if yes press 1 else 0" << endl;
    int t;
    cin >> t;
    if(t){
        for(int i=0; i<n; i++)
            arr.push_back(i+1);
    }
    else{
        cout << "Enter the elements of vector" << endl;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            arr.push_back(x);
            }
    }
    vector<vector<int>>ans;
    vector<int>o;
    solve(n, k, arr, o, 0, 0, ans);
    if(ans.empty()){
        cout << "There are not such subsets in given set to make sum " << k << endl;
    }
    else{
        cout << "The combinations are " << endl;
        for(auto it: ans){
            for(auto i : it){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}