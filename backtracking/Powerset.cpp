// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void solve(vector<int>& nums, int index, vector<int>& output, vector<vector<int>>& ans){
            if(index == nums.size()){
                ans.push_back(output);
                return;
            }
    
            output.push_back(nums[index]);
            solve(nums, index+1, output, ans);
    
            output.pop_back();
            solve(nums, index+1, output, ans);
        }
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            int index = 0;
            vector<int> output;
    
            solve(nums, index, output, ans);
    
            return ans;
        }
    };