//     https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// ACCEPTED
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool solve(vector<int>& arr, int sum, int temp, int index, int n, vector<vector<int>>& t) {
        if (sum == temp) return true;
        if (index == n || temp > sum) return false;
        
        if (t[index][temp] != -1) return t[index][temp];
        
        bool include = solve(arr, sum, temp + arr[index], index + 1, n, t);
        
        bool exclude = solve(arr, sum, temp, index + 1, n, t);
        
        t[index][temp] = include || exclude;
        return t[index][temp];
    }
public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        
        vector<vector<int>> t(n + 1, vector<int>(sum + 1, -1));
        
        return solve(arr, sum, 0, 0, n, t);
    }
};
