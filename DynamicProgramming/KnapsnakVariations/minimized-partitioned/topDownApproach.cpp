
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
void subsetSum(vector<int>& nums, int sum, vector<int>& index){
    int n = nums.size();
    vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));

    for(int i =0; i <= sum; i++){
        t[0][i] = false;
    } 

    for(int i =0; i <= n; i++){
        t[i][0] = true;
    } 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(nums[i-1] <= j){
                t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    for(int i = 0; i <= sum/2; i++){
        if(t[n][i]){
            index.push_back(i);
        }
    }
    return;
}
public:
    int minimumDifference(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums) sum += it;

        vector<int> numbers;
        subsetSum(nums, sum, numbers);

        int mini = INT_MAX;
        for(int i =0; i < numbers.size(); i++){
            mini = min(mini, sum - 2 * numbers[i]);
        }
        return mini;
    }
};