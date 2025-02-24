// https://leetcode.com/problems/partition-equal-subset-sum/submissions/1344784545/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool solve(vector<int> & nums, int index, int temp1, int temp2){
        if(nums.size() == index && temp1 == temp2) return true;
        if(nums.size() == index) return false;

        bool include = solve(nums, index + 1, temp1 + nums[index], temp2);
        bool exclude = solve(nums, index + 1, temp1, temp2 + nums[index]);

        return include || exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        return solve(nums, 0, 0, 0);
    }
};