// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//  NOT ACCEPTED

#include <bits/stdc++.h>
using namespace std;

class Solution{   
private:
    bool solve(vector<int> arr, int &sum, int temp){
        if(sum == temp) return true;
        if(arr.size() == 0) return false;
        
        int t = arr[0];
        arr.erase(arr.begin() + 0);
        
        return solve(arr, sum, temp +t) || solve(arr, sum, temp);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        return solve(arr, sum, 0);
    }
};