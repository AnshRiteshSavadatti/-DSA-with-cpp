// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// ACCEPTED SOLUTION
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));

        // Initialization
        for (int i = 0; i <= sum; i++) t[0][i] = false;
        for (int i = 0; i <= n; i++) t[i][0] = true;

        // DP table population
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    bool result = sol.isSubsetSum(arr, sum);
    return result ? 0 : 1; // Return 0 if true, 1 if false
}
