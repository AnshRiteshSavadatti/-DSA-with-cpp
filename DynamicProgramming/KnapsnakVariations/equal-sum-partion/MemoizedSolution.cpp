// https://leetcode.com/problems/partition-equal-subset-sum/submissions/1344784545/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSubsetSum(vector<int>& arr, int sum, int temp, int index, int n, vector<vector<int>>& t) {
        if (sum == temp) return true;
        if (index == n || temp > sum) return false;
        
        if (t[index][temp] != -1) return t[index][temp];
        
        bool include = isSubsetSum(arr, sum, temp + arr[index], index + 1, n, t);
        
        bool exclude = isSubsetSum(arr, sum, temp, index + 1, n, t);
        
        t[index][temp] = include || exclude;
        return t[index][temp];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i =0; i < nums.size(); i ++){
            sum += nums[i];
        }
        if(sum & 1) return false;

        vector<vector<int>> t(n + 1, vector<int>(sum + 1, -1));

        return isSubsetSum(nums, sum/2, 0, 0, nums.size(), t);
    }
};