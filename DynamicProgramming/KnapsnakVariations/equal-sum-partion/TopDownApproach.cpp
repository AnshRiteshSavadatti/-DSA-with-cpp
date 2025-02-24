// https://leetcode.com/problems/partition-equal-subset-sum/submissions/1344784545/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSubsetSum(vector<int>& arr, int sum){
        int n = arr.size(); // wt;
        // sum;
        
        vector<vector<bool>> t (n+1, vector<bool>(sum+1, false));
        
        // initialization
        for(int i =0; i< sum+1; i++) t[0][i] = false;
        for(int i =0; i < n+1; i++) t[i][0] = true;
        
        // kp
        for(int i =1; i<n+1; i++){
            for(int j =1; j < sum+1; j++){
                if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i =0; i < nums.size(); i ++){
            sum += nums[i];
        }
        if(sum & 1) return false;

        return isSubsetSum(nums, sum / 2);
    }
};