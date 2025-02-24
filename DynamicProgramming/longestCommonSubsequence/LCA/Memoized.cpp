// https://leetcode.com/problems/longest-common-subsequence/submissions/1348563768/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
int solve(string & x, string & y, int n, int m, vector<vector<int>> &t){
    if(m == 0 || n == 0){
        return 0;
    }
    
    if(t[n][m] != -1) return t[n][m];

    if(x[n-1] == y[m-1]){
        return t[n][m] = 1 + solve(x,y,n-1, m-1, t);
    }
    return  t[n][m] = max(solve(x,y,n, m-1, t), solve(x,y,n-1, m, t));
}
public:
    int longestCommonSubsequence(string x, string y) {
        vector<vector<int>> t(x.size()+1, vector<int> (y.size()+1, -1));

        return solve(x, y, x.size(), y.size(), t);

    }
};